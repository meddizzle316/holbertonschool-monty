#include "monty.h"
#include <string.h>
#include <ctype.h>
char *_strdup(const char *src);
char *trim_white_spaces(char *str);
/**
 * tokenize_file_input - tokenizes file input from given file
 * @file_input: buffer containing input
 *
 * Return: double pointer to array of tokenized strings
 */
char **tokenize_file_input(char *file_input, size_t new_buffer_size)
{
	char *token;
	int i;

	char **t_input;
	t_input = malloc(sizeof(char *) * new_buffer_size);
	if (t_input == NULL || new_buffer_size == 0)
	{
		free(t_input);
		return (NULL);
	}
	i = 0;
	/* file_input = trim_white_spaces(file_input); */
	if (file_input != NULL)
		token = strtok(file_input, "$\n");
	else
		token = NULL;
	while (token != NULL)
	{
		token = trim_white_spaces(token); 
		if (token != NULL)
		{
			t_input[i] = token;
			token = strtok(NULL, "$\n");
			/* printf("The value of t_input at %d is %s and length is %lu\n", i, t_input[i], strlen(t_input[i])); */
		}
		i++;
	}
	t_input[i] = NULL;
	return (t_input);
}

char *trim_white_spaces(char *str)
{
	char *end;

	while(isspace((unsigned char)*str)) str++;

	if (*str == 0) 
	 	return (str); 

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	end[1] = '\0';

	return (str);
}
