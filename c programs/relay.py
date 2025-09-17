import socket
import struct
import boto3
import datetime
import os

# AWS S3 Configuration
BUCKET_NAME = 'final-output2-demo'
REGION_NAME = 'eu-north-1'  # e.g., 'us-east-1'

# Initialize S3 client (assumes credentials are configured via AWS CLI or environment)
s3_client = boto3.client('s3', region_name=REGION_NAME)

def upload_to_s3(data: bytes):
    # Generate unique filename
    timestamp = datetime.datetime.now(datetime.timezone.utc).strftime("%Y%m%d-%H%M%S")
    filename = f"encrypted_{timestamp}.enc"
    
    # Upload to S3
    s3_client.put_object(Bucket=BUCKET_NAME, Key=filename, Body=data)
    print(f"[+] Uploaded file {filename} to bucket {BUCKET_NAME}")

def handle_client(conn, addr):
    try:
        print(f"[+] Connection from {addr}")

        # Step 1: Read 4 bytes for the data length (network byte order -> host byte order)
        length_prefix = conn.recv(4)
        if len(length_prefix) < 4:
            print("[-] Invalid length prefix")
            return

        data_length = struct.unpack('!I', length_prefix)[0]  # '!I' is network-order unsigned int
        print(f"[+] Expecting {data_length} bytes of data")

        # Step 2: Receive the actual encrypted data
        data = b''
        while len(data) < data_length:
            chunk = conn.recv(min(4096, data_length - len(data)))
            if not chunk:
                break
            data += chunk

        if len(data) != data_length:
            print("[-] Incomplete data received")
            return

        # Step 3: Upload to S3
        upload_to_s3(data)

        # Optional: Acknowledge back to MCU
        conn.sendall(b"OK")

    except Exception as e:
        print(f"[-] Error: {e}")
    finally:
        conn.close()
        print("[*] Connection closed")

def start_server(host='0.0.0.0', port=12345):
    print(f"[+] Starting TCP server on {host}:{port}")
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen(5)

    try:
        while True:
            conn, addr = server.accept()
            handle_client(conn, addr)
    except KeyboardInterrupt:
        print("\n[*] Server shutting down.")
    finally:
        server.close()

if __name__ == "__main__":
    start_server()
