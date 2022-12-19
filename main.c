#include "monty.h"

file_t file;
stack_t *stack;
unsigned int top = 0;

int main(int argc, char *argv[])
{
	if (argc == 2)
		get_content(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
