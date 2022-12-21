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

/**
 * sub_stack - add new element the sub of last two element
 * @stack: stack
 * @line: integer
 * @file: file
 */
void sub_stack(stack_t **stack, int line, file_t file)
{
	int tmp = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line);
		frees_and_exit(stack, file);
	}

	tmp += (*stack)->next->n;
	tmp -= (*stack)->n;

	(*stack)->next->n = tmp;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}

/**
 * div_stack - add new element the div of last two element
 * @stack: stack
 * @line: integer
 * @file: file
 */
void div_stack(stack_t **stack, int line, file_t file)
{
	int tmp = 0;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line);
		frees_and_exit(stack, file);
	}
	tmp += (*stack)->next->n;
	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line);
		frees_and_exit(stack, file);
	}
	tmp /= (*stack)->n;

	(*stack)->next->n = tmp;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
}
