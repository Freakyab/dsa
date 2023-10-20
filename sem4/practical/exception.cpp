#include <iostream>
using namespace std;

class ZeroDivision {
    public:
    void error(){
        cout << "This is an ZerDivisionError" <<endl;
    }
};

class Divide{
    int n1,n2;
    public:
    Divide(int a,int b) {n1 = a,n2 =b ;}
    int div(){
        if(n2==0){
            ZeroDivision err;
            throw err;
        }
        else{
            return n1/n2;
        }
    }
};

int main(){
    Divide d1(10,0);
    try{
        d1.div();
    }
    catch(ZeroDivision err){
        err.error();
    }
}

