// #include <iostream>
// using namespace std;

// class Parent{
//     public:
//         void virtual display(){
//             cout << "Parent\n";
//         }
// };

// class Child:public Parent{
//     public:
//         void display(){
//             cout << "Child\n";
//         }
// };

// int main(){
//     Parent *p;
//     Child c;
//     p = &c;
//     p->display();
//     return 0;
// }


// viratual function

// CPP Program to illustrate late binding.
// Any normal function call (with virtual)
// is binded late. Here we have taken base
// and derived class example so that readers
// can easily compare and see difference in
// outputs.

// #include<iostream>
// using namespace std;
	
// class Base
// {
// public:
//     // virtual is used for runtime binding
// 	void  virtual show() { cout<<" In Base \n"; }
// };
	
// class Derived: public Base
// {
// public:
// 	void show() { cout<<"In Derived \n"; }
// };
	
// int main(void)
// {
// 	Base *bp = new Derived;
//     Base *b = new Base;

// 	bp->show();
//     b->show(); 
//     // if used virtual function output will be:
//     //  In Derived
//     //  In Base

//     // if not used virtual function output will be:
//     //  In Base
//     //  In Base


// 	return 0;
// }
#include <iostream>
using namespace std;

class Complex {
    int real, imag;

public:
    Complex(int r, int i) {
        real = r;
        imag = i;
    }
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex operator+(Complex);

    void display() {
        cout << real << " + " << imag << "i\n";
    }
};

Complex Complex::operator+(Complex c) {
    Complex temp;
    temp.real = real + c.real;
    temp.imag = imag + c.imag;
    return temp;
}


int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}
