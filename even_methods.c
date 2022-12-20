#include "monty.h"

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
			free_stack(*stack);
			free(file.content);
			fclose(file.fs);
			exit(EXIT_FAILURE);
		}
		push_stack(stack, atoi(comm));
	}
	else if (result == 2)
		pall_stack(stack);
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
	if (*tmp == '-')
		(*tmp)++;
	for (; *tmp != '\0'; tmp++)
		if (*tmp < '0' || *tmp > '9')
			return (1);
	return (0);
}
