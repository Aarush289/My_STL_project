import socket
import struct
import select
import time
from collections import defaultdict
from Crypto.Cipher import AES
from Crypto.Hash import HMAC, SHA256

# Server constants
HOST = '0.0.0.0'
PORT = 12345
CHUNK_BYTES = 16 * 4         # 16 floats = 64 bytes
PADDED_CHUNK = 64            # AES block-padded data
SEQ_BYTES = 2
PACKET_SIZE = PADDED_CHUNK + SEQ_BYTES

# AES & HMAC keys (32 bytes)
aes_key = bytes([
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe,
    0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7,
    0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
])
hmac_key = bytes([
    0xA0, 0xB1, 0xC2, 0xD3, 0xE4, 0xF5, 0x06, 0x17,
    0x28, 0x39, 0x4A, 0x5B, 0x6C, 0x7D, 0x8E, 0x9F,
    0x10, 0x21, 0x32, 0x43, 0x54, 0x65, 0x76, 0x87,
    0x98, 0xA9, 0xBA, 0xCB, 0xDC, 0xED, 0xFE, 0x0F
])

def derive_iv_from_seq(seq_16bit):
    h = HMAC.new(hmac_key, struct.pack('<H', seq_16bit), SHA256)
    return h.digest()[:16]

def decrypt_payload(encrypted_data, iv):
    cipher = AES.new(aes_key, AES.MODE_CBC, iv)
    padded = cipher.decrypt(encrypted_data)
    pad_len = padded[-1]
    if 1 <= pad_len <= 16:
        return padded[:-pad_len]
    return padded

def recv_exact(sock, num_bytes):
    buffer = b''
    while len(buffer) < num_bytes:
        part = sock.recv(num_bytes - len(buffer))
        if not part:
            raise ConnectionError("Connection closed while receiving packet")
        buffer += part
    return buffer

def handle_client(conn, addr):
    print(f"🔌 Connected from {addr}")
    expected_seq = 0
    buffer = {}
    received_count = 0
    start_time = time.time()

    try:
        while True:
            try:
                packet = recv_exact(conn, PACKET_SIZE)
            except ConnectionError:
                print("❌ Client disconnected unexpectedly.")
                break
            except Exception as e:
                print(f"❗ Error receiving data: {e}")
                break

            encrypted_payload = packet[:-2]
            seq = struct.unpack('>H', packet[-2:])[0]

            # Send ACK immediately
            try:
                conn.sendall(f"ACK:{seq}\n".encode())
            except Exception as e:
                print(f"⚠️ Failed to send ACK: {e}")

            if seq in buffer or seq < expected_seq:
                print(f"🔁 Duplicate or old packet ignored: {seq}")
                continue

            iv = derive_iv_from_seq(seq)
            try:
                decrypted = decrypt_payload(encrypted_payload, iv)
            except Exception as e:
                print(f"❌ Decryption failed for seq {seq}: {e}")
                continue

            floats = []
            for i in range(0, len(decrypted), 4):
                if i + 4 <= len(decrypted):
                    f = struct.unpack('<f', decrypted[i:i+4])[0]
                    floats.append(f)

            buffer[seq] = floats
            received_count += 1

            # Print and consume in-order packets
            while expected_seq in buffer:
                print(f"✅ Seq {expected_seq:04} | Floats: {buffer[expected_seq]}")
                del buffer[expected_seq]
                expected_seq = (expected_seq + 1) % 65536

    except Exception as e:
        print(f"❗ Unexpected server error: {e}")
    finally:
        conn.close()
        elapsed = time.time() - start_time
        print(f"🔌 Disconnected: {addr} | 📦 Packets: {received_count} | ⏱️ {elapsed:.2f}s")

def start_server():
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        server_socket.bind((HOST, PORT))
        server_socket.listen(5)
        print(f"🖥️ Server listening on {HOST}:{PORT}")

        while True:
            try:
                conn, addr = server_socket.accept()
                handle_client(conn, addr)
            except KeyboardInterrupt:
                print("\n🛑 Server shutdown requested.")
                break

if __name__ == "__main__":
    start_server()
