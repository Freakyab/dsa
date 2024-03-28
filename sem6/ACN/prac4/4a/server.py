# Simplex duplex communication between server and client

import socket

def server():
    #get hostname
    host = socket.gethostname()
    print("hostname: ",host)
    port = 8080
    
    serverSocket = socket.socket()
    serverSocket.bind((host, port))
    
    serverSocket.listen(2)
    conn, addr = serverSocket.accept()
    
    
    print("Connection from: " + str(addr))
    
    while True:
        data = conn.recv(1024).decode()
        if not data:
            break
        print("From connected user: " + str(data))
        data = "Data received successfully!";
        conn.send(data.encode())
        
    conn.close()
    
if __name__ == '__main__':
    server()