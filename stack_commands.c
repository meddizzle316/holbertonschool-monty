#include "monty.h"

/**
 * push -- my push function for stack of stack_t doubly linked lists
 * @head: double pointer to stack
 * @line_number: integer value for various operations
 *
 * Return: always void
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		dprintf(2, "error at %i", line_number);
		return;
	}
	new->n = pn;
	new->prev = NULL;
	new->next = *head;
	if (new->next != NULL)
	{
		new->next->prev = new;
	}
	*head = new;
}

/**
 * pop - my pop function for stack of stack_t doubly linked lists
 * @head: double pointer to stack/doubly linked list
 * @line_number: integer value for various operations
 *
 * Return: always void
 */
void pop(stack_t **head, unsigned int line_number)
{
	unsigned int *pointer;
	stack_t *current;

	pointer = &line_number;
	if (*head == NULL)
	{
		perror("stack is empty");
		exit(2);
	}
	current = *head;
	*head = current->next;
	if (current->next != NULL)
	{
		current->next->prev = NULL;
	}
	*pointer = (unsigned int)current->n;
	free(current);

}

/**
 * pall - my print all function for stack of stack_t doubly linked lists
 * @head: double pointer to stack/doubly linked list
 * @line_number: integer value for various operations
 *
 * Return: always void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	if (*head != NULL && line_number > 0)
	{
		current = *head;
		while (current != NULL)
		{
			printf("%d\n", current->n);
			current = current->next;
		}
	}
}

/**
 * pint: my print first in stack function
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
		dprintf(2, "L%i: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
}
