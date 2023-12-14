#include "func.h"


int pchar(void)
{
    if (linked)
    {
        if (linked->n < 0 || linked->n > 127)
        {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
        return(EXIT_FAILURE);
        }
        printf("%c\n", linked->n);
    }
    else 
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
        return(EXIT_FAILURE);
    }
    return (0);
}

int pstr(void)
{
    stack_t *temp = NULL;

    if (!linked)
    {
        printf("\n");
        return (0);
    }
    temp = linked;

    while (temp)
    {
        if (temp->n <= 0 || temp->n > 127)
        {
            break;
        }
        printf("%c", temp->n);

        if (temp->next)
            temp = temp->next;
        else
            break;
    }
    printf("\n");
    return (0);
}