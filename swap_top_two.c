#include "monty.h"

/**
 * swap_top_two - Function swaps the top two elements of the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void swap_top_two(stack_t **stk, unsigned int ln)
{
	stack_t *top, *next;
	int temp;

	if (*stk == NULL || (*stk)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	top = *stk;
	next = top->next;
	temp = top->n;

	top->n = next->n;
	next->n = temp;
}

