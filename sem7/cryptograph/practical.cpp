#include <iostream>
#include <string.h>
using namespace std;

void Encrypt(string plainText, int k = 3)
{
    string cipherText = "";

    for (int i = 0; i < plainText.size(); i++)
    {
        int originalCiperWord = int(plainText[i] - 97);
        cipherText += (char)(((originalCiperWord + k) % 26) + 97 - 32);
    }
    cout << "\n\n\nThe cipher Text :" << cipherText << "\n\n\n";
}

void Decrypt(string cipherText, int k = 3)
{

    string plainText = "";

    for (int i = 0; i < cipherText.size(); i++)
    {
        int originalPlainWord = int(cipherText[i] - 65);
        if (originalPlainWord - k < 0)
        {
            plainText += (char)(((26 - (k - originalPlainWord)) % 26) + 65 + 32);
        }
        else
        {
            plainText += (char)(((originalPlainWord - k) % 26) + 65 + 32);
        }
    }
    cout << "\n\n\nThe plain text is: " << plainText << "\n\n\n";
}

int main()
{   
    string plainText;
    // string cipherText = "UVACLYFZLJBYL";
    string cipherText;
    // Encrypt(plainText);

    // Decrypt(cipherText, 7);
    int action;
    while (true)
    {
        cout << "Choose the case:\n1.Enter the P.T to get C.T (using caesar method).\n"
             << "2.Enter the C.T to get P.T (using caesar method).\n"
             << "3.Enter the P.T to get C.T (using modify caesar method).\n"
             << "4.Enter the C.T to get P.T (using modify caesar method).\n";

        cin >> action;

        if (action == 1)
        {
            cout << "Enter your plain text: ";
            cin >> plainText;
            Encrypt(plainText);
        }
        else if (action == 2)
        {
            cout << "Enter your cipher text: ";
            cin >> cipherText;
            Decrypt(cipherText);
        }
        else if (action == 3)
        {
            int key;
            cout << "Enter your plain text: ";
            cin >> plainText;
            cout << "Enter the key: ";
            cin >> key;
            Encrypt(plainText, key);
        }
        else if (action == 4)
        {
            int key;
            cout << "Enter your cipher text: ";
            cin >> cipherText;
            cout << "Enter the key: ";
            cin >> key;
            Decrypt(cipherText, key);
        }
        else
        {
            cout<<"Invalid";
            break;
        }
    }
}
