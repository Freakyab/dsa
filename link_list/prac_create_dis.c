#include <stdio.h>
#include <stdlib.h>

struct node{
    int roll;
    int age;
    char name[20];
    struct node *next;
}*head;

void create(int i)
{
    int n;
    struct node *temp,*head,*roll_,*age_;
    for(n=0;n<3*i;n++)
    {
    // head = (struct node*)malloc(sizeof(struct node));
    // printf("Enter the name: ");
    // scanf("%s",head->name);
    // head->next = NULL;

    // temp=head;
    // roll_= (struct node*)malloc(sizeof(struct node));

    // printf("Enter the roll no: ");
    // scanf("%d",roll_->roll);
    // roll_->next=NULL;

    // age_= (struct node*)malloc(sizeof(struct node));
    // printf("Enter the age: ");
    // scanf("%d",head->age);
    // age_->next=NULL;

    // roll_->next=age_;
    // temp->next=roll_;
    }
    while(temp!=NULL)
    {
        printf("Name : %s\n",temp->roll);
        // printf("Name : %d",temp->roll);
        // printf("Name : %d",temp->age);
        temp=temp->next;
    }
}

int main()
{
    int len;
    printf("Enter the total no. of elements: ");
    scanf("%d",&len);

    create(len);
}