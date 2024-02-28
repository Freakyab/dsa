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

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    printArray(L, n1);
    cout << endl;
    printArray(R, n2);
    cout << endl;
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    printArray(L, n1);
    cout << endl;
    printArray(R, n2);
    cout << endl;
}

void mergeSort(int arr[], int left, int right)
{
    static int pass = 1;
    cout << "Pass: " << pass << endl;
    cout << "Left: " << left << " "
         << "Right : " << right << " ";
    pass = pass + 1;

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        cout  << "Mid: "<< mid <<endl;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {3, 5, 1};

    mergeSort(arr, 0, 3-1);
    printArray(arr, 3);
}