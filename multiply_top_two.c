#include "monty.h"

/**
 * multiply_top_two - Function multiplies the top two elements of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void multiply_top_two(stack_t **stk, unsigned int ln)
{
	stack_t *top, *next;
	int result;

	top = *stk;
	next = top->next;

	if (!top || !next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	result = next->n * top->n;
	next->n = result;
	*stk = next;
	free(top);
}

