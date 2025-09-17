import base64
import ssl
from socket import *

msg = "\r\n I love Computer "
endmsg = "\r\n.\r\n"

mail_server = ("smtp.gmail.com", 587)
client_socket = socket(AF_INET , SOCK_STREAM)
client_socket.connect(mail_server)

recv1 = client_socket.recv(1024).decode()
print(recv1)

if recv1[:3]!='220':
    print("220 reply not received from server.")

client_socket.send(b"EHLO gmail.com\r\n")
recv1= client_socket.recv(1024).decode()
print(recv1)

client_socket.send(b"STARTTLS\r\n")
recv1 = client_socket.recv(1024).decode()
print(recv1)

if recv1[:3]!='220':
    print("220 reply not received from server .")

context = ssl.create_default_context()
client_socket= context.wrap_socket(client_socket , server_hostname="smtp.gmail.com")

client_socket.send(b"EHLO gmail.com\r\n")
recv1= client_socket.recv(1024).decode()
print(recv1)

username = "aarush289156@gmail.com"
password = "sang sbrl qpti etzz"

client_socket.send(b"AUTH LOGIN\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

client_socket.send(base64.b64encode(username.encode()) + b"\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

client_socket.send(base64.b64encode(password.encode()) + b"\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

# Step 7: MAIL FROM
client_socket.send(b"MAIL FROM:<aarush289156@gmail.com>\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

# Step 8: RCPT TO
client_socket.send(b"RCPT TO:<cs24b064@smail.iitm.ac.in>\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

# Step 9: DATA
client_socket.send(b"DATA\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

# Step 10: Send message content and end with .\r\n
client_socket.send(msg.encode())
client_socket.send(endmsg.encode())
recv = client_socket.recv(1024).decode()
print(recv)

# Step 11: QUIT
client_socket.send(b"QUIT\r\n")
recv = client_socket.recv(1024).decode()
print(recv)

client_socket.close()
