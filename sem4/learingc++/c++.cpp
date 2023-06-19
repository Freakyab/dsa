#include <iostream>
#include <string>
using namespace std;


// class carClass{
//     public :
//         int year;
//         string name;
//         int modelNo;  
// };

// int main(){
//     carClass obj;
//     cout << "Enter the no. ";       
//     cin >> obj.year;
//     cout << "Enter the name. ";       
//     cin >> obj.name;
//     cout << "Enter the modelno. ";       
//     cin >> obj.modelNo;
//     cout << obj.modelNo << " " << obj.name << " " << obj.year;
    
// }

// class car{
//     public :
//         int year;
//         int model;
//         string brand;
//         car(int x,int y, string z)
//         {
//             year = x;
//             model = y;
//             brand = z;
//         }
// };

// int main(){
//     car carFirst(1998,209,"BMW");
//     car carSecond(1991,210,"AUDI");
//     cout << carFirst.year << " " << carFirst.model << " " << carFirst.brand << endl;
//     cout << carSecond.year << " " << carSecond.model << " " << carSecond.brand << endl;
// }

// class Employee{
//     private :
//         int salary;
//     public :
//         int getSalary(){
//             return salary;
//         }
//         int setSalary(int x){
//             salary = x;
//         }
//         int addSalary(int x){
//             return salary+x;
//         }
// };
// int main(){
//     Employee obj;
//     obj.setSalary(5000);
//     cout << obj.getSalary();
//     // cout << obj.salary;
    
// }

                    // Passing object as a parameter

// class bird{
//     public :
//     string name;
//     int fly(){
//         cout << this->name << " is flying"<< endl;
//     }
//     int walking(){
//         cout << this->name << " is walking" << endl;
//     }
// };

// int main(){
//     bird obj, obj2;
//     obj.name = "parrot";
//     obj2.name = "Man";
//     obj.fly();
//     obj2.walking();
// }


// Write a program add,two,complex,write a data 

class complex{
    private : 
        float real;
        float img;
    public :
        void set(float realNum,float imgNum){
            real = realNum;
            img = imgNum;
        }
        void add(complex obj,complex obj1){
            cout << "the value is " << obj.real +obj1.real << "+" << obj.img +obj1.img << "i" <<endl;
        }
};

int main(){
    complex obj,obj1,obj2;
    obj.set(10,20);
    obj1.set(20,30);
    obj2.add(obj,obj1);
}