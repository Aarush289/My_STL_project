import socket 
import random
import threading
import sys
from concurrent.futures import ThreadPoolExecutor
import time
import os

HOST = '0.0.0.0'
PORT = 2891
MAX_CONNECTIONS = 10  # Maximum number of pending connections

MAX_THREADS = 5  # Maximum number of threads in the pool

server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
server_socket.bind((HOST, PORT))
server_socket.settimeout(2.0)  # Allow loop to catch Ctrl+C
