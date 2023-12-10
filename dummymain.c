#include "main.h"


int main(int argc, char** argv)
{
	char *read_buffer;
	char **t_input;

	read_buffer = NULL;
	if (argc == 2)
	{
		read_buffer = get_file_input(argv[1]);
		if (read_buffer != NULL)
		{
			printf("operation read_buffer was completed successfully\n");

			t_input = tokenize_file_input(read_buffer, 20);
			


			if (t_input)
			{
				free_array(t_input);
			}
		}

	}
	return (0);
}
