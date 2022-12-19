#include "monty.h"

void get_contact(char *argv)
{
	size_t buf_size = 0;
	int counter = 0;
	char *arguments;

	file.fs = fopen(argv, "r");
	if (file.fs)
	{
		while (getline(&file.content, &buf_size, file.fs) != -1)
		{
			counter++;
			arguments = strtok(file.content, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			printf("%s\n", arguments);
		}
	}
	else
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}