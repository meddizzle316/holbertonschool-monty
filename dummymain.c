#include "monty.h"

int pn;
/**
 * main - entry point
 * @argc: number of given arguments
 * @argv: double pointer that has address of arguments
 *
 * Return: 1 if success, 0 or -1 if fail
 */
int main(int argc, char **argv)
{
	char *read_buffer = NULL;
	unsigned int i;
	int is_num = 0, is_spaces = 0, nl_removed = 0;
	size_t rd;
	char **t_input;
	stack_t *head = NULL;
	void (*f)(stack_t **, unsigned int line_number);
	
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1], &nl_removed, &rd);
		/* printf("value of nl_removed is %d\n", nl_removed); */
		if (read_buffer != NULL)
		{
			t_input = tokenize_file_input(read_buffer, (rd / 2));
			if (t_input == NULL)
			{
				free(read_buffer);
				return (-1);
			}
			for (i = 0; t_input[i]; i++)
			{
				is_spaces = all_spaces(t_input[i]);
				f = cmd_caller(t_input[i]);
				if (f)
				{
					/* printf("f is valid at token %d\n", i);  */ 
					if (!strncmp(t_input[i], "push", 4))
					{
						is_num = extract_number(t_input[i]);
						if (is_num == 1)
							f(&head, (i + 1));
						else
						{
							dprintf(2, "L%i: usage: push integer\n", i + 1 + (nl_removed / 2));
							free_all_and_exit(t_input, read_buffer, &head, 1);
						}
					}
					else
						f(&head, (i + 1));
				}
				else if ((is_spaces != 1)) 
				{
					t_input[i] = strtok(t_input[i], " ");
					dprintf(2, "L%i: unknown instruction %s\n", i + 1 + (nl_removed / 2),  t_input[i]);
					free_all_and_exit(t_input, read_buffer, &head, EXIT_FAILURE);
				}
				/* pall(&head, x); */
			}
			free_all(t_input, read_buffer, &head);
		}
		else
			exit(1);
	}
	else
	{
		dprintf(2, "USAGE: monty file\n");
		exit(1);
	}
	return (0);
}
