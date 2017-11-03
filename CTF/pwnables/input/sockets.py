import socket

HOST = 'localhost'
PORT = 8800
c = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
c.connect((HOST,PORT))
c.send("\xde\xad\xbe\xef")

