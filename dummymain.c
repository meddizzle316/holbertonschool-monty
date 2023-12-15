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
	int nl_removed = 0;
	size_t rd;
	char **t_input;
	stack_t *head = NULL;

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
			execute(t_input, read_buffer, nl_removed, &head);
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
