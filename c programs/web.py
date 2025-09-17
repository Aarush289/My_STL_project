import socket
import sys 
import threading 
# ip = 192.168.0.107
HOST = '0.0.0.0'
PORT = 12345
from concurrent.futures import ThreadPoolExecutor
MAX_WORKERS = 10 

# This web server allows multiple clients to connect , since whenever a client tries to connect , server will make a socket through "accept()" in the code and assign to an idle thread # 
def handle_client(conn):
        try:
            message = conn.recv(1024).decode()                               # receives http request from client
            filename = message.split()[1]                                     #Gets the requested path  i.e. /filename.html from GET /filename.html HTTP/1.1
            f = open(filename[1:])                                          # Remove leading "/" from filename  and tries to open the requested file 
            outputdata = f.read()                                            # read and write the output file 

            conn.send("HTTP/1.1 200 OK\r\n\r\n".encode())                    # if the requested file is available(that means it get opened on trying ) then it will send this 200 OK message 
            conn.send(outputdata.encode())                                  # sending the output file 
            conn.send("\r\n".encode())                                      # signaling the end of the output file 
            conn.close()                                                        # as soon as required file is sent , it closes the connection 

        except FileNotFoundError:                                            # in case , file is not available , send 404 Not Found message 
            conn.send("HTTP/1.1 404 Not Found\r\n\r\n".encode())
            conn.send("<html><body><h1>404 Not Found</h1></body></html>\r\n".encode())
            conn.close()
        finally:
             conn.close()                                                   # closes the connection 

def main():

    server_Socket = socket.socket(socket.AF_INET , socket.SOCK_STREAM)                           # this is where socket is created 
    server_Socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)     # this allows quick use of port just after restart of server 
    try:
        server_Socket.bind((HOST,PORT))                                     # binds the ip and port number to server_socket 
        server_Socket.listen(10)                                            # allows 10 pending connections 
        print("Ready to serve connection from {HOST}:{PORT}")
        with ThreadPoolExecutor(max_workers=MAX_WORKERS) as executor:
            while True :
                print("Main server listening on {PORT}....")
                try:
                    conn , addr = server_Socket.accept()
                    #client_thread = threading.Thread(target=handle_client , args=(conn))
                   # client_thread.start()
                    print(f"[+] Connection from {addr}")
                    executor.submit(handle_client,conn) # assign client to next available thread  
                except KeyboardInterrupt: 
                        print("\n[!] Server shutdown requested")
                        break
                        
                except Exception as e:
                        print(f"[!] Connection error: {str(e)}")
                        
    finally:
        # Clean up server socket
        server_Socket.close()
        print("[*] Server shutdown complete")
        
if __name__ == "__main__":
        main()









