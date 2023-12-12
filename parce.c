#include "monty.h"

char **parse(char *line)
{
	int len = 0, cap = ARGBUF;
	char *token = NULL, **tokens = NULL;

	tokens = malloc(cap * sizeof(char *));
	if (!tokens)
	{
		fprintf(stderr,"tokenatioan failed");
		return (NULL);
	}
	token = strtok(line, DELIMIT);

	if (check(token) == -1)
	{
		return NULL;
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
				fprintf(stderr,"tokenatioan failed at mid");
				return (NULL);
			}
		}
		token = strtok(NULL, DELIMIT);
	}
	tokens[len] = NULL;
	return (tokens);
}

int check(char *order)
{
	char *arr[4] = {"push","pall", "pint", "pop"};
	int i,len;

	len = sizeof(arr)/sizeof(arr[0]);

	for (i = 0; i < len; i++)
	{
		if (strcmp(arr[i],order) == 0)
			return 0;
	}
	return -1;
}

int excute(char **order)
{
	int i;
	if(order[1] != NULL)
		i = atoi(order[1]);

	if (strcmp(order[0], "push") == 0)
	{
		if (!order[1])
		{
				fprintf(stderr,"L<line_number>: usage: push integer");
				return (EXIT_FAILURE);
		}
	   		push(i);
	}
	else if (strcmp(order[0], "pall") == 0)
	{
		pall();
	}
	else if (strcmp(order[0],"pint") == 0)
		pint();
	else if(strcmp(order[0],"pop") == 0)
		pop();
	else
		printf("Default case or error handling\n");

	return 0;
}
