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

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
     
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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

    cout << "Quick sort\t v/s Heap sort \n";
    
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
        quickSort(arr, 0, n - 1);
        end_b = clock();
        total_b = ((float)(end_b - start_b)) / CLOCKS_PER_SEC;
        cout << "N - " << n << ": " << setprecision(10) << total_b  << ": Q\t";
        cout << setprecision(10) << total_b  << ",";
        // updateFile(arr,randomNumberFile,n);

        // Update the file with the sorted array
        writeThefile(randomNumberFile, n);
        readThefile(randomNumberFile, arr);

        // Perform Selection Sort on the array
        clock_t start_s, end_s;
        float total_s;

        start_s = clock();
        heapSort(arr, n);
        end_s = clock();
        total_s = ((float)(end_s - start_s)) / CLOCKS_PER_SEC;
        
        cout << "N - " << n << ": " << setprecision(10) << total_s << ": H\n";
        // cout << setprecision(10) << total_b  << ",";

        // Increase the size of the array for the next iteration
        n = n + 20000;
    }
}
