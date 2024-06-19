#include <bits/stdc++.h>

using namespace std;

int octet[4], index = 0, subnetMask;
char className;
void sliptIp(const string &ip)
{
    string token;
    for (char i : ip)
    {
        if (i != '.' && i != '/')
        {
            token += i;
        }
        else
        {
            octet[index] = stoi(token);
            index++;
            token.clear();
        }
    }
    subnetMask = stoi(token);
}

void displayBinary()
{
    string binary, result;
    for (int i = 0; i < 4; i++)
    {
        int temp = octet[i];
        while (temp > 0)
        {
            int rem = temp % 2;
            char digit = '0' + rem;
            binary = digit + binary;
            temp /= 2;
        }
        while (binary.size() < 8)
        {
            binary = '0' + binary;
        }

        result += binary;
        if (i < 3)
            result += '.';
        binary.clear();
    }

    cout << result;
    if (octet[0] >= 0 && octet[0] <= 127)
    {
        cout << "A";
        className = 'A';
    };
    if (octet[0] >= 128 && octet[0] <= 191)
    {
        cout << "B";
        className = 'B';
    }
    if (octet[0] >= 192 && octet[0] <= 223)
    {
        cout << "C";
        className = 'C';
    }
    if (octet[0] >= 224 && octet[0] <= 239)
        cout << "D";
    if (octet[0] >= 240 && octet[0] <= 255)
        cout << "E";
}

void network()
{
    if (className == 'A')
    {
        cout << "Network id: " << octet[0] << endl;
        cout << "Network Address: " << octet[0] << ".0.0.0" << endl;
        cout << "Host id: " << octet[1] << "." << octet[2] << "." << octet[3] << endl;
        cout << "HOst Address: " << " 0." << octet[1] << "." << octet[2] << "." << octet[3] << endl;
    }
}

void subNetMask()
{
    string addr = "00000000000000000000000000000000";
    int temp = subnetMask, i = 0;
    while (temp != 0)
    {
        addr[i] = '1';
        i++, temp--;
    }
    cout << "Subnet mask: "<<stoi(addr.substr(0,8),0,2)<<
    "."<<stoi(addr.substr(8,8),0,2) << 
     "."<<stoi(addr.substr(16,8),0,2) <<
      "."<<stoi(addr.substr(24,8),0,2) <<endl;
}

int main()
{
    string ip;
    cout << "Enter the ip: ";
    cin >> ip;

    sliptIp(ip);
    displayBinary();
    network();
    subNetMask();
}