#include "headers/stack.h"

int main()
{
    char expression1[] = "2 5 3 6 + * * 15 / 2 -";
    char expression2[] = "2 5 3 a + * * 15 / 2 -";
    char expression3[] = "2 5 3 6 + * * 15 / 2";
    char expression4[] = "2 5 3 6 + * * 15 / 2 - +";

    Stack stack;
    createStack(strlen(expression1), &stack);

    const char s[2] = " ";
    char *token;
    token = strtok(expression1, s);
    while(token != NULL)
    {

        token = strtok(NULL, s);
    }

    return 0;
}
