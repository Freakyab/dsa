#include <iostream>
#include <cmath>
using namespace std;

int differenceofSum(int n, int m)
{
    int nCount = 0, mCount = 0;
    for (int i = 0; i <= m; i++)
    {
        if (i % n == 0)
        {
            nCount += i;
        }
        else
        {
            mCount += i;
        }
    }
    cout<< abs(nCount - mCount);
}

int main()
{
    // differenceofSum(4, 20);
    differenceofSum(3,10);
}