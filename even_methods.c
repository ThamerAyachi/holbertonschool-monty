#include "monty.h"

/**
 * handel_string - check string
 * @str: string
 * @stack: stack
 * @line: integer
 * @file: file
 * Return: integer
 */
int handel_string(char *str, stack_t **stack, int line, file_t file)
{
	char *comm;
	int result;

	comm = strtok(str, " \n\t\r");
	if (comm == NULL)
		return (1);

	result = check_input(comm);
	if (result == 1)
	{
		comm = strtok(NULL, " \n\t\r");
		if (comm == NULL || is_digit(comm) != 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line);
			frees_and_exit(stack, file);
		}
		push_stack(stack, atoi(comm));
	}
	else if (result == 2)
		pall_stack(stack);
	else if (result == 3)
		pop_stack(stack, line, file);
	else
	{
		dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line, comm);
		frees_and_exit(stack, file);
	}
	return (0);
}

/**
 * is_digit - check string if is it digit
 * @str: string
 * Return: (0) if succuss and (1) if fail
 */
int is_digit(char *str)
{
	char *tmp = str;

	if (tmp == NULL)
		return (1);
	for (; *tmp != '\0'; tmp++)
		if ((*tmp < '0' || *tmp > '9') && *tmp != '-')
			return (1);
	return (0);
}

/**
 * frees_and_exit - free element and exit
 * @stack: stack
 * @file: file
 */
void frees_and_exit(stack_t **stack, file_t file)
{
	free_stack(*stack);
	free(file.content);
	fclose(file.fs);
	exit(EXIT_FAILURE);
}
