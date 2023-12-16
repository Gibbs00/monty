#include "monty.h"

/**
 * handle_error - Helper function to handle errors
 * @ln: Line number
 * @stk: Pointer to the head of the stack
 */
void handle_error(unsigned int ln, stack_t **stk)
{
	fprintf(stderr, "L%d: usage: push integer\n", ln);
	fclose(env.file);
	free(env.content);

	if (*stk != NULL)
	{
		free_stack(*stk);
	}

	exit(EXIT_FAILURE);
}

/**
 * _push - Function to add a node to the stack or queue
 * @stk: Pointer to the head of the stack
 * @ln: Line number
 */
void _push(stack_t **stk, unsigned int ln)
{
	size_t j;
	int y;

	if (!env.arg || !*env.arg)
	{
		if (*stk == NULL)
		{
			return;
		}

		handle_error(ln, stk);
	}

	for (j = (env.arg[0] == '-'); env.arg[j]; ++j)
	{
		if (!isdigit(env.arg[j]))
		{
			handle_error(ln, stk);
		}
	}

	y = atoi(env.arg);

	if (env.lifi == 0)
	{
		addNode(stk, y);
	}
	else
	{
		addQueue(stk, y);
	}
}

