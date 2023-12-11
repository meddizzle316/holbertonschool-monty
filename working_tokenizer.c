#include "monty.h"
#include <string.h>
#include <ctype.h>
char *_strdup1(const char *src);
char *trim_white_spaces1(char *str);
/**
 * tokenize_file_input - tokenizes file input from given file
 * @file_input: buffer containing input
 *
 * Return: double pointer to array of tokenized strings
 */
char **tokenize_file_input1(char *file_input, size_t new_buffer_size)
{
	char *token;
	int i;

	char **t_input;
	t_input = malloc(sizeof(char *) * new_buffer_size);
	if (t_input == NULL)
	{
		free(t_input);
		return (NULL);
	}
	i = 0;
	file_input = trim_white_spaces1(file_input);
	token = strtok(file_input, "$");
	while (token != NULL)
	{
		token = trim_white_spaces1(token); 
		if (token != NULL)
		{
			t_input[i] = strdup(token);
			token = strtok(NULL, "$");
			printf("The value of t_input at %d is %s and length is %lu\n", i, t_input[i], strlen(t_input[i]));
		}
		i++;
	}
	free(file_input);
	t_input[i] = NULL;
	return (t_input);
}
/**
 * _strdup - a copy of strdup, throws errors if I don't do this
 * @src: source string to be duplicated
 *
 * Return: a pointer to a newly malloc'd duplicate of src
 */

char *_strdup1(const char *src)
{
	char *dst = malloc(strlen(src) + 1);

	if (dst == NULL) return NULL;
	strcpy(dst, src);
	return (dst);
}

char *trim_white_spaces1(char *str)
{
	char *end;

	while(isspace((unsigned char)*str)) str++;

	if (*str == 0)
		return (NULL);

	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)*end)) end--;

	end[1] = '\0';

	return (str);
}
