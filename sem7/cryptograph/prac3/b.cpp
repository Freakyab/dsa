#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to calculate the modular multiplicative inverse
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse doesn't exist
}

// Encrypt using affine cipher
string affineEncrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (((a * (c - offset)) + b) % 26) + offset;
        }
        ciphertext += c;
    }
    return ciphertext;
}

// Decrypt using affine cipher
string affineDecrypt(string ciphertext, int a, int b) {
    int inverseA = modInverse(a, 26);
    if (inverseA == -1) {
        return "Multiplicative inverse doesn't exist. Decryption not possible.";
    }
    
    string plaintext = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char offset = isupper(c) ? 'A' : 'a';
            c = (((inverseA * (c - offset - b)) % 26));
            if (c < 0) c += 26;  // Handle negative values
            c += offset;
        }
        plaintext += c;
    }
    return plaintext;
}

int main() {
    string plaintext = "HELLO";
    int a = 5; // Multiplicative key
    int b = 8; // Additive key

    string encryptedText = affineEncrypt(plaintext, a, b);
    cout << "Affine Encrypted: " << encryptedText << endl;

    string decryptedText = affineDecrypt(encryptedText, a, b);
    cout << "Affine Decrypted: " << decryptedText << endl;

    return 0;
}
