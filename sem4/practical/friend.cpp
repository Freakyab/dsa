#include <iostream>
#include <string>

using namespace std;

class Employee{
    int id;
    string name;
    int salary;
    public:
        Employee(int i,string n,int s){
            id = i;
            name = n;
            salary = s;
        }
        void getEmployee(){
            cout << "EmployeeID: "<<id <<"; Employee Name: " << name;
        }
        friend int taxCalc(Employee &);
};

int taxCalc(Employee &e){
    float tax = 0;
    if(e.salary <= 300000){ tax = 0; }
    else if(e.salary > 300000 & e.salary <= 600000){tax = (e.salary - 300000)*0.65;}
    else if(e.salary > 600000) {
        tax = 12500 + (e.salary - 600000) * 0.2;
    }
    return tax;
}

int main(){
    Employee e1(1,"Rahul",300000);
    Employee e2(1,"Rohit",400000);
    Employee e3(1,"Raj",700000);

    e1.getEmployee();
    cout << "Tax: "<<taxCalc(e1) <<endl;
    e2.getEmployee();
    cout << "Tax: "<<taxCalc(e2) <<endl;
    e3.getEmployee();
    cout << "Tax: "<<taxCalc(e3) <<endl;

}