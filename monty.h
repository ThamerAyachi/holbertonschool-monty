#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct file_s - file
 * @fs: file address
 * @content: file content
 */
typedef struct file_s
{
	FILE *fs;
	char *content;
} file_t;

extern file_t file;

void get_content(char *argv);
int check_input(char *str);
void push_stack(stack_t **stack, int num);
void pall_stack(stack_t **stack);
int handel_string(char *str, stack_t **stack, int line, file_t file);
void free_stack(stack_t *stack);
int is_digit(char *str);
void frees_and_exit(stack_t **stack, file_t file);
void pop_stack(stack_t **stack, int line, file_t file);
void pint_stack(stack_t **stack, int line, file_t file);
void swap_stack(stack_t **stack, int line, file_t file);
void add_stack(stack_t **stack, int line, file_t file);
void sub_stack(stack_t **stack, int line, file_t file);
void div_stack(stack_t **stack, int line, file_t file);
void mul_stack(stack_t **stack, int line, file_t file);
void mod_stack(stack_t **stack, int line, file_t file);

#endif
