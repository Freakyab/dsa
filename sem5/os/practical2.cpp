#include <iostream>
using namespace std;

int main()
{
    int n, time;
    cout << "Enter the no. of process: ";
    cin >> n;
    cout << "Enter the time slot: ";
    cin >> time;
    int b[n], rounds = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> b[i];
        rounds = b[i] > rounds ? b[i] : rounds;
    }
    for (int k = 0; k <= rounds / time; k++)
    {
        cout << "Round " << k + 1 << ": " <<endl;
        for (int i = 0; i <n; i++)
        {
            int timeRemaining = b[i] - (k+1)*(time) > 0 ? b[i] - (k+1)*(time) : 0;
            cout << "process " << i + 1 << " waiting time : " << timeRemaining   << endl;
        }
        
    }
}