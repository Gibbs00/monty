#include "monty.h"

/**
 * print_top - Function prints top of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void print_top(stack_t **stk, unsigned int ln)
{
	if (*stk == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stk)->n);
}

