#include "monty.h"

void get_content(char *argv)
{
	size_t buf_size = 0;
	stack_t *stack;

	file.fs = fopen(argv, "r");
	if (file.fs)
	{
		while (getline(&file.content, &buf_size, file.fs) != -1)
		{
			if (file.content == NULL)
			{
				continue;
			}
			else if (*file.content == '#')
				continue;
			handel_string(file.content, &stack);
		}
		free(file.content);
		free_stack(stack);
		fclose(file.fs);
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
