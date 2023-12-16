#include "monty.h"

/**
 * pop_top - Function removes the top element from the stack
 * @stk: Pointer to the stack
 * @ln: Line number
 * Return: Void
 */
void pop_top(stack_t **stk, unsigned int ln)
{
	stack_t *new;

	if (*stk == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}

	new = *stk;
	*stk = new->next;
	free(new);
}

