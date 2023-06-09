#include "monty.h"


/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - Doesn't do anything.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}



/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - Divides the second top element by the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Current line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		_free(*stack);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

