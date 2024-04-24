import socket
import threading

def handle_client(client_socket, client_address):
    print(f"Accepted connection from {client_address[0]}:{client_address[1]}")

    while True:
        request = client_socket.recv(1024)
        request = request.decode("utf-8")

        if request.lower() == "close":
            client_socket.send("closed".encode("utf-8"))
            break

        print(f"Received: {request}")

        response = input("Enter message to send to client: ").encode("utf-8")
        client_socket.send(response)

    client_socket.close()
    print(f"Connection to {client_address[0]}:{client_address[1]} closed")

def run_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_ip = "192.168.137.238"
    port = 7000

    server.bind((server_ip, port))
    server.listen(15)  # Listen for up to 5 connections

    print(f"Listening on {server_ip}:{port}")

    while True:
        client_socket, client_address = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_handler.start()

run_server()
