#include "monty.h"

/**
 * print_stack - Function prints stack values
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void print_stack(stack_t **stk, unsigned int ln)
{
	stack_t *new;

	(void)ln;

	new = *stk;
	if (new == NULL)
	{
		/* Stack is empty, handle accordingly*/
		return;
	}

	/* Continue with the loop to print stack values*/
	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
}

