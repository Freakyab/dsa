#include <iostream>
#include <string>

using namespace std;

// Array of C++ keywords
const string keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
    "while", "class", "namespace", "template", "private", "protected", "public",
    "virtual", "operator", "new", "delete", "this", "throw", "catch", "try",
    "explicit", "friend", "mutable", "nullptr", "using", "static_assert",
    "constexpr", "decltype", "noexcept", "thread_local"
};

// Function to check if a string is a keyword
bool isKeyword(const string &str) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; ++i) {
        if (str == keywords[i]) {
            return true;
        }
    }
    return false;
}

// Function to check if a character is a digit
bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

// Function to check if a character is a letter
bool isLetter(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// Function to check if a string is a valid identifier
bool isIdentifier(const string &str) {
    if (str.empty() || isDigit(str[0])) return false; // Identifiers cannot start with a digit
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (!isLetter(ch) && !isDigit(ch) && ch != '_') return false; // Identifiers can only contain letters, digits, or underscores
    }
    return true;
}

// Function to check if a string is a constant (integer or floating-point)
bool isConstant(const string &str) {
    bool hasDecimalPoint = false;
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        char ch = str[i];
        if (ch == '.') {
            if (hasDecimalPoint) return false; // Multiple decimal points are not allowed
            hasDecimalPoint = true;
        } else if (!isDigit(ch)) {
            return false; // Non-digit characters make it invalid
        }
    }
    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isKeyword(input)) {
        cout << "\"" << input << "\" is a keyword." << std::endl;
    } else if (isConstant(input)) {
        cout << "\"" << input << "\" is a constant." << std::endl;
    } else if (isIdentifier(input)) {
        cout << "\"" << input << "\" is an identifier." << std::endl;
    } else {
        cout << "\"" << input << "\" is not a valid identifier, keyword, or constant." << std::endl;
    }

    return 0;
}
