# Simplex duplex communication between server and client

import socket

def client():
    host = socket.gethostname()
    print(host)
    port = 8080
    
    clientSocket = socket.socket()
    clientSocket.connect((host, port))
    
    message = input(" -> ")
    
    while message.lower().strip() != 'bye':
        clientSocket.send(message.encode())
        data = clientSocket.recv(1024).decode()
        
        print("Received from server: " + data)
        
        message = input(" -> ")
        
    clientSocket.close()
    
if __name__ == '__main__':
    client()
    