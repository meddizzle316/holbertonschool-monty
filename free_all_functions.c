#include "monty.h"
/**
 * free_all_and_exit - basic free all function to reduce space; also exits
 * @read_buffer: freeing read_buffer
 * @h: freeing stack
 * @t_input: freeing t_input
 * @st: exit status
 * Return: always void
 */
void free_all_and_exit(char **t_input, char *read_buffer, stack_t **h, int st)
{
	free(t_input);
	free_stack(h);
	free(read_buffer);
	exit(st);
}

/**
 * free_all - freeing all to reduce space
 * @t_input: freeing t_input
 * @read_buffer: freeing read_buffer
 * @h: freeing stack
 * Return: always void
 */
void free_all(char **t_input, char *read_buffer, stack_t **h)
{
	if (t_input != NULL)
		free(t_input);
	free(read_buffer);
	free_stack(h);
}
