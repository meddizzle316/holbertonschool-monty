#include "monty.h"

int pn = 0;

int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;
	unsigned int i;
	unsigned int x;
	int new_line_removed = 0;
	stack_t *head = NULL;
	
	void (*f)(stack_t **, unsigned int line_number);

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1], &new_line_removed);
		if (read_buffer != NULL)
		{
			t_input = tokenize_file_input(read_buffer, 20);
			i = x = 0;
			while(t_input[i])
			{
				f = cmd_caller(t_input[i]);
				if (f)
				{
					x++;
					if (!strncmp(t_input[i], "push", 4) && t_input[i + 1])
					{
						extract_number(t_input[i + 1]);
						f(&head, x + new_line_removed);
					}
					else if ((!strncmp(t_input[i], "push", 4) && !t_input[i + 1]) || pn == -1)
					{
						pn = -1;
						f(&head, x + new_line_removed);
						free_array(t_input);
						free_stack(&head);
						exit(EXIT_FAILURE);
					}
					else
					{
						f(&head, x + new_line_removed);
					}
				
				}
				i++;
			}
			if (t_input)
			{
				free_array(t_input);
			}
			free_stack(&head);
		}

	}
	return (0);
}
