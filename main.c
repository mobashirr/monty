#include "monty.h"

stack_t *linked = 0;

int main(int argc, char *argv[])
{
	const char *file_name;
	FILE *file;
	char *buf = NULL;
	char **tokens;
	size_t len = 5;

	if (argc == 2)
	{
		file_name = argv[1];
		file = fopen(file_name,"r");

		if (!file)
		{
			perror("open error");
			return 1;
		}
		else
		{
			while (getline(&buf, &len, file) != -1)
			{
				tokens = parse(buf);
				if (tokens)
				{
					excute(tokens);
					free_arr(tokens);
				}
			}
		}
		free(buf);
		fclose(file);

	}
	return 0;
}
