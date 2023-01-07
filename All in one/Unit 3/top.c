#include<stdio.h>
#include <stdlib.h>

#define max 100

int arr[max];
int top = -1;

int push(int x)
{
    if(top == -1 || top == max-1)
    {
        printf("Invaild");
    }
    else{
        top++;
        arr[top]= x;
    }
}
int display()
{
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else{
        for(int i = 0;i<top;i++)
        {
            printf("%d\n",arr[i]);
        }
    }
}
int main()
{
    push(1);
    display();
}