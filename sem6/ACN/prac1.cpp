// #include <iostream>
// #include <string>

// using namespace std;

// void checkValidate(const string& ip, int arr[], int& index)
// {
//     string oct = "";
//     for (char c : ip)
//     {
//         if (c == '.')
//         {
//             if (oct[0] == '0' && oct.size() != 1)
//             {
//                 cout << "Error: Leading zero issue found\n";
//                 exit(1); // Exit with an error code
//             }

//             try
//             {
//                 int digit = stoi(oct);
//                 if (digit < 0 || digit > 255)
//                 {
//                     cout << "Error: Not in range\n";
//                     exit(2); // Exit with an error code
//                 }
//                 arr[index++] = digit;
//             }
//             catch (std::exception &e)
//             {
//                 cout << "Error: Alphabet found\n";
//                 exit(3); // Exit with an error code
//             }

//             oct = ""; // Reset oct for the next segment
//         }
//         else
//         {
//             oct += c;
//         }
//     }

//     // Handle the last octet
//     try
//     {
//         int digit = stoi(oct);
//         if (digit < 0 || digit > 255)
//         {
//             cout << "Error: Not in range\n";
//             exit(2); // Exit with an error code
//         }
//         arr[index++] = digit;
//     }
//     catch (std::exception &e)
//     {
//         cout << "Error: Alphabet found\n";
//         exit(3); // Exit with an error code
//     }
// }

// void validateClass(int arr[])
// {
//     if (arr[0] == 169 && arr[1] == 254 && arr[2] >= 0 && arr[2] <= 14)
//     {
//         cout << "Special Address: Link-local addresses";
//     }
//     else if (arr[0] == 127)
//     {
//         cout << "Special Address: Loop-back addresses";
//     }
//     else if (arr[0] == 224 || arr[0] == 254)
//     {
//         cout << "Special Address: Experimental or reserved for special purpose use";
//     }
//     else if (arr[0] >= 1 && arr[0] <= 126)
//     {
//         cout << "Class A address";
//     }
//     else if (arr[0] >= 128 && arr[0] <= 191)
//     {
//         cout << "Class B address";
//     }
//     else if (arr[0] >= 192 && arr[0] <= 223)
//     {
//         cout << "Class C address";
//     }
//     else
//     {
//         cout << "Special Address: Used to communicate within the current network";
//     }

//     cout << endl;
// }

// int main()
// {
//     string ipAddr;
//     cout << "Enter the ip: ";
//     cin >> ipAddr;

//     int arr[4], index = 0;
//     checkValidate(ipAddr, arr, index);

//     if (index != 4)
//     {
//         cout << "Error: IP address must have exactly 4 octets\n";
//         exit(4); // Exit with an error code
//     }

//     validateClass(arr);
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

int index = 0;
int OctArray[4];

int validIp(const string &token)
{
    index++;
    if (index > 4)
    {
        cout << "Not 4 octets";
        exit(2);
    }
    else
    {
        if (token.length() != 0 && token[0] == '0')
        {
            cout << "Leading Zero found";
            exit(2);
        }
        else
        {
            for (char i : token)
            {
                if (i < '0' || i > '9')
                {
                    cout << "Found alphabet";
                    exit(2);
                }
            }
            int octValue = stoi(token);

            if (octValue < 0 || octValue > 255)
            {
                cout << "Error: Not in range";
                exit(2);
            }
            OctArray[index - 1] = octValue;
        }
    }
}
void spiltTheString(const string &ip)
{
    string token;
    for (char ch : ip)
    {
        if (ch != '.')
        {
            token += ch;
        }
        else
        {
            validIp(token);
            token.clear();
        }
    }
    validIp(token);
}

int main()
{
    string ip;
    cout << "Enter the ip: ";
    cin >> ip;
    spiltTheString(ip);
    if (OctArray[0] >= 1 && OctArray[0] <= 126)
    {
        cout << "Class A";
    }
    else if (OctArray[0] == 127)
    {
        cout << "Special Address: Loop-back addresses";
    }
    else if (OctArray[0] >= 128 && OctArray[0] <= 191)
    {
        cout << "Class B";
    }
    else if (OctArray[0] >= 192 && OctArray[0] <= 223)
    {
        cout << "Class C";
    }
    else if (OctArray[0] >= 224 && OctArray[0] <= 239)
    {
        cout << "Class D";
    }
    else if (OctArray[0] >= 240 && OctArray[0] <= 255)
    {
        cout << "Class E";
    }
}
