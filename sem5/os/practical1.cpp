#include <iostream>
using namespace std;

int FCFS (int n){
    int w[n] ,b[n] ,t[n], wt = 0, tat =0;
    w[0] = 0;
    
    for(int i =0; i< n; i++){
        cout << "Enter the burst time of Process " << i+1 << ": ";
        cin >> b[i];
        t[i] = w[i+1] = w[i] +b [i];
        wt += w[i];
        tat += w[i] + b[i];
    }

    for(int i =0; i< n; i++){
        cout << "Turn around time of Process " << i+1 << ": " << t[i] << endl;
    }

    cout << "Average waiting time : " << wt/n << endl;
    cout << "Average turn around time : " << tat/n << endl;

}

int main ()
{
    int n ;
    cout << "Enter the no. of process: ";
    cin >> n;

    FCFS(n);
    return 0;
}