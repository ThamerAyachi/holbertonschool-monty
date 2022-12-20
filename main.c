#include "monty.h"

file_t file;

/**
 * main - entry place
 * @argc: integer
 * @argv: array of string
 * Return: integer
 */
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
