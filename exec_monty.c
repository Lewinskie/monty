#include "monty.h"

/**
 * execute_monty_code - Executes Monty code from a file.
 * @file: The file containing Monty code.
 */
void execute_monty_code(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	int read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode, *arg;

	while ((read = getline(&line, &len, file) != -1))
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode == NULL || opcode[0] == '#')
			continue;

		arg = strtok(NULL, " \t\n");
		if (arg != NULL && is_number(arg))
			push(&stack, atoi(arg));

		if (strcmp(opcode, "pall") == 0)
			pall(&stack, line_number);
	}

	free_stack(&stack);
	free(line);
}
