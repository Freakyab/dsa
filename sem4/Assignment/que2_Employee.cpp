#include <iostream>
#include <string>

using namespace std;

class Employee{
    protected:
        string name;
        int employeeID;
        float salary;
    public:
        Employee(string name,int employeeID,float salary){
            this->employeeID = employeeID;
            this->name = name;
            this->salary = salary;
        }

        void displayDetails(){
            cout << "Details are: " <<endl;
            cout << "\t employeeID: " << employeeID <<endl;
            cout << "\t name: " << name <<endl;
            cout << "\t salary: " << salary <<endl;   
        }
};

class Manager: public Employee {
    string jobType;
    public:
        Manager(string name,int employeeID,float salary,string jobType):Employee(name,employeeID,salary){
            this->name = name;
            this->employeeID =employeeID;
            this->jobType = jobType;
            this->salary = salary;
        }
        void displayDetails() {
        cout << "-- Manager Details --" << endl;
        Employee::displayDetails();
        cout << "\t Job : " << jobType << endl;
        cout << endl;
    }
        
};  
class Engineer: public Employee {
    string jobType;
    public:
        Engineer(string name,int employeeID,float salary,string jobType):Employee(name,employeeID,salary){
            this->name = name;
            this->employeeID =employeeID;
            this->jobType = jobType;
            this->salary = salary;
        }
        void displayDetails() {
        cout << "-- Engineer Details --" << endl;
        Employee::displayDetails();
        cout << "\t Job : " << jobType << endl;
        cout << endl;
    }
        
};  
class Technician: public Employee {
    string jobType;
    public:
        Technician(string name,int employeeID,float salary,string jobType):Employee(name,employeeID,salary){
            this->name = name;
            this->employeeID =employeeID;
            this->jobType = jobType;
            this->salary = salary;
        }
        void displayDetails() {
        cout << "-- Technician Details --" << endl;
        Employee::displayDetails();
        cout << "\t Job : " << jobType << endl;
        cout << endl;
    }
        
};  


int main() {
    Manager manager("John Smith", 1001, 5000.0, "Manager");
    Engineer engineer("Jane Doe", 1002, 4000.0, "Engineer");
    Technician technician("Mike Johnson", 1003, 3000.0, "Technician");

    manager.displayDetails();
    engineer.displayDetails();
    technician.displayDetails();

    return 0;
}