#include "monty.h"

/**
 * rotate_left - Function rotates the stack to the left
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void rotate_left(stack_t **stk, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp = *stk, *auxiliary;

	if (*stk == NULL || (*stk)->next == NULL)
	{
		return;
	}

	auxiliary = (*stk)->next;
	auxiliary->prev = NULL;

	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}

	tmp->next = *stk;
	(*stk)->next = NULL;
	(*stk)->prev = tmp;
	(*stk) = auxiliary;
}

