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
    return 0;
}
