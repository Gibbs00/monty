#include "monty.h"
/**
 * divide_top_two - Function divides the top two elements of the stack
 * @stk: Stack head
 * @ln: Line number
 * Return: Null
 */
void divide_top_two(stack_t **stk, unsigned int ln)
{
	stack_t *current;
	int size, result;

	size = 0;

	current = *stk;
	while (current)
	{
		current = current->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't divide_top_two, stack too short\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	current = *stk;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", ln);
		fclose(env.file);
		free(env.content);
		free_stack(*stk);
		exit(EXIT_FAILURE);
	}
	result = current->next->n / current->n;
	current->next->n = result;
	*stk = current->next;
	free(current);
}

