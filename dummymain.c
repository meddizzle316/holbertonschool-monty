#include "monty.h"

int pn = 0;

int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;
	unsigned int i;
	unsigned int x;
	int is_num;
	size_t rd;
	int new_line_removed = 0;
	stack_t *head = NULL;
	
	void (*f)(stack_t **, unsigned int line_number);

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1], &new_line_removed, &rd);
		if (read_buffer != NULL)
		{
			t_input = tokenize_file_input(read_buffer, (rd / 3));
			i = 0;
			x = 0;
			while(t_input[i])
			{
				is_num = 0;
				f = cmd_caller(t_input[i]);
				if (f)
				{
					/* printf("f is valid at token %d\n", i); */
					x++;
					is_num = extract_number(t_input[i + 1]);
					if (!strncmp(t_input[i], "push", 4) && is_num == 1)
					{
						/* printf("is num operation successful\n"); */ 
						i++;
						f(&head, (x + new_line_removed));
					}
					else if ((!strncmp(t_input[i], "push", 4) && is_num == -1))
					{
						/* printf("is_num operation failed\n"); */
						f(&head, (x + new_line_removed));
						free_array(t_input);
						free_stack(&head);
						exit(1);
					}
					else
					{
						f(&head, (x + new_line_removed));
					}
				
				}
				else if ((is_num = extract_number(t_input[i]) != 1)) 
				{
					dprintf(2, "L%i: unknown instruction %s\n", x, t_input[i]);
					free_array(t_input);
					free_stack(&head);
					exit(EXIT_FAILURE);
				}
				pall(&head, x);
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
