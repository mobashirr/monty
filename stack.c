#include "monty.h"

/**
 * push - push value onto stack
 * @element: value will be added
*/
int push(int element)
{
	stack_t *new = NULL;
	int len;

	new = malloc(sizeof(stack_t));

	if (!new)
	{
		len = strlen("memory problem");
		write(STDERR_FILENO, "memory problem", len);
		return (EXIT_FAILURE);
	}
	else
	{
		new->n = element;

		if (linked == NULL)
		{
			linked = new;
		}
		else
		{
			new->next = linked;
			new->prev = NULL;
			linked->prev = new;
			linked = new;
		}
	}
	return (0);
}


/**
 * pall - print the content of stack
*/
int pall(void)
{
	stack_t *temp = NULL;

	temp = linked;

	while (temp)
	{
		printf("%d\n", temp->n);

		if (temp)
			temp = temp->next;
	}
	return (0);
}

/**
 * pint - print the data at top of stack
*/
int pint(void)
{
	int len;

	if (linked)
	{
		printf("%d\n", linked->n);
	}
	else
	{
		len = strlen("L<line_number>: can't pint, stack empty");
		write(STDERR_FILENO, "L<line_number>: can't pint, stack empty", len);
		return (EXIT_FAILURE);
	}
	return (0);
}

/**
 * pop - remove last element of the stack
*/
int pop(void)
{
	stack_t *temp = NULL;
	int len;

	if (linked)
	{
		if (!linked->next)
		{
			free(linked);
			linked = NULL;
		}
		else
		{
			linked = linked->next;
			temp = linked->prev;
			linked->prev = NULL;
			free(temp);
		}
	}
	else
	{
		len = strlen("L<line_number>: can't pop an empty stack");
		write(STDERR_FILENO, "L<line_number>: can't pop an empty stack", len);
		return (EXIT_FAILURE);
	}
	return (0);
}

/**
 * swap - swap top two elments of the stack
 * Return: 0 or exit_faliure
*/
int swap(void)
{
	int i, len;

	if (linked && linked->next)
	{
		i = linked->n;
		linked->n = linked->next->n;
		linked->next->n = i;

	}
	else
	{
		len = strlen("L<line_number>: can't add, stack too short");
		write(STDERR_FILENO, "L<line_number>: can't add, stack too short", len);
		return (EXIT_FAILURE);
	}
	return (0);
}