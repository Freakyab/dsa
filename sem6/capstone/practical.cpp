#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int RandomNoGenerator()
{
    srand(time(0));
    return rand() % 6;
}

int GuessTheNo()
{
    srand(time(0));
    int secretNo = rand() % 100 + 1;
    int guessNo, attempt = 0;
    while (attempt < 5)
    {
        cout << "Enter the first guess: ";
        cin >> guessNo;
        if (guessNo == secretNo)
        {
            cout << "You guessed it correctly\n";
            break;
        }
        else if (guessNo < secretNo)
        {
            cout << "Guessed no is less than actual no\n";
        }
        else if (guessNo > secretNo)
        {
            cout << "Guessed no is more than actual no\n";
        }
        attempt++;
    }
    cout << "The correct no is : " << secretNo << endl;
}

void RandomPasswordGenerator()
{
    string allSet = "1234567890QWERTYUIOPLKJHGFDSAZXCVBNM";
    string password = "";
    for (int i = 0; i < 10; i++)
    {
        password += allSet[rand() % allSet.size()];
    }
    cout << "The suggested password is: ";
    cout << password;
}
int main()
{
    // cout << "The rolled no. is: ";
    // cout << RandomNoGenerator();
    // GuessTheNo();
    RandomPasswordGenerator();
}