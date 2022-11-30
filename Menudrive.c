<<<<<<< HEAD
#include <stdio.h>
int binary(int arr[], int f, int l, int key)
{
    int mid;
    mid = (l + f) / 2;
    if (key == arr[mid])
        return mid;
    else if (f == l)
    {
        return -1;
    }
    else if (key < arr[mid])
    {
        l = mid;

        binary(arr, f, l, key);
    }
    else if (key > arr[mid])
    {
        f = mid + 1;
        binary(arr, f, l, key);
    }
}

int linear(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int check(int che, int key)
{
    if (che == -1)
    {
        printf("Not found");
    }
    else
    {
        printf("%d Found at %d", key, che);
    }
}
int main()
{
    int n;
    printf("Enter the total elements for array: ");
    scanf("%d", &n);
    int i, l, f, flag = 0, key, action, che;
    int arr[n];
    l = 4, f = 0;
    for (i = 0; i < n; i++)
    {
        printf("Enter the elements for array: ");
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &key);
    printf("1. Linear Search\n2.Binary Search\nEnter: ");
    scanf("%d", &action);
    if (action == 1)
    {
        che = linear(arr, n, key);
        check(che, key);
    }
    else if (action == 2)
    {
        che = binary(arr, f, l, key);
        check(che, key);
    }
    else
    {
        printf("Invalid");
    }
=======
// Online C compiler to run C program online
#include <stdio.h>
int binary(int arr[], int f,int l,int key)
{
    int mid;
    mid = (l+f)/2;
    if(key == arr[mid])
        return mid;
    else if(f==l)
    {
        return -1;
    }
    else if(key<arr[mid])
    {
        l = mid;
      
        binary(arr,f,l,key);
    }    
    else if(key>arr[mid])
    {
        f= mid+1;
        binary(arr,f,l,key);
    }
}
int main() {
//  int n;
//  printf("Enter the ")
 int arr[]={10,20,30,40,50};
 int l,f,flag=0,key = 60,che;
 l = 4,f=0;
 che = binary(arr,f,l,key);
//  if (che == -1)
//  {
//      printf("NOt found");
//  }
 printf("%d",che);
>>>>>>> ebc187b61b22fb6bff69005b8b9331dad0dde9b7
    return 0;
}
