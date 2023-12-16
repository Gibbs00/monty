#include "monty.h"

/**
 * add_top_two - Adds the top two elements of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 */
void add_top_two(stack_t **stk, unsigned int ln)
{
	stack_t *top;
	stack_t *next;
	int sum;

	if (*stk == NULL || (*stk)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	top = *stk;
	next = top->next;
	sum = top->n + next->n;

	next->n = sum;
	*stk = next;
	free(top);
}

