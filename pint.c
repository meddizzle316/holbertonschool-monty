#include "monty.h"
/**
 * pint - my print first in stack function
 * @head: double pointer to stack
 * @line_number: integer value for various operations
 *
 * Return: always void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head != NULL)
		printf("%d\n", (*head)->n);
	else
	{
		dprintf(2, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
