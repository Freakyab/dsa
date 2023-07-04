#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inch;

public:
    Distance()
    {
        feet = 0;
        inch = 0;
    }
    Distance(int f, int i)
    {
        feet = f;
        inch = i;
        if (inch >= 12)
        {
            feet += inch / 12;
            inch %= 12;
        }
    }
    Distance(const Distance &obj)
    {
        feet = obj.feet;
        inch = obj.inch;
    }

    int Display()
    {
        cout << "feet: " << feet << " inch: " << inch <<endl;
    }

    Distance operator+(Distance b)
    {
        feet = feet + b.feet;
        inch = inch + b.inch;

        Distance o(feet, inch);

        return o;
    }

    Distance operator-(Distance b)
    {
        feet = feet - b.feet;
        inch = inch - b.inch;

        Distance o(feet, inch);

        return o;
    }
};

int main()
{
    Distance a(20, 10), b(15, 4), d, c(50, 7);
    d = a + b;
    cout << "---Addition: ";
    d.Display();
    cout << "---Substraction: ";
    Distance e(c - d);
    e.Display();
    return 0;
}