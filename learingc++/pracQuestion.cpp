
//  PRACTICAL 1.1
#include <iostream>
#include <string>
using namespace std;

// class Room
// {
// private:
//     int l, b;

// public:
//     void setData(int len, int bre)
//     {
//         l = len;
//         b = bre;
//     }
//     int area()
//     {
//         return l * b;
//     }
//     int perimeter()
//     {
//         return 2 * (l + b);
//     }
// };

// int main()
// {
//     int n, i, j, totalArea = 0, totalPeri = 0;
//     cout << "Enter the no. of rooms" << endl;
//     cin >> n;
//     Room r[n];
//     for (i = 0; i < n; i++)
//     {
//         int len, bre;
//         cout << "Enter the length and breath Room " << i + 1 << ": " << endl;
//         cin >> len >> bre;
//         r[i].setData(len, bre);
//     }
//     cout << "The Area and Perimeter of each room is: " << endl;
//     for (j = 0; j < n; j++)
//     {
//         cout << "The Area of Room " << j + 1 << ":" << r[j].area() << endl;
//         cout << "The Perimeter of Room " << j + 1 << ":" << r[j].perimeter() << endl;
//     }
//     cout << "The Total Area and Perimeter rooms is: " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         totalArea += r[i].area();
//         totalPeri += r[i].perimeter();
//     }
//     cout << "Area is : " << totalArea << endl;
//     cout << "Permimeter is : " << totalPeri;
// }
// PRACTICAL 1.2

/*
   In an academic session, Teacher wants to maintain the student info of a class like rollno,name,marks.
Average marks and topper name of the class is required to be printed at the end of session.
Write a program to help the teacher
*/
// class Teacher {
// private:
//     int rollNo;
//     string name;
//     int marks[2];
//     int avg;

// public:
//     void setData(int rollStu, string nameStu, int marksStu[]) {
//         rollNo = rollStu;
//         name = nameStu;
//         for (int i = 0; i < 2; i++) {
//             marks[i] = marksStu[i];
//         }
//     }
//     string getName() {
//         return name;
//     }
//     int getRoll() {
//         return rollNo;
//     }
//     int *getMarks() {
//         return marks;
//     }
//     double getAvg() {
//         double avg;
//         int totalMarks = 0, count = 0;
//         for (int i = 0; i < 2; i++) {
//             totalMarks = totalMarks + *(this->getMarks() + i);
//             count++;
//         }
//         avg = totalMarks / count;
//         cout << "The average marks of " << this->getName() << " is: " << avg << endl;
//         return avg;

//     }
// };

// string getTopper(Teacher str[]) {
//     string topperName;
//     for (int i = 0; i < 1; i++) {
//         if (str[i].getAvg() < str[i + 1].getAvg()) {
//             topperName = str[i + 1].getName();
//         }
//     }
//     return topperName;
// }

// int main() {
//     Teacher str[2];
//     for (int i = 0; i < 2; i++) {
//         int rollno;
//         string name;
//         int marks[2];
//         cout << "Enter the name of student: ";
//         cin >> name;
//         cout << "Enter the roll no of student: ";
//         cin >> rollno;
//         for (int j = 0; j < 2; j++) {
//             cout << "Enter the no of marks for subject " << j + 1 << ": ";
//             cin >> marks[j];
//         }
//         str[i].setData(rollno, name, marks);
//     }
//     cout << "The topper is: " << getTopper(str) << endl;
//     return 0;
// }
// Constructor and destructor

// class CreateObj
// {
// public:
//     static int count;
//     CreateObj()
//     {
//         count += 1;
//         cout << "The object " << count << " is Created" << endl;
//     }
//     ~CreateObj()
//     {
//         cout << "The object " << count << " getting destroyed" << endl;
//     }
// };

// int CreateObj::count = 0; // define and initialize static member variable

// int main()
// {
//     CreateObj obj1, obj2;
//     cout << "Total objects created: " << CreateObj::count << endl;
// }

// class Triangle
// {
//     int s, b, h;

// public:
//     Triangle()
//     {
//         s = 10, h = 10, b = 10;
//     }
//     Triangle(int side, int height, int base)
//     {
//         s = side;
//         h = height;
//         b = base;
//     }
//     inline void set(int side, int height, int base);
//     inline int area();
//     inline int perimeter();
// };

// void Triangle :: set(int side, int height, int base){
//         s = side;
//         h = height;
//         b = base;
//     }
// int Triangle :: area(){
//     return (h*b)/2;
// }
// int Triangle :: perimeter(){
//     return h+s+b;
// }

// int main(){
//     Triangle t1;
//     Triangle t2(10,20,30);
//     cout<<"Of default Area " << t1.area()<<endl;
//     cout<<"Of default Perimeter "<<t1.perimeter()<<endl;
//     cout<<"Of Arguments Area "<<t2.area()<<endl;
//      cout<<"Of Arguments Perimeter "<<t2.perimeter()<<endl;
// }

class complex{
    int real,imag;
    public:
    complex(){
        real = 0;
        imag = 0;
    }
    complex(int r,int i){
        real = r;
        imag = i;
    }
    complex add(complex c){
        complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }
    complex sub(complex c){
        complex temp;
        temp.real = real - c.real;
        temp.imag = imag - c.imag;
        return temp;
    }
    void get(){
        cout <<real<<" + "<<imag<<"i"<<endl;
    }
};
int main(){
    complex c1(20,20),c2(50,30),c3,c4;
    c3 = c1.add(c2);
    c4 = c2.sub(c1);
    cout << "Addition of real and imaginary numbers : "<<endl;
    c3.get();
    cout << "Subtraction of real and imaginary numbers : "<<endl;
    c4.get();

}


// class Circle
// {
//     int radius;

// public:
//     Circle()
//     {
//         radius = 5;
//     }
//     int get()
//     {
//         return radius;
//     }
//     int area()
//     {
//         return 3.14 * radius * radius;
//     }
//     int perimeter()
//     {
//         return 2 * 3.14 * radius;
//     }
// };

// int main()
// {
//     Circle c1;
//     cout << "Radius : " << c1.get() << endl;
//     cout << "Area : " << c1.area() << endl;
//     cout << "Perimeter : " << c1.perimeter() << endl;
// }