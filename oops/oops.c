#include <stdio.h>
// Practical no 1
int fact(void)
{
    int n, fact = 1;
    printf("Enter the no: ");
    scanf("%d", &n);
    while (n > 1)
    {
        fact = fact * n;
        n--;
    }
    if (n >= 0)
        printf("\n%d is the fact", fact);
    else
        printf("Not possible");
}

// Practical no 2
int area(void)
{
    int r;
    float pi = 3.14, totalArea;
    printf("Enter the radius: ");
    scanf("%d", &r);
    totalArea = pi * r * r;
    printf("\n%d is total area", totalArea);
}

// practical no 3
int leapYear(void)
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                printf("\n%d is a leap year", year);
            else
                printf("\n%d is not a leap year", year);
        }
        else
            printf("\n%d is a leap year", year);
    }
    else
        printf("\n%d is not a leap year", year);
}
// practical 4;
int GCD(int a, int b)
{
    int result;
    for(int i=1;i<=a && i<=b;i++){
        if(a%i==0 && b%i==0){
            printf("%d\n",i);
            result=i;
        }
    }
    return result; // return gcd of a and b
}

int primeNo()
{
    int n, i, temp, flag = 0;
    printf("Enter : ");
    scanf("%d", &n);
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            {
                flag = 1;
            }
        }
    }
    if (flag == 0)
    {
        printf("Prime");
    }
    else
    {
        printf("not Prime");
    }
}

int palli(void)
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {

        n = n % 10;
    }
}
int main(void)
{
    // fact();
    // area();
    // leapYear();
   int res =  GCD(120,80);
   printf("%d",res);
    // primeNo();
}