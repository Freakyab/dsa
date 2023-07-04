#include <iostream>
using namespace std;

int main(){
    int divid ,div;
    cout << "Enter the dividend: ";
    cin>>divid;

    cout << "Enter divisor: " ;
    cin >> div;

    try{
        if(div != 0){
            cout << "Answer : "<< divid/div << endl;
        }
        else{
            throw(div);
        }
    }
    catch(int div){
        cout << "Zero division error";
    }
}