#include "monty.h"

/**
 * get_content - get content from file
 * @argv: name of file
 */
void get_content(char *argv)
{
	size_t buf_size = 0;
	stack_t *stack;
	int line = 0;

	file.fs = fopen(argv, "r");
	if (file.fs)
	{
		while (getline(&file.content, &buf_size, file.fs) != -1)
		{
			line++;
			if (file.content == NULL)
			{
				continue;
			}
			else if (*file.content == '#')
				continue;
			handel_string(file.content, &stack, line, file);
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
