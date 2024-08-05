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

      // if (len > 0 && variableName[len - 1] == '\n') {
    //     variableName[len - 1] = '\0';
    // }

    char *array[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
        "long", "register", "return", "short", "signed", "sizeof", "static", 
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", 
        "while", "main", "new", "delete"
    };

    for (int i = 0; i < strlen(array); i++)
    {
        if (strcmp(variableName, array[i]) == 0)
        {
            printf("Invalid variable name");
            return 0;
        }
    }

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
