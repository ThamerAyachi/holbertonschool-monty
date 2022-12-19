#include "monty.h"

file_t file;

int main(int argc, char *argv[])
{
	if (argc == 2)
		get_contact(argv[1]);
	else
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	return (0);
}
