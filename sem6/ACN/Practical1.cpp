#include <iostream>
#include <string>

using namespace std;

// Error status

const int STARTING_WITH_ZERO = 2;
const int LEADING_ZERO = 3;
const int CLASS_A = 4;
const int CLASS_B = 5;
const int CLASS_C = 6;
const int NOT_IN_RANGE = 7;
const int NOT_INTEGER = -1;
const int LEADING_OCT = 8;
const int BLANK_SPACE = 9;
const int EXACTLY_4_OCTETS = 10;

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

int stringToInteger(const string &s)
{
    int result = 0;
    for (char c : s)
    {
        if (!isDigit(c))
        {
            return NOT_INTEGER; // Error if the string contains non-digit characters
        }
        result = result * 10 + (c - '0');
    }
    return result;
}

int validateSegment(string segment, int arr[], int index)
{
    if (segment[0] == '0' && segment.size() != 1)
    {
        return LEADING_ZERO;
    }
    int digit = stringToInteger(segment);

    if (digit == NOT_INTEGER)
    {
        return NOT_INTEGER;
    }

    if (digit > 255)
    {
        return NOT_IN_RANGE;
    }

    // You may want to store the digit in the array for further use
    arr[index] = digit;
    return 0;
}

int validateClass(int arr[])
{
    // Check the first octet to identify the class
    if (arr[0] == 169 && arr[1] == 254 && arr[2] >= 0 && arr[2] <= 14)
    {
        cout << "Link-local addresses";
        return 0;
    }
    // else if(arr[0] = 0 )

    else if (arr[0] == 127)
    {
        cout << "Loop-back addresses ";
        return 0;
    }

    else if (arr[0] == 224 || arr[0] == 254)
    {
        cout << " Experimental or reserved for special purpose use";
        return 0;
    }

    else if (arr[0] >= 1 && arr[0] <= 126)
    {
        cout << "Class A address" << endl;
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        cout << "Class B address" << endl;
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        cout << "Class C address" << endl;
    }
    else
    {
        cout << "Used to communicate within the current network" << endl;
    }
}

int checkValidate(string ip)
{
    int j = 0, index = 0;
    int arr[4];
    string oct = "";

    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == ' ')
        {
            cout << "Blank space found" << endl;
            return BLANK_SPACE;
        }
        while (j < ip.size() && (ip[j] != '.' && ip[j] != ':'))
        {
            oct += ip[j];
            j++;
        }

        if (!oct.empty())
        {
            int errorCode = validateSegment(oct, arr, index);
            if (errorCode == NOT_IN_RANGE)
            {
                return NOT_IN_RANGE;
            }
            else if (errorCode == NOT_INTEGER)
            {
                return NOT_INTEGER;
            }
            else if (errorCode == LEADING_ZERO)
            {
                return LEADING_ZERO;
            }
            else if (index >= 4)
            {
                return LEADING_OCT;
            }
            oct = ""; // Reset oct for the next segment
            index++;
        }

        j++; // Move to the next character after the dot
    }

    // Check if there are exactly 4 octets
    if (index != 4)
    {
        return EXACTLY_4_OCTETS;
    }

    // Class validation
    validateClass(arr);

    return 0; // You may want to return a different value here based on your logic
}

int main()
{
    // Variables require
    string ipAddress;
    cout << "Enter the ip : ";
    cin >> ipAddress;

    switch (checkValidate(ipAddress))
    {
    case STARTING_WITH_ZERO:
        cout << "Starting with zero";
        break;
    case LEADING_ZERO:
        cout << "Leading zero found";
        break;
    case CLASS_A:
    case CLASS_B:
    case CLASS_C:
        // Class validation already printed in validateClass
        break;
    case NOT_IN_RANGE:
        cout << "Not in range";
        break;
    case NOT_INTEGER:
        cout << "Not an integer";
        break;
    case LEADING_OCT:
        cout << "Leading cells found";
        break;
    case BLANK_SPACE:
        cout << "Blank space found";
        break;
    case EXACTLY_4_OCTETS:
        cout << "IP address must have exactly 4 octets";
        break;
    }

    return 0;
}
