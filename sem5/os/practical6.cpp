#include <iostream>

using namespace std;

struct Memory {
    int a, b, c;
};

Memory allocation_[5];
Memory max_[5];
Memory avail_;
Memory need[5];

int main () {
    for(int i =0 ; i< 5; i++){
        cout << "Enter the require Allocation for process " << i+1 << ": ";
        cin >> allocation_[i].a >> allocation_[i].b >> allocation_[i].c;

        cout << "Enter the Max allocation for process "<< i+1 << ": ";
        cin >> max_[i].a >> max_[i].b >> max_[i].c;
    }

    cout << "Enter the available memory: " ;
    cin >> avail_.a >> avail_.b >>avail_.c;

    for(int i =0; i< 5;i++){
        need[i].a = max_[i].a - allocation_[i].a;
        need[i].b = max_[i].b - allocation_[i].b;
        need[i].c = max_[i].c - allocation_[i].c;
    }

    int i =0 ,done = 0;
    while(done <= 5){
        if(need[i].a <= avail_.a && need[i].b <= avail_.b && need[i].c <= avail_.c){
            avail_.a += allocation_[i].a;
            avail_.b += allocation_[i].b;
            avail_.c += allocation_[i].c;
            done++;
            cout << "\tProcess " << i + 1 << "\n is executed" << endl;
        }else{
            cout << "\tProcess " << i + 1 << "\n is can't executed" << endl;
        }

        i = (i+1) % 5;
     }
}
