#include <bits/stdc++.h>

using namespace std;

int printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
            swap(arr[i], arr[minIndex]);
        }
    }
}

int merge(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + j + 1];

    int i = 0, j = 0, k = l;

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
        k++, i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

int mergeSort(int left, int right, int arr[])
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(left, mid, arr);
        mergeSort(mid + 1, right, arr);
        merge(arr, left, mid, right);
    }
}

int insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j -= 1;
        }

        arr[j + 1] = key;
    }
}

int WTF(string file, int n)
{
    ofstream myFile(file);
    if (!myFile.is_open())
    {
        cout << "error";
        return 0;
    }
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        myFile << rand() % 1000 << "\n";
    }
}

int RTF(string file, int arr[])
{
    ifstream myFile(file);

    int i, j = 0;

    while (myFile >> i)
    {
        arr[j] = i;
        j++;
    }
}

int main()
{
    // int n = 5000;
    // while (n >= 5000 && n <= 50000)
    // {
    //     int arr[n];
    //     string file = "UNsorted.txt";

    //     clock_t start, end;
    //     float total;

    //     WTF(file, n);
    //     RTF(file, arr);

    //     start = clock();
    //     bubbleSort(arr, n);
    //     end = clock();

    //     total = (float)end - start / CLOCKS_PER_SEC;

    //     cout << setprecision(10) << total << "\t";
    //     WTF(file, n);
    //     RTF(file, arr);

    //     start = clock();
    //     selectionSort(arr, n);
    //     end = clock();

    //     total = (float)end - start / CLOCKS_PER_SEC;

    //     cout << setprecision(10) << total << "\t";
    //     n += 500;
    //     cout << endl;
    // }
    int n = 5;
    int arr[n] = {0, 99, 88, 77, 12};
    insertion(arr, n);
    printArray(arr, n);
}