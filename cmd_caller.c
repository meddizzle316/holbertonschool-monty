#include "monty.h"
/**
 * cmd_caller -- function to call  commands using function pointers
 * @s: string to compare  to array
 *
 * Return: function pointer
 */

void (*cmd_caller(const char *s))(stack_t **stack, unsigned int line_number)
{
	int i, size;
	char *copied_s;
	char *token;

	instruction_t p[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"NULL", NULL},
	};
	i = 0;
	size = 7;
	copied_s = strdup(s);
	if (copied_s == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(1);
	}
	token = strtok(copied_s, " \r\n\v\f");
	while (token != NULL)
	{
		token = strtok(NULL, " \r\n\v\f");
	}
	while (i < size)
	{
		if (strncmp(p[i].opcode, copied_s, 5) == 0)
		{
			free(copied_s);
			return (p[i].f);
		}
		i++;
	}
	free(copied_s);
	return (p[i].f);
}
