// #include <iostream>
// using namespace std;

// int queueSize= 11;
// int mutex = 1;
// int full = 0;
// int empty = 11;
// int itemProduced = 0;

// void producer() {
//     // Locking
//     mutex--;
//     if(full == queueSize) {
//         cout << "Queue is full" << endl;
//         return;
//     }
//     else{
//         itemProduced++;
//         full++;
//         empty--;
//         cout << "Producer produces the item " << itemProduced << endl;
//     }

//     // Unlocking
//     mutex++;
// }

// void consumer() {
//     // Locking
//     mutex--;
//     if(full <= 0) {
//         cout << "Queue is empty" << endl;
//         return;
//     }
//     else{
//         full--;
//         empty++;
//         cout << "Consumer consumes the item " << itemProduced << endl;
//     }

//     // Unlocking
//     mutex++;
// }

// int main() {
//     int choice;
//     while(true) {
//         cout << "1. Producer" << endl;
//         cout << "2. Consumer" << endl;
//         cout << "3. Exit" << endl;
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch(choice) {
//             case 1:
//                 if(mutex == 1 && empty != 0) {
//                     producer();
//                 }
//                 else{
//                     cout << "Producer is waiting" << endl;
//                 }
//                 break;
//             case 2:
//                 if(mutex == 1 && full != 0) {
//                     consumer();
//                 }
//                 else{
//                     cout << "Consumer is waiting" << endl;
//                 }
//                 break;
//             case 3:
//                 exit(0);
//                 break;
//             default:
//                 cout << "Invalid choice" << endl;
//         }
//     }
// }

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