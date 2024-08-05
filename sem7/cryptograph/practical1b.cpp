#include <iostream>
#include <string.h>
using namespace std;

int getSmallCharValue(char a)
{
    return (int(a) - 97);
}
int getCapCharValue(char A)
{
    return (int(A) - 65);
}

char Encrypt(char plainWord, int k)
{
    char cipherWord;

    int originalCiperWord = int(plainWord - 97);
    cipherWord = (char)(((originalCiperWord + k) % 26) + 97 - 32);
    
    return cipherWord;
}

void vin(string plainText, string cipherText)
{
    cout << "P.T : \t";
    for (int i = 0; i < plainText.size(); i++)
    {
        cout << plainText[i] << " |";
    }
    cout << endl;
    cout << "val : \t";
    for (int j = 0; j < plainText.size(); j++)
    {
        cout << getSmallCharValue(plainText[j]) << " |";
    }
    cout << endl;
    cout << "key : \t";
    for (int j = 0; j < plainText.size(); j++)
    {
        cout << getCapCharValue(cipherText[j % cipherText.size()]) << " |";
    }
    cout << endl;
    cout << "C.T : \t";
    for (int k = 0; k < plainText.size(); k++)
    {
        cout << Encrypt(plainText[k], getCapCharValue(cipherText[k % cipherText.size()])) << " |";
    }
    cout << endl;
}

int main()
{
    string plainText = "sheislistening";
    string cipherText = "PASCAL";

    vin(plainText, cipherText);
}