#include "monty.h"

int pn = 0;

int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;
	unsigned int i;
	unsigned int x;
	int is_num;
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
			i = 0;
			x = 1;
			while(t_input[i])
			{
				f = cmd_caller(t_input[i]);
				if (f)
				{
					x++;
					if (!strncmp(t_input[i], "push", 4) && t_input[i + 1])
					{
						is_num = extract_number(t_input[i + 1]);
						if (is_num == 1)
						{
							i++;
							f(&head, x);
						}
					}
					if ((!strncmp(t_input[i], "push", 4) && !t_input[i + 1]) || pn == -1)
					{
						pn = -1;
						f(&head, x);
						free_array(t_input);
						free_stack(&head);
						exit(EXIT_FAILURE);
					}
					else
					{
						f(&head, x);
					}
				
				}
				else if ((is_num = extract_number(t_input[i]) != 1)) 
				{
					dprintf(2, "L%i: unknown instruction %s\n", x, t_input[i]);
					free_array(t_input);
					free_stack(&head);
					exit(EXIT_FAILURE);
				}
				i++;
			}
			if (t_input)
			{
				free_array(t_input);
			}
			free_stack(&head);
		}
		else
		{
			exit(1);
		}

	}
	else
	{
		dprintf(2, "USAGE: monty file\n");
		exit(1);
	}
	return (0);
}
