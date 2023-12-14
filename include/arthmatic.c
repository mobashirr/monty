#include "func.h"


/**
 * add - add top two elments of the stack
 * Return: 0 if success else 1
*/
int add(void)
{
	int i;

	if (linked && linked->next)
	{
		i = linked->n + linked->next->n;
		linked = linked->next;
		linked->n = i;
		free(linked->prev);
		linked->prev = NULL;
		return (0);
	}
	else
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line);
		return (EXIT_FAILURE);
    }
}

/**
 * add - subtract top two elments of the stack x(n-1) - x(n)
 * where n is the order of last pushed element 
 * Return: 0 if success else 1
*/
int sub(void)
{
    int i;

    if (linked && linked->next)
    {
        i = linked->n;
        linked = linked->next;

        linked->n = linked->n - i;

        linked->prev->next = NULL;
        free(linked->prev);

        linked->prev = NULL;

        return 0;
    }
    else
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line);
        return (EXIT_FAILURE);
    }

    return (1);
}

/**
 * add - subtract top two elments of the stack x(n-1) - x(n)
 * where n is the order of last pushed element 
 * Return: 0 if success else 1
*/
int divi()
{
   int i = -1;

    if (linked && linked->next)
    {
        i = linked->n;

        if (i == 0)
        {
        fprintf(stderr, "L%d: division by zero\n", line);
        return (EXIT_FAILURE);
        }
        linked = linked->next;

        linked->n = linked->n / i;

        linked->prev->next = NULL;
        free(linked->prev);

        linked->prev = NULL;

        return 0;
    }
    else
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", line);
        return (EXIT_FAILURE);
    }
    return (1);
}

/**
 * add - mull top two elments of the stack
 * Return: 0 if success else 1
*/
int mul(void)
{
    if (linked && linked->next) 
    {
        int i = linked->n;

        linked = linked->next;

        linked->n = linked->n * i;

        linked->prev->next = NULL;
        free(linked->prev);


        linked->prev = NULL;

        return 0;
    } else
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line);
        return(EXIT_FAILURE);
    }
}
