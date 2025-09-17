import socket
import sys 
import threading 
SERVER_IP = '192.168.0.107'

SERVER_PORT = 2891
from concurrent.futures import ThreadPoolExecutor
MAX_WORKERS = 10 

def fetch_file(path):
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket :
            #client_socket.bind(("192.168.0.105", 0))  # 0 means "any available port"
            client_socket.connect((SERVER_IP , SERVER_PORT))
            request = f"GET {path} HTTP/1.1\r\nHost: {SERVER_IP}\r\n\r\n"
            client_socket.send(request.encode())
            print(f"Request sent for {path} >>>>>>>")
            response = b""
            i=0
            while True:
                

                chunk = client_socket.recv(1024)
                if(not i):
                    if not chunk:
                        print(f"Requested file is empty :( ")
                i+=1
                if not chunk:
                    break
                response += chunk
                
            print_lock = threading.Lock()

            with print_lock:
                print(f"[{path}] Full Response:\n{response.decode()}\n{'-'*60}")

    except ConnectionRefusedError:
        print(f"[ERROR] Could not connect to server at {SERVER_IP}:{SERVER_PORT} for path {path}")
    except Exception as e:
        print(f"[ERROR] Unexpected error for {path}: {e}")

        #print(data.decode())
       # client_socket.close()

files=["/index.html", "/hi.html" , "/webt.html"]

with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
    for file in files:
        print(f"Requesting for {file} on {SERVER_PORT}")
        executor.submit(fetch_file, file)





