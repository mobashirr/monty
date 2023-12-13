#define _GNU_SOURCE
#include "monty.h"

stack_t *linked;

int main(int argc, char *argv[])
{
	const char *file_name;
	FILE *file;
	char *buf = NULL;
	char **tokens;
	size_t len = 5;
	int exit_stat = 0;

	if (argc == 2)
	{
		file_name = argv[1];
		file = fopen(file_name, "r");

		if (!file)
		{
			len = strlen("opening error");
			write(STDERR_FILENO, "opening error", len);
			return (1);
		}
		else
		{
			while (getline(&buf, &len, file) != -1)
			{
				tokens = parse(buf);
				if (tokens && buf)
				{
					exit_stat = excute(tokens);
					free(tokens);
					if (exit_stat != 0)
						break;
				}
			}
		}
		free_linked();
		free(buf);
		fclose(file);
	}
	exit (exit_stat);
}


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