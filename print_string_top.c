#include "monty.h"

/**
 * print_string_top - Function prints the string from the top of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void print_string_top(stack_t **stk, unsigned int ln)
{
	stack_t *top;
	(void)ln;

	top = *stk;
	while (top)
	{
		if (top->n > 127 || top->n <= 0)
		{
			break;
		}
		printf("%c", top->n);
		top = top->next;
	}
	printf("\n");
}

