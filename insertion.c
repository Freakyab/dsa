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

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    int i, j, n = 5, temp;
    print(arr, n);
    for (i=1;i<n;i++)
    {
        for ( j = i+1; j<n; j++)
        {
            if (arr[i]<arr[j])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            print( arr,n);
        }
    }
    // if (arr[0] > arr[1])
    // {
    //     temp = arr[1];
    //     arr[1] = arr[0];
    //     arr[0] = temp;
    // }
    // print(arr,n);
    // if (arr[1] > arr[2])
    // {
    //     temp = arr[2];
    //     arr[2] = arr[1];
    //     arr[1] = temp;
    // }
    
    // print(arr,n);
    return 0;
}