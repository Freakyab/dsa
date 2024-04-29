# Message encryption using python
#End to End chatbot using python
#calculate distance between two location

import math
from geopy.distance import geodesic

def distance(lat1, lon1, lat2, lon2):
    coords_1 = (lat1, lon1)
    coords_2 = (lat2, lon2)
    print(geodesic(coords_1, coords_2).km, "km")
    
distance(28.7041, 77.1025, 19.0760, 72.8777)

# Message encryption using python

def encrypt(text,s):
    result = ""
    for i in range(len(text)):
        char = text[i]
        if (char.isupper()):
            result += chr((ord(char) + s-65) % 26 + 65)
        else:
            result += chr((ord(char) + s - 97) % 26 + 97)
    return result

def decrypt(text,s):
    result = ""
    for i in range(len(text)):
        char = text[i]
        if (char.isupper()):
            result += chr((ord(char) - s-65) % 26 + 65)
        else:
            result += chr((ord(char) - s - 97) % 26 + 97)
    return result

text = "ATTACKATONCE"

s = 4
# print ("Text  : " + text)
# print ("Shift : " + str(s))
# print ("Cipher: " + encrypt(text,s))
# print ("Decipher: " + decrypt(encrypt(text,s),s))

# End to End chatbot using python
# Define a dictionary of responses
responses = {
    "hi": "Hello!",
    "how are you?": "I'm good, thank you!",
    "bye": "Goodbye!",
    "default": "I'm sorry, I don't understand that."
}

# Function to get response from user input
def get_response(user_input):
    # Convert user input to lowercase
    user_input = user_input.lower()
    
    # Check if user input exists in responses dictionary
    if user_input in responses:
        return responses[user_input]
    else:
        return responses["default"]

# Main function for chatting
def chat():
    print("Chatbot: Hi there! How can I help you?")
    
    while True:
        # Get user input
        user_input = input("You: ")
        
        # Check for exit command
        if user_input.lower() == "exit":
            print("Chatbot: Goodbye!")
            break
        
        # Get response and print it
        response = get_response(user_input)
        print("Chatbot:", response)

# Start the chat
chat()
