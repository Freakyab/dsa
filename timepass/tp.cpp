#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

void WTF(int n)
{
    srand(time(0));

    ofstream myFile("this.txt");

    for (int i = 0; i < n; i++)
    {
        myFile << rand() % 100000 << endl;
    }

    myFile.close();
}

void RTF(int arr[]){
    ifstream myFile("this.txt");

    int j = 0,i =0;
    while(myFile >> i){
        cout << i<< " ";
        arr[j] = i;
        j++;
    }
}

int merge(int arr[], int l, int r, int m)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
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
        i++, k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++, k++;
    }
}

int mergeSort(int l, int r, int arr[])
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(l, m, arr);
        mergeSort(m + 1, r, arr);

        merge(arr, l, r, m);
    }
}

int insertion(int arr[],int n){
    for(int i= 1; i<n;i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int main(){
    // int arr[] = {9,8,7,6,5,4,3,2,1};
    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    // WTF(n);
    RTF(arr);

    for(int i =0; i<n;i++){
        cout << arr[i] << " ";
    }
}