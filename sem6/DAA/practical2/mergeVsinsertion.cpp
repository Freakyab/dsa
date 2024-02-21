#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

#define MAX 10000

using namespace std;

// Function to generate random numbers and write them to a file
void writeThefile(string file, int n)
{
    // Seed for random number generation
    srand(time(0));

    // Open the file for writing
    ofstream myFile(file);

    // Check if the file is opened successfully
    if (!myFile.is_open())
    {
        cout << "Error is opening file";
        return;
    }

    // Generate a4nd write random numbers to the file
    for (int i = 0; i < n; i++)
    {
        myFile << rand() % MAX << "\n";
    }

    // Close the file
    myFile.close();
}

// Function to read numbers from a file into an array
int readThefile(string file, int arr[])
{
    // Open the file for reading
    ifstream myFile(file);

    // Variables for reading from the file
    int i = 0, j = 0;

    // Check if the file is opened successfully
    if (!myFile.is_open())
    {
        cerr << "Error opening file: " << file << endl;
        return 0;
    }

    // Read numbers from the file into the array
    while (myFile >> i)
    {
        arr[j] = i;
        j++;
    }

    // Close the file
    myFile.close();
}

// Function to print the content of an array
int printArray(int arr[], int n)
{
    cout << "\t";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to swap two elements
int swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

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

int updateFile(int arr[], string file, int n)
{
    // Open the file for writing
    ofstream outputFile(file);

    // Check if the file is opened successfully
    if (outputFile.is_open())
    {
        // Write the content of the array to the file
        for (int i = 0; i < n; i++)
        {
            outputFile << arr[i] << "\n";
        }

        // Notify that the array is saved to the file
        cout << "Sorted array saved to: " << file << endl;

        // Close the file
        outputFile.close();
    }
}

int main()
{
    // Number of random numbers to be generated
    int n = 20000;

    cout << "Merge sort\t v/s Insertion sort \n";
    
    // Loop to test different array sizes
    while (n >= 20000 & n <= 200000)
    {
        int arr[n];

        string randomNumberFile = "unsorted.txt";
        // string sortedFile = "Bubblesorted.txt";

        // Generate random numbers and write them to the file
        writeThefile(randomNumberFile, n);

        // Read the file into the array and print the original array
        readThefile(randomNumberFile, arr);

        // Perform Bubble Sort on the array
        clock_t start_b, end_b;
        float total_b;

        start_b = clock();
        mergeSort(arr, 0, n - 1);
        end_b = clock();
        total_b = ((float)(end_b - start_b)) / CLOCKS_PER_SEC;
        cout << "N - " << n << ": " << setprecision(10) << total_b  << ": M \t";

        // Update the file with the sorted array
        writeThefile(randomNumberFile, n);
        readThefile(randomNumberFile, arr);

        // Perform Selection Sort on the array
        clock_t start_s, end_s;
        float total_s;

        start_s = clock();
        insertionSort(arr, n);
        end_s = clock();
        total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
        
        cout << "N - " << n << ": " << setprecision(10) << total_s << ": I\n";

        // Increase the size of the array for the next iteration
        n = n + 20000;
    }
}
