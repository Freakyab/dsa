#include <iostream>

using namespace std;

// Function to print the content of an array
void printArray(int arr[], int n)
{
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Function to print element in red color
void printRed(int element)
{
    cout << "\033[1;31m" << element << "\033[0m";
}

// Function to print element in blue color
void printBlue(int element)
{
    cout << "\033[1;34m" << element << "\033[0m";
}

// Function to print element in green color
void printGreen(int element)
{
    cout << "\033[1;32m" << element << "\033[0m";
}

void printColorArray(int arr[], int n, int pivot)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == pivot)
        {
            printRed(arr[i]);
        }
        else
        {
            cout << arr[i];
        }
        cout << " ";
    }
    cout << endl;
}

void printSingleColorArray(int arr[], int n, int l, int h)
{
    for (int i = 0; i < n; i++)
    {
        if (i >= l && i <= h)
            printBlue(arr[i]);
        else
            cout << arr[i];
        cout << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    cout << "\033[1;31mPivot :\033[0m ";
    printRed(pivot);
    cout << endl;
    cout << "Range is: " << endl;
    printSingleColorArray(arr, n, low, high);
    printColorArray(arr, n, pivot);

    int i = low - 1;

    cout << "\033[1;32mI is: " << i << "\033[0m" << endl;
    for (int j = low; j < high; j++)
    {
        cout << "\033[1;34mJ is: " << j << "\033[0m" << endl;
        if (arr[j] <= pivot)
        {
            i++;

            swap(arr[i], arr[j]);
            cout << "\033[1;31mInner Swap : \033[0m";
            printColorArray(arr, n, arr[j]);
        }
    }
    cout << "\033[1;31mOuter Swap : \033[0m";
    swap(arr[i + 1], arr[high]);
    printColorArray(arr, n, pivot);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n)
{
    cout << "Low : " << low << " High: " << high << endl;

    if (low < high)
    {
        cout << "Condition accepted \n";
        int pivot = partition(arr, low, high, n);
        cout << "Second Quicksort" << endl;
        quickSort(arr, low, pivot - 1, n);
        cout << "Third Quicksort" << endl;
        quickSort(arr, pivot + 1, high, n);
    }
}

int main()
{
    int arr[] = {10, 90, 70, 80, 60, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, n);
    quickSort(arr, 0, n - 1, n);
    printArray(arr, n);
}
