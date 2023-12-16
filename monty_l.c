#include "monty.h"

/**
 * addNode - Adds a new node to the top of the stack
 * @stk: Pointer to the stack
 * @value: Value to be added
 * Return: Void
 */
void addNode(stack_t **stk, int value)
{
	stack_t *new_node, *current;

	current = *stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	if (current)
		current->prev = new_node;

	new_node->n = value;
	new_node->next = *stk;
	new_node->prev = NULL;
	*stk = new_node;
}

/**
 * addQueue - Adds a new node to the bottom of the stack
 * @stk: Pointer to the stack
 * @value: Value to be added
 * Return: Void
 */
void addQueue(stack_t **stk, int value)
{
	stack_t *new_node, *current;

	current = *stk;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;

	if (current)
	{
		while (current->next)
			current = current->next;
	}

	if (!current)
	{
		*stk = new_node;
		new_node->prev = NULL;
	}
	else
	{
		current->next = new_node;
		new_node->prev = current;
	}
}

