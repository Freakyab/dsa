//  Excerise 1
// #include <iostream>
// #include <string>
// using namespace std;

// class Rectangle
// {
//     int len, bre;

// public:
//     Rectangle() { len = 0, bre = 0; }
//     Rectangle(int l, int b) { len = l, bre = b; }
//     double area() {return len * bre;}
// };

// class Square : public Rectangle {
//     int side;
//     public :
//     Square (int s) : Rectangle(s,s ) {side  = s ;}
// };

// int main(){
//     Rectangle r1(20,30);
//     Square c1(10);

//     cout << r1.area() << endl;
//     cout << c1.area() << endl;

// }

// Excerise 2

// #include <iostream>
// #include <string>
// using namespace std;

// class Member
// {
//     private: 
//     string name, address;
//     int age, phoneNo;
//     double salary;

// public:
//     Member printSalary()
//     {
//         cout << salary;
//     }
//     Member(int _age, int _phoneNo, double _salary, string _name, string _address)
//     {
//         age = _age;
//         phoneNo = _phoneNo;
//         salary = _salary;
//         name = _name;
//         address = _address;
//     }
// };

// class Manager : public Member
// {
// private:
//     string department;
// public: 
//     Manager(int _age, int _phoneNo, double _salary, string _name, string _address, string _department)
//         : Member(_age, _phoneNo, _salary, _name, _address)
//     {
//         department = _department;
//     }


// };

// class Employee : public Member {
//     private :
//         string specialization;
//     public:
//         Employee (int _age, int _phoneNo, double _salary, string _name, string _address, string _specialization ) : Member (_age, _phoneNo, _salary, _name, _address){
//             specialization = _specialization;
//         }
// };

// int main() {
//     // Create an Employee object
//     Employee emp (30 ,123,500000,"John Doe", "123 Street, City","Software Engineering");

//     // Create a Manager object
//     Manager mgr(40,432,700000,"martian","home","Human Resources");

//     // Print employee details
   
//     emp.printSalary();

//     // Print manager details
//    cout << endl;
//     mgr.printSalary();

//     return 0;
// }


#include <iostream>
using namespace std;

class Shape {
    public: 
    virtual double calculateArea () const = 0;
};

class TwoDimensionalShape : public Shape{
    public: 
    virtual double calculatePerimeter () const = 0;
        
};

class ThreeDimensionalShape : public Shape{
    public: 
    virtual double calculateVolume () {return 0; };
};

class Circle : public TwoDimensionalShape{
    double side;
    public:
        Circle(double side) {this->side = side; }
        double calculatePerimeter () const override{
            return 2 * 3.14 * side;
        }
        double calculateArea () const override{
            return 3.14 * side * side ;
        }
};


class Sphere : public ThreeDimensionalShape{
    double rad;
    public :
        Sphere(int rad) {this->rad = rad;}
        double calculateVolume()  override {
            return (4/3) * 3.14 * (rad* rad*rad ); 
        };
        double calculateArea() const override {
            return 4 * 3.14 * rad * rad ;
        }
};


int main() {
    // Create a Circle object
    Circle circle(5.0);

    // Create a Sphere object
    Sphere sphere(2.0);

    // Calculate and display area and perimeter of the circle
    cout << "Circle:" << endl;
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;

    // Calculate and display area and volume of the sphere
    cout << "\nSphere:" << endl;
    cout << "Surface Area: " << sphere.calculateArea() << endl;
    cout << "Volume: " << sphere.calculateVolume() << endl;

    return 0;
}