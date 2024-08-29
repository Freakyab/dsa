#include <iostream>
#include <string>

using namespace std;
string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "class", "namespace", "template", "private", "protected", "public",
    "virtual", "operator", "new", "delete", "this", "throw", "catch", "try",
    "explicit", "friend", "mutable", "nullptr", "using", "static_assert",
    "constexpr", "decltype", "noexcept", "thread_local"
};

void checkFloat(string token)
{
    try
    {
        stof(token);
        cout << "Type: CONSTANT, Value: " << token << endl;
    }
    catch (invalid_argument &e)
    {
        cout << "Type: IDENTIFIER, Value: " << token << endl;
    }
}

void checkKeyword(string token)
{
    bool isKeyword = false;
    for (const auto &keyword : keywords)
    {
        if (token == keyword)
        {
            cout << "TYPE: KEYWORD, Value: " << token << endl;
            isKeyword = true;
            break;
        }
    }
    if (!isKeyword)
    {
        checkFloat(token);
    }
    
}

void LexicalAnalyzer(string input)
{
    int n = input.size();

    string token = "";

    for (int i = 0; i < n; i++)
    {
        if (input[i] != ' ' && input[i] != '(' && input[i] != ')' && input[i] != '{' && input[i] != '}' && input[i] != ';' && input[i] != '+' && input[i] != '-' && input[i] != '=')
        {
            token += input[i];
        }
        else
        {
            if (!token.empty())
            {
                checkKeyword(token);
                token = "";
            }

            if (input[i] == '+' || input[i] == '-' || input[i] == '=')
            {
                cout << "Type: OPERATOR, Value: " << input[i] << endl;
            }

            if (input[i] == '(' || input[i] == ')' || input[i] == '{' || input[i] == '}' || input[i] == ';')
            {
                cout << "Type: PUNCTUATOR, Value: " << input[i] << endl;
            }
        }
    }

    if (!token.empty())
    {
        checkKeyword(token);
        token = "";
    }
}

int main()
{
    string input = "int main() { float x = 3.14; float y = 3.15; float z = x + y; return 0; }";
    LexicalAnalyzer(input);
    return 0;
}
