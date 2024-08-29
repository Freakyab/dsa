#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to calculate the modular inverse
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No modular inverse if -1
}

// Encrypt using multiplicative cipher
string multiplicativeEncrypt(string plaintext, int key) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (((c - offset) * key) % 26) + offset;
        }
        ciphertext += c;
    }
    return ciphertext;
}

// Decrypt using multiplicative cipher
string multiplicativeDecrypt(string ciphertext, int key) {
    int inverseKey = modInverse(key, 26);
    if (inverseKey == -1) {
        return "Multiplicative inverse doesn't exist. Decryption not possible.";
    }
    
    string plaintext = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (((c - offset) * inverseKey) % 26);
            if (c < 0) c += 26;  // Handle negative values
            c += offset;
        }
        plaintext += c;
    }
    return plaintext;
}

int main() {
    string plaintext = "HELLO";
    int key = 5;

    string encryptedText = multiplicativeEncrypt(plaintext, key);
    cout << "Multiplicative Encrypted: " << encryptedText << endl;

    string decryptedText = multiplicativeDecrypt(encryptedText, key);
    cout << "Multiplicative Decrypted: " << decryptedText << endl;

    return 0;
}
