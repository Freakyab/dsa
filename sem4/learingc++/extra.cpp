#include <iostream>

using namespace std;

class Convert
{
    float feet, inch;

public:
    Convert()
    {
        feet = 0;
        inch = 0;
    }
    float getInch()
    {
        return feet * 12;
    }
    void setInch(float i)
    {
        inch = i;
    }
    float getFeet()
    {
        return inch / 12;
    }
    void setFeet(float f)
    {
        feet = f;
    }
    Convert add(Convert c)
    {
        Convert temp;
        temp.feet = feet + c.feet;
        temp.inch = inch + c.inch;
        return temp;
    }
    void get()
    {
        cout << "Total distance covered :\n"
             << "Feet: " << feet << endl
             << "Inch: " << inch;
    }
};

int main()
{
    Convert obj[3];
    float f, j;
    for (int i = 0; i < 2; i++)
    {
        int act;
        cout << "Enter the type to Convertlate the distance" << endl
             << "1.Feet\n2.Inch\nEnter the no:";
        cin >> act;
        if (act == 1)
        {
            cout << "Enter the value " << i + 1 << ": ";
            cin >> f;
            obj[i].setFeet(f);
            j = obj[i].getInch();
            obj[i].setInch(j);
            cout << endl;
        }
        else if (act == 2)
        {
            cout << "Enter the value " << i + 1 << ": ";
            cin >> j;
            obj[i].setInch(j);
            f = obj[i].getFeet();
            obj[i].setFeet(f);
            cout << endl;
        }
        else
        {
            return 0;
        }
    }
    obj[2] = obj[0].add(obj[1]);
    obj[2].get();
}