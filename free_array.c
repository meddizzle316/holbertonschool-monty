#include "monty.h"
/**
 * free_array - function to free array
 * @array: array to be freed
 *
 * Return: always void
 */
void free_array(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
