#include <stdio.h>
#include <stdlib.h>

//  define max size of queue
#define max 100
int arr[max];
int front = -1;
int rear = -1;

//  define functions
int display()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else{
        for(int i = front;i<=rear;i++)
        {
            printf("Element of %d: %d\n",i,arr[i]);
        }
    }
}

int enqueue(int x)
{
    if(rear == max-1)
    {
        printf("Queue is full\n");
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = x;
        printf("Enqueued %d\n",x);
    }
    else{
        rear++;
        arr[rear] = x;
        printf("Enqueued %d\n",x);
    }
}

int dequeue()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else{
        front++;
    }
}

int peek()
{
    if(front == -1 && rear == -1)
    {
        printf("Queue is empty\n");
    }
    else{
        printf("Front element is %d\n",arr[front]);
    }
}

int main()
{
    int choice;
    int x=0;

    while(x==0)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\nEnter your choice: ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            printf("Enter the element: ");
            scanf("%d",&x);
            enqueue(x);
        }
        else if(choice == 2)
        {
            dequeue();
        }
        else if(choice == 3)
        {
            peek();
        }
        else if(choice == 4)
        {
            display();
        }
        else if(choice == 0)
        {
            printf("Exiting...\n");
            x = 1;
        }
        else{
            printf("Invalid choice\n");
        }
    }
}
