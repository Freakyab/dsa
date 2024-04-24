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
print ("Text  : " + text)
print ("Shift : " + str(s))
print ("Cipher: " + encrypt(text,s))
print ("Decipher: " + decrypt(encrypt(text,s),s))

# End to End chatbot using python
