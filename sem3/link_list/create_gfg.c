#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next; 
};

void print(struct node* p)
{
    while (p!=NULL)
    {
        printf("%d\n",p->data);
        printf("%d\n",p->next);
        p=p->next;
    }
}
int main()
{
    //define
    struct node* head=NULL;
    struct node* second = NULL;
    struct node* third=NULL;

    // heap allocation
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    // assign values
    head->data=1;
    head->next=second;
    second->data=2;
    second->next=third;
    third->data=3;
    third->next=NULL;

    print(head);
}
