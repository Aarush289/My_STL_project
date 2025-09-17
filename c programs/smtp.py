from socket import *
msg = "\r\n I love computer networks !"
endmsg = "\r\n.\r\n"

mailserver = ("smtp.gmail.com" , 587)

client_socket = socket(AF_INET, SOCK_STREAM)
client_socket.connect(mailserver)

recv = client_socket.recv(1024).decode()
print(recv)

if recv[:3]!='220' :
    print('220 reply not recieved from mail server.')

helo = 'HELLO ALICE \r\n'
client_socket.send(helo.encode())
recv1 = client_socket.recv(1024).decode()
print(recv1)

if recv1[:3]!='250' :
    print('250 reply not recieved from server.')

mailfrom = "MAIL FROM:<alice123@example.com>\r\n"
client_socket.send(mailfrom.encode())
recv2 = client_socket.recv(1024).decode()
print(recv2)

recpTO = "RCPT TO:<bob123@example.com>\r\n"
client_socket.send(recpTO.encode())
recv3 =client_socket.recv(1024).decode()
print(recv3)

data = 'DATA\r\n'
client_socket.send(data.encode())
recv4 = client_socket.recv(1024).decode()
print(recv4)

client_socket.send(msg.encode())
client_socket.send(endmsg.encode())
recv5 = client_socket.recv(1024).decode()
print(recv5)

quitcom = 'QUIT\r\n'
client_socket.send(quitcom.encode())
recv6 = client_socket.recv(1024).decode()
print(recv6)

client_socket.close()



