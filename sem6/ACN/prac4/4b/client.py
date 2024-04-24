import socket

def run_client():
    server_ip = "127.0.0.1"
    port = 7000

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((server_ip, port))

    print("Connected to server")

    while True:
        message = input("Enter message to send to server: ")
        client.send(message.encode("utf-8"))

        if message.lower() == "close":
            response = client.recv(1024)
            print(response.decode("utf-8"))
            break

        response = client.recv(1024)
        print("Response from server:", response.decode("utf-8"))

    client.close()
    print("Connection to server closed")

run_client()
