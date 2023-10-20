#include <iostream>
using namespace std;

class Shape{
    public:
    virtual float Area() = 0;
    virtual float Peri() = 0;
};

class Rectangle : public Shape{
    float len , bre;
    public:
        Rectangle(float len,float bre) {
            this->len = len;
            this->bre = bre; 
        }
        float Area () {
            return len * bre;
        }
        float Peri (){ return 2*(len+bre);}
};
class Circle : public Shape{
    float side;
    public:
        Circle(float side) {
            this->side = side;
        }
        float Area () {
            return 3.14 * side * side;
        }
        float Peri (){ return 2*3.14 * side;}
};

int main (){
    Shape *ptr;
    ptr = new Rectangle(4.0f,5.0f);
    cout << "\t----Rectangle----\n";
    cout << "Rectangle Area : " << ptr->Area() <<endl;
    cout << "Rectangle Perimeter : " << ptr->Peri() <<endl;
    
    delete ptr;
    ptr = new Circle(3.0f);
    cout << "\t----Circle------\n";
    cout << "Circle Area : " << ptr->Area() <<endl;
    cout << "Circle Perimeter : " << ptr->Peri() <<endl;

    delete ptr;
    // Shape *ptr;

    // Rectangle r (4.0f,5.0f);
    // Circle c (3.0f);

    // ptr = &r;
    // cout << "\t----Rectangle----\n";
    // cout << "Rectangle Area : " << ptr->Area() <<endl;
    // cout << "Rectangle Perimeter : " << ptr->Peri() <<endl;

    // ptr = &c;
    // cout << "\t----Circle------\n";
    // cout << "Circle Area : " << ptr->Area() <<endl;
    // cout << "Circle Perimeter : " << ptr->Peri() <<endl;


}