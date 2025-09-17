import socket
import boto3
import datetime
import os
import subprocess
import threading
import base64
import re
import struct
from cryptography.hazmat.primitives import serialization, hashes
from cryptography.hazmat.primitives.asymmetric import padding

# AWS S3 Configuration
BUCKET_NAME = 'final-output2-demo'
REGION_NAME = 'eu-north-1'  # e.g., 'us-east-1'
s3_client = boto3.client('s3', region_name=REGION_NAME)

# Load RSA private key
with open("private.pem", "rb") as key_file:
    private_key = serialization.load_pem_private_key(key_file.read(), password=None)

EXPECTED_HELLO = b"HELLO_MCU"
RSA_ENCRYPTED_LEN = 256
FILENAME_LEN = 8

from cryptography.hazmat.primitives.asymmetric import padding

def rsa_decrypt(data: bytes) -> bytes:
    return private_key.decrypt(
        data,
        padding.PKCS1v15()   # <- changed from OAEP to PKCS#1 v1.5
    )

def sanitize_filename(filename: str) -> str:
    # Remove any special characters from the filename
    return re.sub(r'[^a-zA-Z0-9_.-]', '_', filename)

def upload_to_s3(filename : str ,data: bytes):
    # Generate unique filename
    filename = sanitize_filename(filename)
    puck_id=filename
    timestamp = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%d-%H%M%S")
    print({type(puck_id)})
    filename = "{}_{}.enc".format(puck_id, timestamp)
    print(f"{filename}")
    # Upload to S3
    s3_client.put_object(Bucket=BUCKET_NAME, Key=filename, Body=data)
    print(f"[+] Uploaded file {filename} to bucket {BUCKET_NAME}")

def handle_client(conn, addr):
    try:
        print(f"[+] Connection from {addr}")

        # === Step 1: RSA handshake ===
        encrypted_hello = conn.recv(RSA_ENCRYPTED_LEN)
        print(f"Received encrypted hello length: {len(encrypted_hello)}")
        if len(encrypted_hello) != RSA_ENCRYPTED_LEN:
            print(f"[-] {addr}: Invalid handshake size")
            conn.sendall(b"AUTH_FAIL")
            return
        hello_msg = rsa_decrypt(encrypted_hello)
        print(f"Decrypted hello :{hello_msg}")
        if hello_msg != EXPECTED_HELLO:
            print(f"[-] {addr}: Handshake failed")
            conn.sendall(b"AUTH_FAIL")
            return
        conn.sendall(b"AUTH_OK")
        print(f"[+] {addr}: Handshake successful")

        # === Step 2: Filename ===
        filename_bytes = conn.recv(FILENAME_LEN)
        if len(filename_bytes) != FILENAME_LEN:
            print(f"[-] {addr}: Invalid filename size")
            return
        filename = filename_bytes.decode()
        print(f"[+] {addr}: Receiving file {filename}")
        filename = filename
        # === Step 3: Data length (4 bytes) ===
        length_bytes = conn.recv(4)
        if len(length_bytes) != 4:
            print(f"[-] {addr}: Invalid length field")
            return
        data_length = struct.unpack("!I", length_bytes)[0]
        print(f"[+] {addr}: Expecting {data_length} bytes of data")

        # === Step 4: Receive data ===
        data = b''
        while len(data) < data_length:
            chunk = conn.recv(min(4096, data_length - len(data)))
            if not chunk:
                break
            data += chunk

        if len(data) != data_length:
            print(f"[-] {addr}: Incomplete data received ({len(data)}/{data_length})")
            return

        # === Step 5: Upload to S3 ===
        upload_to_s3(filename , data)
        conn.sendall(b"OK")

    except Exception as e:
        print(f"[-] {addr}: Error {e}")
    finally:
        conn.close()
        print(f"[*] {addr}: Connection closed")

def start_server(host='0.0.0.0', port=12345):
    print(f"[+] Starting threaded TCP server on {host}:{port}")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind((host, port))
    server.listen(10)

    try:
        while True:
            conn, addr = server.accept()
            thread = threading.Thread(target=handle_client, args=(conn, addr))
            thread.daemon = True
            thread.start()
    except KeyboardInterrupt:
        print("\n[*] Server shutting down.")
    finally:
        server.close()

if __name__ == "__main__":
    start_server()
