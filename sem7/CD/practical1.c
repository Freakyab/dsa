#include <stdio.h>
#include <conio.h>
#define max 100

int main()
{
    char variableName[max];

    printf("Enter the name of variable : ");
    scanf("%s", variableName);

    if(variableName[0] >=  'a' && variableName[0] <= 'z' || variableName[0] >= 'A' && variableName[0] <= 'Z' || variableName[0] == '_')
    {
        int i = 1;
        while(variableName[i] != '\0')
        {
            if(variableName[i] >= 'a' && variableName[i] <= 'z' || variableName[i] >= 'A' && variableName[i] <= 'Z' || variableName[i] >= '0' && variableName[i] <= '9' || variableName[i] == '_')
            {
                i++;
            }
            else
            {
                printf("Invalid variable name");
                return 0;
            }
        }
        printf("Valid variable name");
    }
    else
    {
        printf("Invalid variable name");
    }
}