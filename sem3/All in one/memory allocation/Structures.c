// Structure is the collection of heterogeneous different data types

// Syntax:
// struct structure_name
//     {
//         data_type member1;
//         data_type member2;
//         data_type member3;
//         .
//         .
//         .
//     } variable_name;
    
// Example:
// Students detail using structures
/*
#include<stdio.h>
#include <stdlib.h>

void main()
{
    struct student
        {
            int rn;
            char name[20];
            float marks;
        } stu1;
    struct student stu2;
    printf("For student 1\n");
    
    printf("Enter the roll number:");
    scanf("%d",&stu1.rn);
    printf("Enter the name:");
    scanf("%s",stu1.name);
    printf("Enter the marks:");
    scanf("%f",&stu1.marks);
    
    printf("For student 2\n");
    
    printf("Enter the roll number:");
    scanf("%d",&stu2.rn);
    printf("Enter the name:");
    scanf("%s",stu2.name);
    printf("Enter the marks:");
    scanf("%f",&stu2.marks);
    printf("The student details are:\n");
    printf("1.Name: %s , Roll no: %d , Marks: %f",stu1.name,stu1.rn,stu1.marks);
    printf("2.Name: %s , Roll no: %d , Marks: %f",stu2.name,stu2.rn,stu2.marks);
}
*/

// Pointer 
// A variable that stores memory address of another variable

// Syntax:
    // data_type *variable_name 
// example:
    /*  
    int *iptr,a;
        iptr =&a;
    float *fptr,b;
        fptr =&b;
    char *cptr,c;
        cptr =&c;
    */
// Array and pointers

/* 
int a =10,*iptr = &a;
float b = 10.5,*fptr = &b;
char c = 'A',*cptr = &c;

iptr++ => iptr+1
       => 2000+(1*4) = 2004
fptr++ => fptr+1
       => 2000+(4*4) = 2016
cptr++ => cptr+1
       => 2000+(1*1) = 2001
*/

// Find sum of array elements using pointer

/*
#include<stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5],i,sum =0;
    printf("Enter the elements for array\n");
    for(i=0;i<5;i++)
    {   
        printf("Enter: ");
        scanf("%d",&arr[i]);
    }
    for(i=0;i<5;i++)
    {
        sum = sum + *(arr+i);
    }
    printf("Sum of the elements is %d",sum);
    return 0;
}
*/

// Pointer to Structure

#include<stdio.h>
#include <stdlib.h>

struct student
    {
        int rn;
        char name[20];
        float marks;
    };
void main()
{
    struct student stu,*ptr;
    ptr = &stu;
    printf("Enter the students details:\n");
    scanf("%d %s %f",&stu.rn,&stu.name,&stu.marks);
    printf("The student details are:\n");
    printf("Name: %s , Roll no: %d , Marks: %f",(*ptr).name,ptr->rn,(*ptr).marks);
}