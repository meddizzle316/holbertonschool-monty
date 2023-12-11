#include "monty.h"


int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;
	int i;
	char *endptr = NULL;
	long result;
	stack_t *head = NULL;
	
	void (*f)(stack_t **, unsigned int line_number);

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1]);
		if (read_buffer != NULL)
		{
			printf("operation read_buffer was completed successfully\n");

			t_input = tokenize_file_input(read_buffer, 20);
			i = 0;
			while(t_input[i])
			{
				f = cmd_caller(t_input[i]);
				i++;
				if (f)
				{
					printf("f is valid\n");
					result = strtol(t_input[i], &endptr, 10);
					if (*endptr == '\0')
					{
						printf("string to int conversion successful\n");
						f(&head, (unsigned int)result);
						i++;
					}
				}
			}

			pall(&head, 45);
			if (t_input)
			{
				free_array(t_input);
			}
		}

	}
	return (0);
}
