#include <iostream>
using namespace std;

class Shape{
    public:
    virtual float Area() = 0;
    virtual float Peri() = 0;
};

class Triangle : public Shape{
    float b , h;
     public:
        Triangle(float b,float h) {
            this->b = b;
            this->h = h; 
        }
        float Area () {
            return 0.5 * b * h;
        }
        float Peri (){ return 3 * b;}
};
class Square : public Shape{
    float side;
    public:
        Square(float side) {
            this->side = side;
        }
        float Area () {
            return side * side;
        }
        float Peri (){ return 4 * side;}
};

int main (){
    Shape *ptr;
    Triangle t (6,8);
    Square s (6);

    ptr = &t;

    cout << "\t----Triangle----\n";
    cout << "Triangle Area : " << ptr->Area() <<endl;
    cout << "Triangle Perimeter : " << ptr->Peri() <<endl;
    
    ptr = &s;
    cout << "\t----Square------\n";
    cout << "Square Area : " << ptr->Area() <<endl;
    cout << "Square Perimeter : " << ptr->Peri() <<endl;


}