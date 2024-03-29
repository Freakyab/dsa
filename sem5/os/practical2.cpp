#include <iostream>
using namespace std;

int RoundRobin(int n){
    int b[n] , biggestRound = 0, time ;
    cout << "Enter the time slot: " ;
    cin >> time;
    
    for(int i =0; i <n;i++){
        cout << "Enter the burst time of process " << i+1 << ": ";
        cin >> b[i];

        biggestRound = b[i] > biggestRound ? b[i] : biggestRound;
    }

    for(int i =0; i< biggestRound/time ;i++){
        cout << "Round no " << i+1 << ": " << endl;
       for(int j =0; j< n ;j++){
        int timeRemaining = b[j] - (i+1)*(time) > 0 ? b[j] - (i+1)*(time) : 0;
        cout << "process " << j+1 << " waiting time : " << timeRemaining << endl;
       }
    }
    return 0;
}

int main(){
    int n ;
    cout << "Enter the no. of process: ";
    cin >> n;

    RoundRobin(n);
}