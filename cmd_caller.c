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
		{"-1", NULL},
	};

	i = 0;
	size = 3;

	while (i < size)
	{
		if (strncmp(p[i].opcode, s, 5) == 0) /*compare operation is poopy, only does first letter comparison */
		{
			return (p[i].f);	
		}
		/* printf("command caller: match failed -- incrementing %d to %d\n", i, i + 1); */
		i++;
	}
	return (p[i].f);
}
