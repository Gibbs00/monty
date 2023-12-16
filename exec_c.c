#include "monty.h"
int exec_c(char *content, stack_t **stk, unsigned int ln, FILE *file);

/**
 * exec_c - Function executes the opcode
 * @content: Content
 * @stk: Stack head
 * @ln: Line number
 * @file: Monty file
 * Return: 0 on success, 1 on failure
 */
int exec_c(char *content, stack_t **stk, unsigned int ln, FILE *file)
{
	instruction_t opst[] = {
		{"push", _push},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"swap", swap_top_two},
		{"add", add_top_two},
		{"nop", do_nothing},
		{"sub", subtract_top_two},
		{"div", divide_top_two},
		{"mul", multiply_top_two},
		{"mod", compute_modulo},
		{"pchar", pchar_top},
		{"pstr", print_string_top},
		{"rotl", rotate_left},
		{"rotr", rotate_right},
		{"queue", set_queue_mode},
		{"stack", set_stack_mode},
		{NULL, NULL},
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (!op || op[0] == '#')
		return (0);

	env.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stk, ln);
			return (0);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", ln, op);
	fclose(file);
	free(content);
	free_stack(*stk);
	exit(EXIT_FAILURE);
	return (1);
}

