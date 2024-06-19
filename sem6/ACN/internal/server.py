import socket 

def server():
    
    serverSocket = socket.socket();
    
    host = socket.gethostname();
    port = 5000;
    
    serverSocket.bind((host,port));
    
    serverSocket.listen(2)
    
    conn, addr = serverSocket.accept()
    
    while True:
        
        data = conn.recv(1024).decode()
        
        print("Connection from: " + str(addr))
        print("data : " + str(data))
        
        conn.send("data recv".encode())
        
        if not data:
            break
        
    serverSocket.close()
    
server()
        
        