#include "monty.h"

/**
 * pchar_top - Function prints character from the top of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void pchar_top(stack_t **stk, unsigned int ln)
{
	stack_t *top;

	top = *stk;
	if (!top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	if (top->n > 127 || top->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", top->n);
}

