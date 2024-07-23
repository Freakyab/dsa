#include <stdio.h>
#include <conio.h>
#include <string.h>
#define max 100

int main()
{
    char variableName[max];

    printf("Enter the name of variable : ");
    scanf("%s", variableName);

    char *array[34];
    array[0] = "auto";
    array[1] = "break";
    array[2] = "case";
    array[3] = "char";
    array[4] = "const";
    array[5] = "continue";
    array[6] = "default";
    array[7] = "do";
    array[8] = "double";
    array[9] = "else";
    array[10] = "enum";
    array[11] = "extern";
    array[12] = "float";
    array[13] = "for";
    array[14] = "goto";
    array[15] = "if";
    array[16] = "int";
    array[17] = "long";
    array[18] = "register";
    array[19] = "return";
    array[20] = "short";
    array[21] = "signed";
    array[22] = "sizeof";
    array[23] = "static";
    array[24] = "struct";
    array[25] = "switch";
    array[26] = "typedef";
    array[27] = "union";
    array[28] = "unsigned";
    array[29] = "void";
    array[30] = "volatile";
    array[31] = "while";
    array[32] = "main";
    array[33] = "new";

    for (int i = 0; i < 34; i++)
    {
        // printf("%s\n",array[i]);
        if (strcmp(variableName, array[i]) == 0)
        {
            printf("Invalid variable name");
            return 0;
        }
    }

    if (variableName[0] >= 'a' && variableName[0] <= 'z' || variableName[0] >= 'A' && variableName[0] <= 'Z' || variableName[0] == '_')
    {
        int i = 1;
        while (variableName[i] != '\0')
        {
            if (variableName[i] >= 'a' && variableName[i] <= 'z' || variableName[i] >= 'A' && variableName[i] <= 'Z' || variableName[i] >= '0' && variableName[i] <= '9' || variableName[i] == '_')
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
}