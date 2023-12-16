#include "monty.h"

/**
 * rotate_right - Function rotates the stack to the right
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void rotate_right(stack_t **stk, __attribute__((unused)) unsigned int ln)
{
	stack_t *dup;

	dup = *stk;
	if (*stk == NULL || (*stk)->next == NULL)
	{
		return;
	}

	while (dup->next)
	{
		dup = dup->next;
	}

	dup->next = *stk;
	dup->prev->next = NULL;
	dup->prev = NULL;
	(*stk)->prev = dup;
	(*stk) = dup;
}

