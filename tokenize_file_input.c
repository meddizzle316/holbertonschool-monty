#include "main.h"
#include <string.h>

char *_strdup(const char *src);
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
	if (t_input == NULL)
	{
		free(t_input);
		return (NULL);
	}
	i = 0;
	token = strtok(file_input, " $\0\n");
	while (token != NULL)
	{
		t_input[i] = _strdup(token);
		token = strtok(NULL, " $\0\n");
		printf("The value of t_input at %d is %s and length is %lu\n", i, t_input[i], strlen(t_input[i]));
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

char *_strdup(const char *src)
{
	char *dst = malloc(strlen(src) + 1);

	if (dst == NULL) return NULL;
	strcpy(dst, src);
	return (dst);
}
