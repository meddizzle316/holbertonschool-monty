#include "monty.h"
/**
 * all_spaces - checks to see if given buffer is all spaces
 * @string: given buffer
 *
 * Return: 1 if all spaces, 0 if not
 */
int all_spaces(char *string)
{
	while(isspace((unsigned char)*string)) string++;

	if (*string == 0)
		return (1);
	else
		return (0);
}
