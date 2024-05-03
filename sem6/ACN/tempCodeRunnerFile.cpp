#include <iostream>
#include <string>
using namespace std;

int OctArray[4], octNumber = 0;

void splitTheIp(const string &ip)
{
    string token;
    for (char i : ip)
    {
        if (i != '.')
        {
            token += i;
        }
        else
        {
            token.clear();
        }
    }
}
int main()
{
    string ipAddr;
    cout << "Enter an IPv4 address with CIDR No.: ";
    cin >> ipAddr;
    splitTheIp(ipAddr);
    int choice;
    do
    {
        cout << "Select an action:\n"
             << "1. Display Binary and Decimal Representation\n"
             << "2. Display Network and Host Addresses\n"
             << "3. Display Subnet Mask\n"
             << "4. Display Address Information\n"
             << "0. Exit\n";
        cout << "Enter the number corresponding to your choice: ";
        cin >> choice;
    } while (true);
}