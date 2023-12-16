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
		dprintf(2, "L%i: can't pop an empty stack\n", line_number);
		exit(1);
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
/**
 * swap - my swap function; swaps first two elements in stack
 * @head: head of stack to swap elements
 * @line_number: line_number for error statement
 *
 * Return: always void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int tmp;

	if (*head != NULL && (*head)->next != NULL)
	{
		tmp = (*head)->next->n;
		(*head)->next->n = (*head)->n;
		(*head)->n = tmp;
	}
	else
	{
		dprintf(2, "L%i: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
}
