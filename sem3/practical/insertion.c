#include <stdio.h>
int print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%3d ", arr[i]);
    }
    printf("\n");
}

int merge(int arr[],int n)
{
    int mid= n/2;
    print(arr,n);
    int arr1[mid],arr2[n-mid],res[5];
    int i=0,j;
    while(i<mid)
    {
        print(arr1,mid);
        arr1[i]=arr[i];
        print(arr1,mid);
        i++;
    }
    i=0;
    while(mid+1<n)
    {
         print(arr2,mid+1);
        arr2[i]=arr[mid+1];
         print(arr2,mid+1);
        mid++;
        i++;
    }
    print(arr1,2);
    print(arr2,3);

}

int main()
{
    int arr[5] = {5, 45, 3, 2, 1};
    int i, j, n = 5, temp,min;
    print(arr, n);
    // for(i = 1; i<n;i++)
    // {
        // int temp = arr[0];
        // for(j=i-1;j>=0;j--)
        // {
        //     if(arr[j]>arr[j+1])
        //     {
        //         print(arr,n);
        //         temp=arr[j];
        //         arr[j]=arr[j+1];
        //         arr[j+1]=temp;
        //     }
        // }
    // }
    // for(i=0;i<n;i++)
    // {
    //     min = i;
    //     for(j=i+1;j<n;j++)
    //     {
    //         if(arr[min]>arr[j])
    //             min = j;
    //         temp = arr[min];
    //         arr[min]= arr[i];
    //         arr[i] = temp;
    //     }
    // }
    merge(arr,n);
    // print(arr,n);
    return 0;
}