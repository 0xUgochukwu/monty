#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define BUFFER_SIZE 1024

void handler(FILE *file)
{
	char buffer[BUFFER_SIZE];
	char *opcode, *argument;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (fgets(buffer, BUFFER_SIZE, file) != NULL)
	{
		line_number++;
		opcode = strtok(buffer, " \t\n$");

		if (opcode == NULL || opcode[0] == '#')
			continue; /* Ignore empty lines and comments */

		argument = strtok(NULL, " \t\n$");

		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL || !is_numeric(argument))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}

			push(&stack, atoi(argument));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}
