#include<stdio.h>
#include <stdlib.h>
//  define max size of stack
#define max 100

//  define stack
int arr[max];

//  define top
int top = -1;

//  define functions
int display()
{
    // if stack is empty then print stack is empty

    if(top==-1)
    {
        printf("Stack is empty");
    }
    else{
        for(int i = top;i>=0;i--)
        {
            printf("element of %d: %d\n",i,arr[i]);
        }
    }
}
int push(int x)
{
    if( top == max-1)
    {
        printf("Invaild");
    }
    else{
        top++;
        arr[top]= x;
        printf("Pushed %d\n",x);
        
    }
}
int pop()
{
    if(top == -1)
    {
        printf("stock is empty\n");
    }
    else{
        top--;
    }
}
int peek()
{
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",arr[top]);
    }
}
int main()
{
    // printf("hi %d",top);
    // printf("hi %d",max);
    int action;
    int done = 0;
    while(done == 0)
    {
    printf("Enter the action you want to perform:\n1.Push\n2.Pop\n3.Peek\n4.Display\nEnter: ");
    scanf("%d",&action);
        if(action == 1)
        {
            int x;
            printf("Enter the element you want to push:");
            scanf("%d",&x);
            push(x);
            // display();
        }
        else if(action == 2)
        {
            pop();
            display();
        }
        else if(action == 3)
        {
            peek();
        }
        else if(action == 4)
        {
            display();
        }
        else if(action == 5)
        {
            done = 1;
        }
        else{
            printf("Invalid");
        }
    }
    
}