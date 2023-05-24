#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: current line number
 */
void push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!argument || _isdigit(argument) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(argument);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}


/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: current line number
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}


/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

