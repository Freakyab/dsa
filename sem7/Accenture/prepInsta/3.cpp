#include <iostream>

using namespace std;

int CheckPassword(char str[], int n)
{
    if (n < 4)
    {
        return 0;
    }
    int isDigit = 0, isCapital = 0;
    if (str[0] >= '0' && str[0] <= '9')
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0' || str[i] == '/')
            return 0;
        if (str[i] >= '0' && str[i] <= '9')
            isDigit = 1;
        if (str[i] >= 'A' && str[i] <= 'Z')
            isCapital = 1;
    }
    if (isDigit && isCapital)
        return 1;
    else
        return 0;
}

int main()
{
    char password[] = "a987";
    int n = sizeof(password) / sizeof(char);
    cout << CheckPassword(password, n-1);
}