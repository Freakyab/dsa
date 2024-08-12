#include <iostream>
#include <limits.h>
using namespace std;

int ProductSmallestPair(int sum, int arr[], int n)
{
    int smallest = INT_MAX, secSmallest = INT_MAX;
    if (n < 2)
        return -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[smallest])
        {
            secSmallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] < secSmallest)
        {
            secSmallest = arr[i];
        }
    }

    if (smallest + secSmallest <= sum)
    {
        // cout << arr[smallest] * arr[secSmallest] << endl;
        return smallest * secSmallest;
    }
    else
    {
        return 0;
    }
    // cout<<
}

int main()
{
    int arr[] = {9, 8, 3, -7, 3, 9};
    int sum = 4;
    int n = sizeof(arr) / sizeof(int);
    int ans = ProductSmallestPair(sum, arr, n);
    cout << ans;
}