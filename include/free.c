#include "monty.h"

/**
 * free_arr - free allocated memory for array
 * @arr: string array
*/
void free_arr(char **arr)
{
	if (arr)
	{
		if (arr[0])
	{
			free(arr[0]);
		}
	}
}

/**
 * free_linked - free linked list
 * @arr: linked list
*/
void free_linked(void)
{
	stack_t *temp = NULL;

	if (linked)
	{
		while (linked)
		{
			if (linked->next)
			{
				temp = linked->next;
				free(linked);
				linked = temp;
				linked->prev = NULL;
			}
			else
			{
				free(linked);
				break;
			}
		}
	}
}