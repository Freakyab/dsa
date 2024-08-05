#include <stdio.h>
#include <string.h>
#define max 100

int main()
{
    char variableName[max];

    printf("Enter the name of variable : ");
    fgets(variableName, max, stdin);

    // Remove trailing newline character if present
    size_t len = strlen(variableName);

    if ((variableName[0] >= 'a' && variableName[0] <= 'z') || 
        (variableName[0] >= 'A' && variableName[0] <= 'Z') || 
        variableName[0] == '_')
    {
        int i = 1;
        while (variableName[i] != '\n') 
        // can use /0 if we remove the newline character
        {
            if ((variableName[i] >= 'a' && variableName[i] <= 'z') || 
                (variableName[i] >= 'A' && variableName[i] <= 'Z') || 
                (variableName[i] >= '0' && variableName[i] <= '9') || 
                variableName[i] == '_')
            {
                i++;
                if (i > 32)
                {
                    printf("Invalid variable length");
                    return 0;
                }
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

    return 0;
}
