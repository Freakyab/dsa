#include<stdio.h>
#include <stdlib.h>

// Code to multiply two numbers using dynamic memory allocation 
void main()
{
    int n,*ptr,i=0,sum=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    ptr = (int *)malloc(n*sizeof(int));
    printf("Enter the elements for array :");
    while(n != NULL)
    {
        scanf("%d",ptr+i);
        sum = sum + *(ptr+i);
        n--;
    }
    
    printf("Sum of the elements is %d",sum);
    free(ptr);
}