#include "monty.h"
/**
 * free_stack - frees a dlistint_t list
 * @head: head of list
 * Return: always void
 */
void free_stack(stack_t **head)
{
	stack_t *tmp;
	stack_t *current;

	if (*head)
	{
		current = *head;
		while (current != NULL)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
	}
}
