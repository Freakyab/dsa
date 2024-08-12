#include <iostream>
using namespace std;

int LargeSmallSum(int arr[], int n)
{

    int Largest = 0, SecondLargest = 0;
    for (int i = 0; i < n; i = i + 2)
    {
        if (arr[i] > arr[Largest])
        {
            SecondLargest = Largest;
            Largest = i;
        }
        else if (arr[i] < arr[Largest] && arr[i] > arr[SecondLargest])
        {
            SecondLargest = i;
        }
    }
    int Smallest = Largest, SecondSmallest = Largest;
    for (int i = 1; i < n; i = i + 2)
    {
        if (arr[i] < arr[Smallest])
        {
            SecondSmallest = Smallest;
            Smallest = i;
        }
        else if (arr[i] > arr[Smallest] && arr[i] < arr[SecondSmallest])
        {
            SecondSmallest = i;
        }
    }
    cout << arr[SecondLargest] + arr[SecondSmallest];
}

int main()
{
    int arr[] = {1, 8, 0, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(int);
    LargeSmallSum(arr, n);
}