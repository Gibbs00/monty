#include "monty.h"

/**
 * set_stack_mode - Sets the stack mode to LIFO (Last In, First Out)
 * @stk: Pointer to the stack
 * @ln: Line number (unused)
 * Return: Void
 */
void set_stack_mode(stack_t **stk, __attribute__((unused)) unsigned int ln)
{
	(void)stk;
	(void)ln;
	env.lifi = 1;
}

/**
 * set_queue_mode - Sets the stack mode to FIFO (First In, First Out)
 * @stk: Pointer to the stack
 * @ln: Line number (unused)
 * Return: Void
 */
void set_queue_mode(stack_t **stk, __attribute__((unused)) unsigned int ln)
{
	(void)stk;
	(void)ln;
	env.lifi = 0;
}

