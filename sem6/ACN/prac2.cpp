#include <iostream>
#include <string>
#include <math.h>
#include <typeinfo>
using namespace std;

int arr[4], index = 0, customSMN;
char className;
// Function to convert decimal to binary
string DecimalToBinary(int a)
{
    string binary = "";

    while (a > 0)
    {
        int remainder = a % 2;
        char digit = '0' + remainder;
        binary = digit + binary;
        a = a / 2;
    }

    // Pad with leading zeros to make it 8 bits
    while (binary.length() < 8)
    {
        binary = '0' + binary;
    }

    return binary;
}

void classInBinary()
{
    string result = "";
    for (int i = 0; i < index; i++)
    {
        result += DecimalToBinary(arr[i]);
        if (i < index - 1)
            result += '.'; // Add dot between octets
    }
    cout << "\tClass in Binary: " << result << endl;
    if (arr[0] >= 1 && arr[0] <= 126)
    {
        cout << "\tClass A address";
        className = 'A';
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        cout << "\tClass B address";
        className = 'B';
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        cout << "\tClass C address";
        className = 'C';
    }
    cout << endl;
}

void detailsExtracter(string ip)
{
    string oct = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            arr[index] = stoi(oct);
            index++;
            oct = "";
        }
        else
        {
            if (ip[i] == '/')
            {
                customSMN = stoi(ip.substr(i + 1, (ip.size() - i)));
            }
            oct += ip[i];
        }
    }

    arr[index] = stoi(oct);
    index++;
     if (arr[0] >= 1 && arr[0] <= 126)
    {
        className = 'A';
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        className = 'B';
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        className = 'C';
    }
}

void networkAndHostAddr()
{
    if (className == 'A')
    {
        cout << "\tNetwork ID: " << arr[0] << endl;
        cout << "\tNetwork Address: " << arr[0] << ".0.0.0" << endl;
        cout << "\tHost ID: " << arr[1] << "." << arr[2] << "." << arr[3] << endl;
        cout << "\tHost Address: 0." << arr[1] << "." << arr[2] << "." << arr[3] << endl;
    }
    else if (className == 'B')
    {

        cout << "\tNetwork ID: " << arr[0] << "." << arr[1] << endl;
        cout << "\tNetwork Address: " << arr[0] << "." << arr[1] << ".0.0" << endl;
        cout << "\tHost ID: " << arr[2] << "." << arr[3] << endl;
        cout << "\tHost Address: 0.0." << arr[2] << "." << arr[3] << endl;
    }
    else if (className == 'C')
    {
        cout << "\tNetwork ID: " << arr[0] << "." << arr[1] << "." << arr[2] << endl;
        cout << "\tNetwork Address: " << arr[0] << "." << arr[1] << "." << arr[2] << ".0" << endl;
        cout << "\tHost ID: " << arr[3] << endl;
        cout << "\tHost Address: 0.0.0." << arr[3] << endl;
    }
    cout << endl;
}

void subnetMaskAddr()
{
    string maskAdd = "00000000000000000000000000000000";
    int i = 0;
    int temp = customSMN;
    while (temp > 0)
    {
        maskAdd[i] = '1';
        temp = temp - 1;
        i++;
    }

    cout << "\tCustom Masking Address : " << stoi(maskAdd.substr(0, 8), 0, 2)
         << "." << stoi(maskAdd.substr(8, 8), 0, 2)
         << "." << stoi(maskAdd.substr(16, 8), 0, 2)
         << "." << stoi(maskAdd.substr(24, 8), 0, 2) << endl;
}

void addressInfo()
{
    if (className == 'A')
    {
        cout << "\tFirst Address : " << arr[0] << ".0.0.0" << endl;
        cout << "\tLast Address : " << arr[0] << ".255.255.255" << endl;
        cout << "\tTotal Addresses : " << 256 * 256 * 256 << endl;
    }
    else if (className == 'B')
    {
        cout
            << "\tFirst Address : " << arr[0] << "." << arr[1] << ".0.0";
        cout << "\tLast Address : " << arr[0] << "." << arr[1] << ".255.255" << endl;
        cout << "\tTotal Addresses : " << 256 * 256 << endl;
    }
    else if (className == 'C')
    {
        cout
            << "\tFirst Address : " << arr[0] << "." << arr[1] << "." << arr[2] << ".0" << endl;
        cout << "\tLast Address : " << arr[0] << "." << arr[1] << "." << arr[2] << ".255" << endl;
        cout << "\tTotal Addresses : " << 256 << endl;
    }
}

// Driver program to test above function
int main()
{
    string ipAddr;
    cout << "Enter an IPv4 address with CIDR No.: ";
    cin >> ipAddr;
    int action;

    do
    {
        cout << "Select an action:\n"
             << "1. Display Binary and Decimal Representation\n"
             << "2. Display Network and Host Addresses\n"
             << "3. Display Subnet Mask\n"
             << "4. Display Address Information\n"
             << "0. Exit\n";
        cout << "Enter the number corresponding to your choice: ";
        cin >> action;

        detailsExtracter(ipAddr);
        if (action == 1)
        {
            cout << endl;
            classInBinary();
            cout << endl;
        }
        else if (action == 2)
        {
            cout << endl;
            networkAndHostAddr();
            cout << endl;
        }
        else if (action == 3)
        {
            cout << endl;
            subnetMaskAddr();
            cout << endl;
        }
        else if (action == 4)
        {
            cout << endl;
            addressInfo();
            cout << endl;
        }
        else if (action == 0)
        {
            cout << endl;
            cout << "Exiting the program." << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "Invalid choice. Please enter a valid option." << endl;
            cout << endl;
        }
    } while (action != 0);

    return 0;
}
