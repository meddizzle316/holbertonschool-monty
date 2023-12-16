#ifndef MAIN_H
#define MAIN_H
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

extern int pn;
int _putchar(char c);
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
void free_all_and_exit(char **t_input, char *read_buffer, stack_t **h, int st);
void free_all(char **t_input, char *read_buffer, stack_t **h);
char **tokenize_file_input(char *file_input, size_t new_buffer_size);
char *get_file_input(char *filename, int *new_line_removed, size_t *rd);
char **tokenize_file_input_2(char *file_input, size_t new_buffer_size);
void free_array(char **array);
int execute(char **t_input, char *read_buffer, int nl_removed, stack_t **head);
void push(stack_t **head, unsigned int line_number);
void (*cmd_caller(const char *s))(stack_t **stack, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void free_stack(stack_t **head);
int extract_number(char *string);
int all_spaces(char *string);
#endif
