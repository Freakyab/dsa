#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input = "";
    cout << "Enter the string: ";
    getline(cin,input);
    bool isComment = false;

    if (input[0] == '/' && input[1] == '/')
    {
        isComment = true;
    }
    else if (input[0] == '/' && input[1] == '*' && input[input.size() - 1] == '/' && input[input.size() - 2] == '*')
    {
        isComment = true;
    }

    if (isComment)
        cout << "Entered string is comment";
    else
        cout << "Entered string is not a comment";

    return 0;
}