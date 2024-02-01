
#include <iostream>
using namespace std;

int queueSize = 3;
int full = 0;
int empty = 3;
int itemProduced = 0;
int mutex = 1;

int Producer()
{

    // Locking
    mutex--;

    if (full == queueSize)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        full++;
        empty--;
        itemProduced++;
        cout << "Producer has produce item " << itemProduced << endl;
    }
    mutex++;
}

void Consumer()
{
    // Locking

    mutex--;
    if (full <= 0)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        full--;
        empty++;
        cout << "Consumer has consume" << itemProduced << endl;
    }

    mutex++;
}

int main()
{
    int choice;
    while (true)
    {
        cout << "1.Procuder\n2.Consumer\n3.Exit\nEnter the choice: ";
        cin >> choice;

        if (choice == 1)
        {
            if (mutex == 1 && empty != 0)
            {
                Producer();
            }else{
                cout << "Producer is waiting" << endl;
            }
        }
        else if (choice == 2)
        {
            if (mutex == 1 && full != 0)
            {
                Consumer();
            }
            else
            {
                cout << "Consumer is waiting" << endl;
            }
        }
        else
        {
            break;
        }
    }
}