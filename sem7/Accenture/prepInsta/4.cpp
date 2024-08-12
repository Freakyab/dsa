#include <iostream>
using namespace std;

int findCount(int arr[], int length, int num, int diff)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        int val = arr[i] - num >= 0 ? arr[i] - num : num - arr[i];
        if (val <= diff)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {12, 3, 14, 56, 77, 13};
    int num = 13, diff = 2;
    int n = sizeof(arr) / sizeof(int);
    cout << findCount(arr, n, num, diff);
}