#include "monty.h"

/**
 * check_input - check input
 * @str: input
 * Return: integer
 */
int check_input(char *str)
{
	if (strcmp(str, "push") == 0)
		return (1);

	return (0);
}