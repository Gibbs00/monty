#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]);
MontyEnv_t env;

/**
 * main - Monty language interpreter
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t buffer_size = 0;
	ssize_t line_read = 1;
	stack_t *stk = NULL;
	unsigned int ln = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	env.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (line_read > 0)
	{
		content = NULL;
		line_read = getline(&content, &buffer_size, file);
		env.content = content;
		ln++;

		if (line_read > 0)
		{
			exec_c(content, &stk, ln, file);
		}

		free(content);
	}

	free_stack(stk);
	fclose(file);

	return (0);
}

