// A linked list is a data structure which can change during execution
/*
    - A linked list is a collection of nodes
    - Each node contains a data field and a link field
    - The link field contains the address of the next node in the list
    - The last node in the list contains a link field with a value of NULL
    - The first node in the list is called the head of the list
    - The last node in the list is called the tail of the list
    - The link field of the tail node is NULL
*/
// link list is Abstract data type
// Abstract data type is a data type which is defined by user they are basically more complex than the primitive data types

// Why abstract data type is used?
// 1. To hide the implementation details
// 2. To provide a standard way of accessing the data
// 3. To provide a standard way of manipulating the data


// structure 
//  struct nd
//  {
//     int data;
//     struct nd *next;
//  }
//  self refrance structure
/*
                    typedef struct node
                    {
                        int data;
                        struct node *next;
                    }node;
*/

// Insertion
// 1. At the beginning
// 2. At the end
// 3. At the given position
//  New node is created with new items
//  New node is linked to the list

// Syntax:
/*
void insert (node* curr)
{
        node *newnode;
        newnode = (node*)malloc(sizeof(node));
        newnode->data = 10;
        newnode->next = curr->next;
        curr->next = newnode;
}
*/

// Deletion
// 1. At the beginning
// 2. At the end
// 3. At the given position
// Syntax:
/*
void delete(node* curr)
{
        node *temp;
        temp = curr->next;
        curr->next = temp->next;
        free(temp);
}
*/

// Array vs Linked List
// 1. Array is a static data structure      
// 2. Linked list is a dynamic data structure
// 3. Array is a contiguous data structure
// 4. Linked list is a non-contiguous data structure
// 5. Array is a linear data structure
// 6. Linked list is a non-linear data structure
// 7. Array insertion and deletion take place at the end
// 8. Linked list insertion and deletion take place wherever we want
// 9. Array can access any element randomly
// 10. Linked list can access any element sequentially
// 11. Array insertion and deletion is 0(n)
// 12. Linked list insertion and deletion is 0(1)

// Type Of List
    // depending on adjacency
// 1. Singly Linked List
// 2. Doubly Linked List
// 3. Circular Linked List

// basic operation on list 
// 1. Creation
// 2. Insertion
// 3. Traversal
// 4. Deletion
// 5. concatination

// 1. Singly Linked List
// 1.Creation
// To create a linked list we need to create a node
// A node is a structure which contains two parts
// 1. Data
// 2. Link

// #include<stdio.h>
// #include<stdlib.h>
// typedef struct node
// {
//     int data;
//     struct node *next;
// }node;

// node *create_list()
// {
//     int k,n;
//     node *p,*head;
//     printf("Enter the number of nodes: ");
//     scanf("%d",&n);

//     for(k=0;k<n;k++)
//     {
//         if(k==0)
//         {
//             head = (node*)malloc(sizeof(node));
//             p=head;
//         }
//         else{
//             p->next = (node*)malloc(sizeof(node));
//             p=p->next;
//         }
//         printf("Enter the data for node %d: ",k+1);
//         scanf("%d",&p->data);
//     }
//     p->next = NULL;
//     return head;
// }

// // 2.Traversal
// void display(node * head){
//     int count = 1;
//     node *p;

//     p = head;
//     while(p!=NULL)
//     {
//         printf("Data for node %d is %d\n",count,p->data);
//         count++;
//         p = p->next;
//     } 
// }

// void main()
// {
//     node *head;
//     head = create_list();
//     display(head);
// }

/* Testing 
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    char name[20];
    struct node *next;
}node;

node* create()
{
    int i,n;
    node *head,*p;
    printf("ENTER THE NO> OF NODE WANT: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            head = (node *)malloc(sizeof(node));
            p = head;
        }
        else{
            p->next = (node *)malloc(sizeof(node));
            p = p->next;
        }
        printf("ENTER THE DATA: ");
        scanf("%d",&p->data);
        printf("ENTER THE NAME: ");
        scanf("%s",&p->name);
    }
    p->next = NULL;
    return head; 
}
int main()
{
    node *head,*p;
    head = create();
    p = head;
    while(p!=NULL)
    {
        printf("THE ENTERED DATA IS %s\n",p->name);
        p = p->next;
    }
}
*/

//3.Inserting
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

node* display(node *p)
{
    while(p!= NULL)
    {
        printf("%3d",p->data);
        // printf("address %3d",p);
        p=p->next;
    }  
    printf("\n");
}
node * insert(node * head,int atpos,node * first)
{
    node *last,*p;
    p = head;
    while(p!=NULL)
    {
        if(p->data == atpos)
        {
            last = p->next ;
            p->next = first;
            break;
        }
        p=p->next;
    }
    while(p->next!=NULL)
    {
        p=p->next;
    }        
    p->next = last;
    return head;
}

node* delete(node* head,int pos)
{
    node *p,*del;
    p = head;

    // If the node to be deleted is the first node
    if(p->data == pos)
    {
        head = p->next;
        free(p);
        return head;
    }
    while(p->next != NULL)
    {   
        printf("%d\n",p->next->data);
        if(p->next->data==pos)
        {
            del = p->next;
            p->next = del->next;
            free(del);
            break;
        }
        p = p->next;
    }
    return head;
}

node * Concatenate(node * head)
{
    node *first,*i,*p;
    int n,j;
    p = head;
    printf("How many elements you want\nEnter: ");
    scanf("%d",&n);
    for(int j =0;j<n;j++)
    {
        if(j==0)
        {
            first = (node *)malloc(sizeof(node *));
            i = first;
        }
        else{
            i->next = (node *)malloc(sizeof(node *));
            i=i->next;
        }
        printf("Enter: ");
        scanf("%d",&i->data);
    }
    i->next = NULL;
    while(p->next!= NULL)
        p=p->next;
    p->next = first;
    return(head);
}
node *sort(node * head)
{
    node *p,*last,*no;
    int i,n = 2;
    p = head;
    no= (node *)malloc(sizeof(node *));
    no->data = n;
    no->next = NULL;
    
    while(p->next != NULL && p->next->data<n)
    {
        p=p->next;
    }

    if(n < head->data)
    {
        head = no;
        head->next = p;
        return head;
    }
    last = p->next;
    p->next = no;
     no->next = last;
    return head;
}
int main()
{
    node *head,*p,*second,*third,*fourth,*first,*j,*final;
    int i,m=3,n,atPos,act = 0;
    head = (node *)malloc(sizeof(node));
    p = head;
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    p->data = 1;
    p->next = second;
    second->data =3;
    second->next= third;
    third->data=4;
    third->next = fourth;
    fourth->data = 5;
    fourth->next = NULL;
    display(p);
    // printf("what u want to do\n1.Insert\n2.Delete\nEnter: ");
    // scanf("%d",&act);
    if(act==1)
    {
        printf("How many new node you want to add:\nEnter: ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                first = (node *)malloc(sizeof(node));
                j = first;
            }
            else{
                j->next = (node *)malloc(sizeof(node));
                j= j->next;
            }
            printf("Enter: ");
            scanf("%d",&j->data);
        }
        j->next = NULL;
        display(first);
        printf("After whom you want to add this data: ");
        scanf("%d",&atPos);
        final = insert(head,atPos,first);
        display(final);
    }
    if(act == 2)
    {
        printf("Which element you want to delete\nEnter: ");
        scanf("%d",&atPos);
        final = delete(head,atPos);
        display(final);
    }

    // Exercise
    // 1. Concatenate
    printf("Excercise qna\n");
    // final = Concatenate(head);
    // display(final);
    // 2.Sort
    final = sort(head);
    display(final);
}