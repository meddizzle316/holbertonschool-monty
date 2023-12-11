#include "monty.h"
/**
 * cmd_caller -- function to call  commands using function pointers
 * @string: string to compare  to array
 *
 * Return: function pointer
 */

void (*cmd_caller(const char *s))(stack_t **stack, unsigned int line_number)
{
	int i, size;

	instruction_t p[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"0", NULL},
	};

	i = 0;
	size = 2;

	while (strncmp(p[i].opcode, s, 4) != 0 && i < size) /*compare operation is poopy, only does first letter comparison */
	{
		i++;
	}
	return (p[i].f);
}
