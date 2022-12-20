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
	if (strcmp(str, "pall") == 0)
		return (2);
	if (strcmp(str, "pop") == 0)
		return (3);

	return (0);
}

/**
 * push_stack - push new element in stack
 * @stack: array of linked list
 * @num: value
 */
void push_stack(stack_t **stack, int num)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	tmp->n = num;
	tmp->next = (*stack);
	if (*stack != NULL)
		(*stack)->prev = tmp;
	(*stack) = tmp;
}

/**
 * pall_stack - print stack
 * @stack: array of linked list
 */
void pall_stack(stack_t **stack)
{
	stack_t *tmp;

	tmp = (*stack);

	while (tmp->next != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - free stack as linked list
 * @stack: stack
 */
void free_stack(stack_t *stack)
{
	if (stack->next != NULL)
	{
		free_stack(stack->next);
		free(stack);
	}
}

/**
 * pop_stack - remove last element from stack
 * @stack: stack
 * @line: integer
 */
void pop_stack(stack_t **stack, int line, file_t file)
{
	stack_t *tmp;

	tmp = malloc(sizeof(stack_t));
	if (tmp == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		frees_and_exit(stack, file);
	}

	if (*stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line);
		frees_and_exit(stack, file);
	}

	tmp = (*stack);
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	free(tmp);
}
