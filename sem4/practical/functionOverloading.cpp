// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class MathOperation{
  public:
  int num1,num2;
  float num3,num4;
    float add(float a,float b) {
       return a +b ;
    }
    int add(int a,int b) {
       return a +b ;
    }
    int sub(int a,int b) {
        return a- b;
    }
    float sub(float a,float b) {
        return a- b;
    }
    int multiply(int a,int b) {
      return a * b;
    }
    float multiply(float a,float b) {
      return a * b;
    }
    int division(int a,int b) {
      return a * b;
    }
    float divison(float a,float b) {
      return a * b;
    }
    
};

int main(){
    MathOperation m1;
    cout << "---Addition---\n";
    cout << "\t" << m1.add(10,20)<<endl;
    cout << "\t" << m1.add(10.12f,20.8)<<endl;
    
    cout << "---Substraction---\n";
    cout << "\t" << m1.sub(10,20)<<endl;
    cout << "\t" << m1.sub(10.3f,20.8)<<endl;
    
    cout << "--- Multiply---\n";
    cout << "\t" << m1.multiply(10,20)<<endl;
    cout << "\t" << m1.multiply(10.3f,20.8)<<endl;
    
    cout << "--- Division---\n";
    cout << "\t" << m1.division(10,20)<<endl;
    cout << "\t" << m1.division(10.3f,20.8)<<endl;
    
    
}