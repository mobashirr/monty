#include "monty.h"


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
		return (1);
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
        return 1;

}
