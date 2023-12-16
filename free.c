#include "monty.h"

/**
 * free_stack - Frees a linked list
 * @stk: Pointer to the head of the list
 */
void free_stack(stack_t *stk)
{
	stack_t *auxiliary;

	auxiliary = stk;
	while (stk)
	{
		auxiliary = stk->next;
		free(stk);
		stk = auxiliary;
	}
}

