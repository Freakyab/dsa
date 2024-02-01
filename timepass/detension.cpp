#include <iostream>
#include <string>
using namespace std;
// 1. WAP to print the area of a rec by creating a class named Area having two methods first method named as setDim takes
//  len and bre of rec as parameter and the second mwthod as getARea returns the area of the rectangle. length and bre of
//  rectangle are entered by keyword
/*

class Area{
    double len,bre;
    public:
        Area(){
            len = 0, bre =0 ;
        }

        void getDim(double len,double bre){
            this->len =len;
            this->bre = bre;
        }
        double getArea(){
            return len * bre;
        }
};

int main(){
    double len,bre;
    Area a1;
    cout << "Enter the length of rectangle: ";
    cin >> len;
    cout << "Enter the bre of rectangle: ";
    cin >> bre;
    a1.getDim(len,bre);
    cout << "The area is : " << a1.getArea();

}
*/
// 2. WAP to print area and perimeter of triangle by creating a class named 'triangle' without any parameter in its constructor;
/*
class Triangle {
    int s,l,h;
    public:
        Triangle(){
            s =10,l = 10,h =10;
        }
        int area(){ return 0.5 * s * h;}
        int peri() {return s* l*h ;}
};

int main(){
    Triangle t1;
    cout << "Area of triangle" << t1.area();
    cout << "Area of triangle" << t1.peri();
}
*/

// 3.
/*
class TimeCalculator
{
    int hr, sec, min;

public:
    void getTime(int hr, int min, int sec)
    {
        if (sec > 60)
        {
            sec = sec % 60;
            int newMin = sec / 6;
            min = min + newMin;
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        if (min > 60)
        {
            int newHr = min / 60;
            int newMin = min % 60;

            hr += newHr;
            min = newMin ;
            // cout << newHr << " hr" << "\n";
            // cout << hr << "\n";
            // cout << sec << "\n";
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        else
        {
            this->hr = hr;
            this->min = min;
            this->sec = sec;
        }
        // cout << "Time is : " << this->hr << "hr " << this->min << "min " << this->sec << "sec " <<endl;
    }
    void readTime()
    {
        cout << "Time is : " << this->hr << "hr " << this->min << "min " << this->sec << "sec ";
    }
    TimeCalculator addTime(TimeCalculator &a)
    {
        TimeCalculator temp;
        int min_ = this->min + a.min;
        int hr_ = this->hr + a.hr;
        int sec_ = this->sec + a.sec;
        temp.getTime(hr_, min_, sec_);
        temp.readTime();
    }
};

int main()
{
    TimeCalculator t, t1;
    t.getTime(10, 2, 12);
    t1.getTime(10, 12, 18);
    t1.addTime(t);
}

*/

// 4.

class Teacher {
private:
    int rollNo;
    string name;
    int marks[2];
    int avg;

public:
    void setData(int rollStu, string nameStu, int marksStu[]) {
        rollNo = rollStu;
        name = nameStu;
        for (int i = 0; i < 2; i++) {
            marks[i] = marksStu[i];
        }
    }
    string getName() {
        return name;
    }
    int getRoll() {
        return rollNo;
    }
    int *getMarks() {
        return marks;
    }
    double getAvg() {
        double avg;
        int totalMarks = 0, count = 0;
        for (int i = 0; i < 2; i++) {
            totalMarks = totalMarks + *(this->getMarks() + i);
            count++;
        }
        avg = totalMarks / count;
        cout << "The average marks of " << this->getName() << " is: " << avg << endl;
        return avg;

    }
};

string getTopper(Teacher str[]) {
    string topperName;
    for (int i = 0; i < 1; i++) {
        if (str[i].getAvg() < str[i + 1].getAvg()) {
            topperName = str[i + 1].getName();
        }
    }
    return topperName;
}

int main() {
    Teacher str[2];
    for (int i = 0; i < 2; i++) {
        int rollno;
        string name;
        int marks[2];
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the roll no of student: ";
        cin >> rollno;
        for (int j = 0; j < 2; j++) {
            cout << "Enter the no of marks for subject " << j + 1 << ": ";
            cin >> marks[j];
        }
        str[i].setData(rollno, name, marks);
    }
    cout << "The topper is: " << getTopper(str) << endl;
    return 0;
}


// 5.
/*
class Average
{
    float n1, n2, n3;

public:
    Average(float n1, float n2, float n3) { this->n1 = n1, this->n2 = n2, this->n3 = n3;}
    double getAverage()
    {
        return (n1 + n2 + n3) / 3;
    }
};
int main()
{
    Average avg(10.0f, 20.00, 30.0);
    cout << avg.getAverage();
}
*/

// 6.

// class Complex{
//     int real ,img;
//     public :
//         Complex operator+ (Complex &a){

//         }
// }


#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{

    char str[]="{()}";

    printf("%c\n",str[0]);
    int newarr[100];

    char symbols[] = {'(',')','{','}','[',']'};
    for (int i = 0; i < 6; i++)
    {
        
        printf("%c: ",symbols[i]);
        printf("%d\n",symbols[i]);
        newarr[i] = int(symbols[i]);
        printf("%d\n",newarr[i]);
    }
    return 0;
}