#include "monty.h"
#include <string.h>
#include <ctype.h>
char *_strdup(const char *src);
char *trim_white_spaces(char *str);
/**
 * tokenize_file_input - tokenizes file input from given file
 * @file_input: buffer containing input
 * @new_buffer_size: size to create new buffer
 * Return: double pointer to array of tokenized strings
 */
char **tokenize_file_input(char *file_input, size_t new_buffer_size)
{
	char *token;
	int i;
	char **t_input;

	t_input = malloc(sizeof(char *) * new_buffer_size);
	if (t_input == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		return (NULL);
	}
	i = 0;
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
		}
		i++;
	}
	t_input[i] = NULL;
	return (t_input);
}
/**
 * trim_white_spaces - trims leading and trailing white spaces in given buffer
 * @str: given buffer to remove white spaces from
 *
 * Return: pointer to string without leadign and trailing white spaces
 */
char *trim_white_spaces(char *str)
{
	char *end;

	if (str != NULL)
	{
		while (isspace((unsigned char)*str))
			str++;
		if (*str == 0)
			return (str);
		end = str + strlen(str) - 1;
		while (end > str && isspace((unsigned char)*end))
			end--;
		end[1] = '\0';
	}
	return (str);
}
