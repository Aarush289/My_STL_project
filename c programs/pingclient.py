import socket
import sys 
import time
import threading 
SERVER_IP = '192.168.0.107' #lan 
Server_ip = '192.168.63.16' # mobile hotspot 
PING_REQUESTS=50
SERVER_PORT = 2891
from concurrent.futures import ThreadPoolExecutor
MAX_WORKERS = 10 

server_addr=(SERVER_IP , SERVER_PORT)

def main():
    loss=0
    min_rtt= float("inf")
    max_rtt=0
    avg_rtt=0
    try:
        client_socket = socket.socket(socket.AF_INET,socket.SOCK_DGRAM)
        client_socket.settimeout(2)
        for i in range(PING_REQUESTS):
            message = f"PING_REQUEST {i} \r\n\r\n ".encode()
            start  = time.perf_counter()
            client_socket.sendto(message , server_addr)
            try:
                response, _ = client_socket.recvfrom(1024)
                end = time.perf_counter()
                print("Received for ping {i}:", response)
                elapsed = (end - start)*1000
                avg_rtt+=elapsed
                if max_rtt <elapsed :
                    max_rtt=elapsed
                if min_rtt>elapsed :
                    min_rtt=elapsed
                print(f"RTT {i}: {elapsed:.8f} miliseconds")

            except socket.timeout:
                loss+=1
                print(f"No response for packet{i}(packet might have been lost)")
        if loss <50 :
             
         print(f"Max.RTT : {max_rtt}milliseconds     ,Min.RTT : {min_rtt}milliseconds   , Avg.RTT : {avg_rtt/(50-loss)}milliseconds  , persentage loss : {loss*2}%  ")
        else :
            print("ALL Packets lost !!")
    finally :
         client_socket.close()

if __name__ == "__main__":
        main()