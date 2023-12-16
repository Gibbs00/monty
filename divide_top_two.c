#include "monty.h"

/**
 * divide_top_two - Function divides the second
 * element by the top element
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void divide_top_two(stack_t **stk, unsigned int ln)
{
	stack_t *top, *next;
	int result;

	top = *stk;
	next = top->next;

	if (!top || !next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	if (top->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	result = next->n / top->n;
	next->n = result;
	*stk = next;
	free(top);
}

