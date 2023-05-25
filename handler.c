#include <string.h>
#include "monty.h"

#define BUFFER_SIZE 1024

char *argument = NULL;


/**
 * get_opcode_argument - Extracts the opcode and argument from a line of input.
 * @buffer: Line of input containing the opcode and argument.
 * @opcode: Pointer to store the extracted opcode.
 *
 * Return: 1 on success, 0 if opcode is empty or a comment.
 */
int get_opcode_argument(char *buffer, char **opcode)
{
	*opcode = strtok(buffer, " \t\n");

	if (*opcode == NULL || (*opcode)[0] == '#')
		return (0);

	argument = strtok(NULL, " \t\n");

	return (1);
}

/**
 * execute_opcode - Executes the corresponding function for an opcode.
 * @opcode: The opcode.
 * @stack: stack
 * @line_number: The line number of the opcode.
 *
 * Return: 1 if opcode is found and executed successfully, 0 otherwise.
 */
int execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (1);
		}
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * handler - Reads and interprets the Monty bytecode file.
 * @file: File pointer to the Monty bytecode file.
 */
void handler(FILE *file)
{
	char buffer[BUFFER_SIZE];
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		line_number++;

		if (!get_opcode_argument(buffer, &opcode))
			continue;


		if (!execute_opcode(opcode, &stack, line_number))
			exit(EXIT_FAILURE);
	}
}

