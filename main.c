#define _GNU_SOURCE
#include "header.h"

stack_t *linked;
int line = 0;

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
			len = strlen("Error: Can't open file");
			write(STDERR_FILENO, "Error: Can't open file", len);
			return (EXIT_FAILURE);
		}
		else
		{
			while (getline(&buf, &len, file) != -1)
			{
				line += 1;
				tokens = parse(buf);
				if (tokens && buf)
				{
					exit_stat = excute(tokens);
					free(tokens);
				}

			}
		}
		free_linked();
		free(buf);
		fclose(file);
	}
	else
	{
		fprintf(stderr, "USAGE: monty file");
		exit (EXIT_FAILURE);
	}
	exit (exit_stat);
}
