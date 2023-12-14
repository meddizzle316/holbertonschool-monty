#include "monty.h"

extern int pn;
/**
 * push -- my push function for stack of stack_t doubly linked lists
 * @value: value of new node
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
		exit(2);
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
