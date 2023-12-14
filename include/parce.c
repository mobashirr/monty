#include "func.h"

/**
 * parse - parse
 * @line: line
 * Return: arr of ptr
*/
char **parse(char *command)
{
	int len = 0, cap = ARGBUF;
	char *token = NULL, **tokens;

	tokens = malloc(cap * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	token = strtok(command, DELIMIT);

	if (check(token) == -2 || token[0] == '#')
	{
		if (tokens)
			free(tokens);
		return (NULL);
	}
	else if (check(token) == -1 && token)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, token);
		return (NULL);
	}


	while (token)
	{
		tokens[len++] = token;
		if (len >= cap)
		{
			cap += (ARGBUF + 1);
			tokens = realloc(tokens, cap * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "tokenatioan failed at mid");
				return (NULL);
			}
		}
		token = strtok(NULL, DELIMIT);
	}
	tokens[len] = NULL;
	return (tokens);
}

/**
 * check - check if the order is rigth
 * @order: is the command
 * return: 0 if ture else -1
 */
int check(char *order)
{
	char *arr[11] = {"push", "pall", "pint",
					 "pop", "swap", "add", "nop",
					 "sub", "div", "mul",
					 "pchar"	};
	int i = 0, len =0;

	len = sizeof(arr) / sizeof(arr[0]);

	if (!order)
		return (-2);
	for (i = 0; i < len; i++)
	{
		if (strcmp(arr[i], order) == 0)
			return (0);
	}
	return (-1);
}

/**
 * excute - excute the command
 * @order: command
 * Return: 0 if success else -1
*/
int excute(char **order)
{
	int i = -320;
    char *endptr = NULL;

	if (!order)
		return (EXIT_FAILURE);

	if (order[1] != NULL)
	{
		strtol(order[1], &endptr, 10);
		if(*endptr == '\0')
			i = atoi(order[1]);
		else if (strcmp(order[0], "push") == 0)
			goto erorr;
	}

	if (strcmp(order[0], "push") == 0)
	{
		if (!order[1] || i == -320)
		{
erorr:
			fprintf(stderr, "L%d: usage: push integer\n", line);
			return (EXIT_FAILURE);
		}
		return (push(i));
	}
	else if (strcmp(order[0], "pall") == 0)
		return (pall());
	else if (strcmp(order[0], "pint") == 0)
		return (pint());
	else if (strcmp(order[0], "pop") == 0)
		return (pop());
	else if (strcmp(order[0], "swap") == 0)
		return (swap());
	else if (strcmp(order[0], "add") == 0)
		return (add());
	else if (strcmp(order[0], "nop") == 0)
		return (0);	/*no opreation just skip*/
	else if (strcmp(order[0], "sub") == 0)
		return (sub());
	else if (strcmp(order[0], "div") == 0)
		return (divi());
	else if (strcmp(order[0], "mul") == 0)
		return (mul());
	else if (strcmp(order[0], "pchar") == 0)
		return (pchar());
	return (1);
}
