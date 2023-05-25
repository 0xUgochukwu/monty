#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element
 *       of the stack by the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}


/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if ((stack == NULL) || (*stack == NULL))
	{
		printf("\n");
	}
	else
	{
		while (current != NULL)
		{
			if ((current->n > 0) && current->n > 0 &&
					current->n < 127)
			{
				printf("%c", current->n);
				current = current->next;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	}
}

