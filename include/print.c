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