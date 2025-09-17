import socket 

HOST='0.0.0.0'
PORT= 2891

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.bind((HOST,PORT))
    server_socket.listen(1)
    print("Listening .... ")
    
    while True:
        conn, addr = server_socket.accept()
        with conn:
            print(f"\nConnected by {addr}")
            while True:
                data = conn.recv(1024)
                
                if not data:
                    break
                print(data.decode(errors='ignore'))
    