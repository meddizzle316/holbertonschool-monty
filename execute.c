#include "monty.h"
/**
 * execute - a space saving function; stores main for loop
 * @t_input: tokenized read_buffer input by lines
 * @read_buffer: passed int read_buffer in case of freeing for errors
 * @nl_removed: int number of how many newlines were removed in get_file_input
 * @head: head to be passed in
 * Return: 1 if succeed, if it fails, won't return 0 but will exit program
 */
int execute(char **t_input, char *read_buffer, int nl_removed, stack_t **head)
{
	int i;
	int is_spaces = 0, is_num = 0;
	void (*f)(stack_t **, unsigned int line_number);
	int line;

	line = nl_removed / 2;
	for (i = 0; t_input[i]; i++)
	{
		is_spaces = all_spaces(t_input[i]);
		f = cmd_caller(t_input[i]);
		if (f)
		{
			/* printf ("f is valid at token %d\n", i); */
			if (!strncmp(t_input[i], "push", 4))
			{
				is_num = extract_number(t_input[i]);
				if (is_num == 1)
					f(head, (i + 1));
				else
				{
					dprintf(2, "L%i: usage: push integer\n", i + 1 + line);
					free_all_and_exit(t_input, read_buffer, head, 1);
				}
			}
			else
				f(head, (i + 1));
		}
		else if (is_spaces != 1)
		{
			t_input[i] = strtok(t_input[i], " ");
			dprintf(2, "L%i: unknown instruction %s\n", i + 1 + line,  t_input[i]);
			free_all_and_exit(t_input, read_buffer, head, EXIT_FAILURE);
		}
		/* pall (&head, i + 1); */
	}
	return (1);
}
