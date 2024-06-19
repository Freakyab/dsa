#include <bits/stdc++.h>

using namespace std;

int index = 0;
int oct_[4];

void checkToken(const string &token)
{
    index++;
    if (index > 4)
    {

        cout << "Error: Not index 4";
        exit(2);
    }
    else
    {
        if (token.size() > 1 && token[0] == '0')
        {
            cout << "Error: Leading zero";
            exit(2);
        }
        for (char a : token)
        {
            if (!(a >= '0' && a <= '9'))
            {
                cout << "Error: Not number";
                exit(2);
            }
        }
        int octValue = stoi(token);
        oct_[index - 1] = octValue;
        if (!(octValue >= 0 && octValue <= 255))
        {
            cout << "Error: Leading range";
            exit(2);
        }
    }
}

void sliptIp(const string &ip)
{
    string token = "";

    for (char i : ip)
    {
        if (i != '.')
        {
            token += i;
        }
        else
        {
            checkToken(token);
            token.clear();
        }
    }
    checkToken(token);
}

char checkClass()
{
    if (index < 4)
    {
        cout << "Error : Ip not complete " << 4 - index << " remaining oct";
        exit(2);
    }
    if (oct_[0] >= 0 && oct_[0] <= 126)
        return 'A';
    else if (oct_[0] == 127)
        return 'S';
    else if (oct_[0] >= 128 && oct_[0] <= 191)
        return 'B';
    else if (oct_[0] >= 191 && oct_[0] <= 223)
        return 'C';
    else if (oct_[0] >= 224 && oct_[0] <= 239)
        return 'D';
    else if (oct_[0] >= 240 && oct_[0] <= 255)
        return 'D';
}

int main()
{
    string ip;
    cout << "Enter the ip: ";
    cin >> ip;

    sliptIp(ip);
    checkClass() == 'S' ? cout << "Special Address" : cout << "Class: " << checkClass();
}