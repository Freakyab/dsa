#include <iostream>

using namespace std;

int printArray(int arr[], int n)
{
    // cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printColorArray(int arr[], int n, int left, int right, int largest)
{
    cout << "\033[1;31mRed is for left value.\033[0m"
         << " && "
         << "\033[1;32mgreen is for right value.\033[0m"
         << " && "
         << "\033[1;34mLargest is blue.\033[0m" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i == left)
        {
            cout << "\033[1;31m" << arr[i] << "\033[0m"
                 << " ";
        }
        else if (i == right)
        {
            cout << "\033[1;32m" << arr[i] << "\033[0m"
                 << " ";
        }
        else if (i == largest)
        {
            cout << "\033[1;34m" << arr[i] << "\033[0m"
                 << " ";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    cout << "Array : ";
    printArray(arr, n);
    cout << "i: " << i << endl;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    cout << "largest: " << largest << "\t";
    cout << "left: " << left << "\t";
    cout << "right: " << right << endl;
    printColorArray(arr, 6, left, right, largest);

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    cout << "largest value :" << largest<<endl;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
        cout << "After swapping\n";
        printArray(arr, n);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {3, 5, 1, 10, 20, 4};

    heapSort(arr, 6);
    // printArray(arr, 3);
}