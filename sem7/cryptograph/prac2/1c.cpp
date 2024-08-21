#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void createInverseKey(int encryptionKey[], int length, int inverseKey[])
{
    pair<int, int> keyWithIndex[length];
    for (int i = 0; i < length; i++)
    {
        keyWithIndex[i] = make_pair(encryptionKey[i], i + 1);
    }

    sort(keyWithIndex, keyWithIndex + length);

    for (int i = 0; i < length; i++)
    {
        inverseKey[keyWithIndex[i].second - 1] = i + 1;
    }
}

int main()
{
    int length;

    cout << "Enter the length of the key: ";
    cin >> length;

    int encryptionKey[length];
    int inverseKey[length];

    cout << "Enter the encryption key values: ";
    for (int i = 0; i < length; i++)
    {
        cin >> encryptionKey[i];
    }

    createInverseKey(encryptionKey, length, inverseKey);

    cout << "The inverse (decryption) key is: ";
    for (int i = 0; i < length; i++)
    {
        cout << inverseKey[i] << " ";
    }
    cout << endl;

    return 0;
}
