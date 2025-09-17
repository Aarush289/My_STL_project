import socket
import struct
from Crypto.Cipher import AES
from Crypto.Util.Padding import unpad

# AES-256 key (must match MCU)
AES_KEY = bytes([
    0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe,
    0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
    0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7,
    0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4
])

# AES IV (must match MCU)
AES_IV = bytes([
    0x00, 0x01, 0x02, 0x03,
    0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b,
    0x0c, 0x0d, 0x0e, 0x0f
])

def recv_all(conn, length):
    """Receive exactly 'length' bytes."""
    data = b''
    while len(data) < length:
        packet = conn.recv(length - len(data))
        if not packet:
            raise ConnectionError("Connection closed before receiving full data.")
        data += packet
    return data

def decrypt_data(encrypted: bytes) -> bytes:
    cipher = AES.new(AES_KEY, AES.MODE_CBC, AES_IV)
    return unpad(cipher.decrypt(encrypted), AES.block_size)

def parse_floats(data: bytes):
    if len(data) % 4 != 0:
        print("⚠️ Decrypted data length not multiple of 4")
        return []
    count = len(data) // 4
    return struct.unpack(f"<{count}f", data)

def handle_connection(conn, addr):
    print(f"\n🔗 Connection from {addr}")
    try:
        # Step 1: Receive 4-byte length header (network byte order)
        raw_len = recv_all(conn, 4)
        enc_len = struct.unpack("!I", raw_len)[0]
        print(f"📏 Expecting {enc_len} bytes of encrypted data")

        # Step 2: Receive encrypted payload
        encrypted = recv_all(conn, enc_len)
        print(f"📦 Received encrypted data ({len(encrypted)} bytes)")

        # Step 3: Decrypt
        decrypted = decrypt_data(encrypted)
        print(f"🔓 Decrypted {len(decrypted)} bytes")

        # Step 4: Parse floats
        floats = parse_floats(decrypted)
        if floats:
            print(f"📊 Parsed {len(floats)} floats:")
            for i, f in enumerate(floats[:10]):
                print(f"[{i:04d}] {f:.4f}")
            if len(floats) > 10:
                print(f"... and {len(floats)-10} more")
        else:
            print("⚠️ No valid floats decoded")

        # Step 5: Send ACK
        conn.sendall(b"ACK")
        print("✅ Sent ACK")

    except Exception as e:
        print(f"❌ Error during handling: {e}")
    finally:
        conn.close()

def start_server(host="0.0.0.0", port=12345):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        server_socket.bind((host, port))
        server_socket.listen(5)
        while True:
            print(f"🚀 Server listening on {host}:{port}\n")
            conn, addr = server_socket.accept()
            handle_connection(conn, addr)

if __name__ == "__main__":
    start_server()
