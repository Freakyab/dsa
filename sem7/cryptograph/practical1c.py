def generate_key_square(key: str) -> list:
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    key = "".join(dict.fromkeys(key.upper().replace("J", "I")))
    key_square = list(key)
    
    for letter in alphabet:
        if letter not in key_square:
            key_square.append(letter)
    return [key_square[i:i + 5] for i in range(0, 25, 5)]

def prepare_text(text: str) -> str:
    text = text.upper().replace("J", "I")
    prepared_text = ""
    i = 0
    
    while i < len(text):
        prepared_text += text[i]
        i += 1

    # If the length of the text is odd, add 'X' at the end to make it even
    if len(prepared_text) % 2 != 0:
        prepared_text += 'X'
    
    return prepared_text

def find_position(char: str, key_square: list) -> tuple:
    for row in range(5):
        for col in range(5):
            if key_square[row][col] == char:
                return row, col
    return None

def playfair_encrypt(text: str, key_square: list) -> str:
    text = prepare_text(text)
    encrypted_text = ""
    
    for i in range(0, len(text), 2):
        row1, col1 = find_position(text[i], key_square)
        row2, col2 = find_position(text[i + 1], key_square)
        
        if row1 == row2:
            encrypted_text += key_square[row1][(col1 + 1) % 5]
            encrypted_text += key_square[row2][(col2 + 1) % 5]
        elif col1 == col2:
            encrypted_text += key_square[(row1 + 1) % 5][col1]
            encrypted_text += key_square[(row2 + 1) % 5][col2]
        else:
            encrypted_text += key_square[row1][col2]
            encrypted_text += key_square[row2][col1]
    
    return encrypted_text

def playfair_decrypt(text: str, key_square: list) -> str:
    decrypted_text = ""
    
    for i in range(0, len(text), 2):
        row1, col1 = find_position(text[i], key_square)
        row2, col2 = find_position(text[i + 1], key_square)
        
        if row1 == row2:
            decrypted_text += key_square[row1][(col1 - 1) % 5]
            decrypted_text += key_square[row2][(col2 - 1) % 5]
        elif col1 == col2:
            decrypted_text += key_square[(row1 - 1) % 5][col1]
            decrypted_text += key_square[(row2 - 1) % 5][col2]
        else:
            decrypted_text += key_square[row1][col2]
            decrypted_text += key_square[row2][col1]
    
    return decrypted_text

# Example usage
key = input("Enter the key: ")
text = input("Enter the text: ")

key_square = generate_key_square(key)
print("Key Square:")
for row in key_square:
    print(row)

encrypted_text = playfair_encrypt(text, key_square)
print(f"Encrypted Text: {encrypted_text}")

decrypted_text = playfair_decrypt(encrypted_text, key_square)
print(f"Decrypted Text: {decrypted_text.lower()}")
