#include "monty.h"

int handel_string(char *str, stack_t **stack)
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
		if (comm == NULL)
			return (1);
		push_stack(stack, atoi(comm));
	}
	else if (result == 2)
		pall_stack(stack);
	exit(1);
}
