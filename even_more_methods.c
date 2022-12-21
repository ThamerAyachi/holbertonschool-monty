#include "monty.h"

/**
 * add_stack - add new element the total of last two element
 * @stack: stack
 * @line: integer
 * @file: file
 */
void add_stack(stack_t **stack, int line, file_t file)
{
	int tmp = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line);
		frees_and_exit(stack, file);
	}

	tmp += (*stack)->n;
	tmp += (*stack)->next->n;

	(*stack)->next->n = tmp;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}