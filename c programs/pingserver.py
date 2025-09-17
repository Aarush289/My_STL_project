import socket 
import random
import threading
import sys
from concurrent.futures import ThreadPoolExecutor

HOST='0.0.0.0'
PORT= 2891

server_socket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM ) 

server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
try:
    server_socket.bind((HOST,PORT))
    server_socket.settimeout(2.0)  # <-- Allow loop to catch Ctrl+C                                        # allows 10 pending connections 
    print(f"Ready to serve connection from {HOST}:{PORT}")

    while True :
        print(f"Main server listening on {PORT}....")
        try:
            message , addr = server_socket.recvfrom(2024)
            print(message)
            server_socket.sendto(message,addr)
        except socket.timeout:
            continue  # just loop again, check for Ctrl+C
except KeyboardInterrupt: 
        print("\n[!] Server shutdown requested")
        
except Exception as e:
        print(f"[!] Connection error: {str(e)}")
                    
finally:
    # Clean up server socket
    server_socket.close()
    print("[*] Server shutdown complete")
    