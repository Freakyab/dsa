#include <stdio.h>
int print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int selection(int arr[],int n)
{
    int i,min,j,temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int insertion(int arr[],int n)
{
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[i];
                arr[i]=temp;
            }
        }
    }
    
}
int main()
{
    int arr[5] = {1,2,3,4,5};
    int i, j, n = 5, temp;
    selection(arr,n);
    // insertion(arr,n);
    print(arr,n);
}