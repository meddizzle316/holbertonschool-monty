#include "monty.h"

int pn = 0;

int main(int argc, char** argv)
{
	char *read_buffer;
	unsigned int i;
	int is_num;
	int is_spaces;
	size_t rd;
	char **t_input;
	int nl_removed = 0;
	stack_t *head = NULL;
	
	void (*f)(stack_t **, unsigned int line_number);

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1], &nl_removed, &rd);
		/* printf("value of nl_removed is %d\n", nl_removed); */
		if (read_buffer != NULL)
		{
			t_input = tokenize_file_input(read_buffer, (rd / 3));
			i = 0;
			while(t_input[i])
			{
				is_num = 0;
				is_spaces = all_spaces(t_input[i]);
				f = cmd_caller(t_input[i]);
				if (f)
				{
					/* printf("f is valid at token %d\n", i); */ 
					if (!strncmp(t_input[i], "push", 4))
					{
						is_num = extract_number(t_input[i]);
						if (is_num == 1)
						{
							f(&head, (i + 1));
						}
						else
						{
							dprintf(2, "L%i: usage: push integer\n", i + 1 + (nl_removed / 2));
							free(t_input);
							free(read_buffer);
							free_stack(&head);
							exit(1);
						}
					}
					else
					{
						f(&head, (i + 1));
					}
				}
				else if ((is_spaces != 1)) 
				{
					t_input[i] = strtok(t_input[i], " ");
					dprintf(2, "L%i: unknown instruction %s\n", i + 1 + (nl_removed / 2),  t_input[i]);
					free(t_input);
					free_stack(&head);
					free(read_buffer);
					exit(EXIT_FAILURE);
				}
				/* pall(&head, x); */
				i++;
			}
			if (t_input)
			{
				free(t_input);
			}
			free_stack(&head);
			free(read_buffer);
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
