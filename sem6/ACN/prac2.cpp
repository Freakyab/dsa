#include <iostream>
#include <string>
using namespace std;

int arr[4], index = 0, customSMN;
char className;
// Function to convert decimal to binary
string BtoD(int a)
{
    string binary = "";

    while (a > 0)
    {
        int remainder = a % 2;
        char digit = '0' + remainder;
        binary = digit + binary;
        a = a / 2;
    }
    return binary;
}

void classInBinary(string ip)
{
    string oct, result = "";
    for (int i = 0; i < index; i++)
    {
        result += BtoD(arr[i]);
        if (i < index - 1)
            result += '.'; // Add dot between octets
    }
    cout << "Class in Binary: " << result << endl;
    cout << "Class name: " << className << endl;
}

void binaryToDecimal(string ip)
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

    if (arr[0] >= 1 && arr[0] <= 126)
    {
        cout << "Class A address";
        className = 'A';
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        cout << "Class B address";
        className = 'B';
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        cout << "Class C address";
        className = 'C';
    }
}

void networkAndHostAddr()
{
    if (className == 'A')
    {
        cout << "Network ID: " << arr[0] << endl;
        cout << "Network Address: " << arr[0] << ".0.0.0" << endl;
        cout << "Host ID: " << arr[1] << "." << arr[2] << "." << arr[3] << endl;
        cout << "Host Address: 0." << arr[1] << "." << arr[2] << "." << arr[3] << endl;
    }
    else if (className == 'B')
    {
        
        cout << "Network ID: " << arr[0] << "." << arr[1] << endl;
        cout << "Network Address: " << arr[0] << "." << arr[1] << ".0.0" << endl;
        cout << "Host ID: " << arr[2] << "." << arr[3] << endl;
        cout << "Host Address: 0.0." << arr[2] << "." << arr[3] << endl;
    }
    else if (className == 'C')
    {
        cout << "Network ID: " << arr[0] << "." << arr[1] << "." << arr[2] << endl;
        cout << "Network Address: " << arr[0] << "." << arr[1] << "." << arr[2] << ".0" << endl;
        cout << "Host ID: " << arr[3] << endl;
        cout << "Host Address: 0.0.0." << arr[3] << endl;
    }
    cout << endl;
}

void subnetMaskAddr()
{
    string maskAdd = "00000000000000000000000000000000";
    int i = 0;
    while (customSMN > 0)
    {
        maskAdd[i] = '1';
        customSMN = customSMN - 1;
        i++;
    }

    for (int i = 0; i < maskAdd.size(); i++)
    {

        if (i == 8 || i == 17 || i == 26)
        {
            maskAdd.insert(i, 1, '.');
        }
    }
    cout << maskAdd << endl;
}

void addressInfo()
{
    if (className == 'A')
    {
        cout << endl
             << "First Address : " << arr[0] << ".0.0.0" << endl;
        cout << "Last Address : " << arr[0] << ".255.255.255" << endl;
        cout << "Total Addresses : " << 256 * 256 * 256 << endl;
    }
    else if (className == 'B')
    {
        cout << endl
             << "First Address : " << arr[0] << "." << arr[1] << ".0.0";
        cout << "Last Address : " << arr[0] << "." << arr[1] << ".255.255" << endl;
        cout << "Total Addresses : " << 256 * 256 << endl;
    }
    else if (className == 'C')
    {
        cout << endl
             << "First Address : " << arr[0] << "." << arr[1] << "." << arr[2] << ".0" << endl;
        cout << "Last Address : " << arr[0] << "." << arr[1] << "." << arr[2] << ".255" << endl;
        cout << "Total Addresses : " << 256 << endl;
    }
}

// Driver program to test above function
int main()
{
    string ipAddr;
    cout << "Enter the correct ip: ";
    cin >> ipAddr;

    binaryToDecimal(ipAddr);
    classInBinary(ipAddr);
    networkAndHostAddr();
    subnetMaskAddr();
    addressInfo();
    return 0;
}
