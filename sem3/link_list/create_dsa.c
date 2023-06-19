#include <stdio.h>
#include <stdlib.h>

//Structure is created

struct node{
    int data;
    struct node *next;
}*head;

void create(int n)
{
    //Two pointer temp and newnode is used
    struct node *newNode,*temp;
    int i,data;

    //space allocation is done in runtime
    head = (struct node*)malloc (sizeof(struct node));
    printf("Enter the data for node 1: ");
    scanf("%d",&data);

    //[ 1 | Null ]

    head->data=data;
    head->next=NULL;

    //temp==   [ 1 | Null]
    temp=head;
    
    //To link futher list i is started from 2
    for(i=2;i<=n;i++)
    {

        //space allocation is done in runtime
        newNode=(struct node*)malloc(sizeof(struct node));
        
        printf("Enter the data for node %d: ",i);
        scanf("%d",&data);
        
        //newNode == [ 2 | null]
        
        newNode->data=data;
        newNode->next=NULL;

        //  temp== [ 1 | (locationm of 2)]-> [ 2 | NUll]
        temp->next=newNode;
        temp=temp->next;
    }
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("Data : %d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int n;
    printf("Enter the no. of elements you want: ");
    scanf("%d",&n);

    create(n);
    display();
}