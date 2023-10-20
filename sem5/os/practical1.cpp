#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of process: ";
    cin >> n;
    int w[n], b[n], t[n], wt = 0, tat = 0;
    w[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time of process " << i + 1 << ": ";
        cin >> b[i];
        w[i + 1] = w[i] + b[i];
        t[i] = w[i] + b[i];
        wt += w[i];
        tat += w[i] + b[i];
        cout << "Turn around time of process " << i + 1 << ": " << t[i] << endl;
    }
    cout << "Average waiting time : " << wt / n << endl;
    cout << "Average turn around time : " << tat / n << endl;
}