import socket

def client():
    
    host = socket.gethostname()
    port = 5000
    
    clientSocket = socket.socket()
    
    clientSocket.connect((host,port))
    
    message = input("-> ")
    
    while message != 'bye':
        clientSocket.send(message.encode())
        
        data = clientSocket.recv(1024).decode()
        
        print(data)
        
        message = input("-> ")
        
        
    clientSocket.close()
    
client()