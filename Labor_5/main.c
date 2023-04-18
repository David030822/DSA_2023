#include "headers/stack.h"
#include "sources/stack.c"

int main()
{
    char expression1[] = "2 5 3 6 + * * 15 / 2 -";
    char expression2[] = "2 5 3 a + * * 15 / 2 -";
    char expression3[] = "2 5 3 6 + * * 15 / 2";
    char expression4[] = "2 5 3 6 + * * 15 / 2 - +";

    Stack stack;
    createStack(strlen(expression1), &stack);

    printf("%d\n", isnumber("7854"));

    printf("%d ", peek(postfix(stack, expression1)));

    return 0;
}
