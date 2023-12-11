#include "monty.h"

int push_number = 0;

int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;
	unsigned int i;
	char *p;
	stack_t *head = NULL;
	
	void (*f)(stack_t **, unsigned int line_number);

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1]);
		if (read_buffer != NULL)
		{
			t_input = tokenize_file_input_2(read_buffer, 20);
			i = 1;
			while(t_input[i])
			{
				f = cmd_caller(t_input[i]);
				if (f)
				{
					if (!strncmp(t_input[i], "push", 4))
					{
						p = t_input[i];
						while (*p)
						{
							if(isdigit(*p) || ((*p =='-' || *p=='+') && isdigit(*(p + 1))))
							{
								push_number = (int)strtol(p, &p, 10);
								break;
							}
							else
							{
								p++;
							}
							push_number = -1;
						}
						f(&head, i);
					/*	pall(&head, i); */
					}
					else
					{
						f(&head, i);
					}
				
				}
				i++;
			}
			if (t_input)
			{
				free_array(t_input);
			}
		}

	}
	return (0);
}
