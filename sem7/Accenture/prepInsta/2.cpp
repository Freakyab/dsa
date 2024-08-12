#include <iostream>
using namespace std;

int OperationsBinaryString(char *str)
{
    int total = 0;
    int first = *str - '0';
    str++;
    while (*str != '\0')
    {   
        char op = *str;
        str++;
        if (op == 'A')
        {
            first &= (*str - '0');
        }
        else if (op == 'B')
        {
            first |= (*str - '0');
        }
        else
        {
            first ^= (*str - '0');
        }
        str++;
    }
    return first;
}

int main()
{
    char str[] = "0C1A1B1C1C1B0A0";
    int a = OperationsBinaryString(str);
    cout<<a;
}