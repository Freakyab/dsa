#include <iostream>
using namespace std;

int getTotal(int r, int unit, int n, int arr[])
{
    int count = 0;
    if (n == 0)
        return -1;
    for (int i = 0; i < n; i++)
    {
        count += arr[i];
        if (count >= (r * unit))
            return i + 1;
    }
    return -1;
}

int main()
{
    int r = 7, unit = 2, n = 8;
    int arr[] = {2, 8, 3, 5, 7, 4, 1, 2};
    int count = getTotal(r, unit, n, arr);
    cout<<count;
    return 0;
}