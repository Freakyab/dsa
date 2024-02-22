#include <iostream>
#include <string>

using namespace std;

void checkValidate(const string& ip, int arr[], int& index)
{
    string oct = "";
    for (char c : ip)
    {
        if (c == '.')
        {
            if (oct[0] == '0' && oct.size() != 1)
            {
                cout << "Error: Leading zero issue found\n";
                exit(1); // Exit with an error code
            }

            try
            {
                int digit = stoi(oct);
                if (digit < 0 || digit > 255)
                {
                    cout << "Error: Not in range\n";
                    exit(2); // Exit with an error code
                }
                arr[index++] = digit;
            }
            catch (std::exception &e)
            {
                cout << "Error: Alphabet found\n";
                exit(3); // Exit with an error code
            }

            oct = ""; // Reset oct for the next segment
        }
        else
        {
            oct += c;
        }
    }

    // Handle the last octet
    try
    {
        int digit = stoi(oct);
        if (digit < 0 || digit > 255)
        {
            cout << "Error: Not in range\n";
            exit(2); // Exit with an error code
        }
        arr[index++] = digit;
    }
    catch (std::exception &e)
    {
        cout << "Error: Alphabet found\n";
        exit(3); // Exit with an error code
    }
}

void validateClass(int arr[])
{
    if (arr[0] == 169 && arr[1] == 254 && arr[2] >= 0 && arr[2] <= 14)
    {
        cout << "Special Address: Link-local addresses";
    }
    else if (arr[0] == 127)
    {
        cout << "Special Address: Loop-back addresses";
    }
    else if (arr[0] == 224 || arr[0] == 254)
    {
        cout << "Special Address: Experimental or reserved for special purpose use";
    }
    else if (arr[0] >= 1 && arr[0] <= 126)
    {
        cout << "Class A address";
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        cout << "Class B address";
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        cout << "Class C address";
    }
    else
    {
        cout << "Special Address: Used to communicate within the current network";
    }

    cout << endl;
}

int main()
{
    string ipAddr;
    cout << "Enter the ip: ";
    cin >> ipAddr;

    int arr[4], index = 0;
    checkValidate(ipAddr, arr, index);

    if (index != 4)
    {
        cout << "Error: IP address must have exactly 4 octets\n";
        exit(4); // Exit with an error code
    }

    validateClass(arr);
    return 0;
}
