#include <ctype.h>
#include <stddef.h>
#include "monty.h"


/**
 * is_numeric - Checks if a string is numeric.
 * @str: The string to be checked.
 *
 * Return: 1 if the string is numeric, 0 otherwise.
 */
int is_numeric(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	for (; *str != '\0'; str++)
	{
		if (!isdigit(*str))
			return (0);
	}

	return (1);
}

/**
 *  _isdigit - checks if a string is all digits or not
 *
 *  @str: string to check
 *
 *  Return: 1 for digit, 0 if not
 */

int _isdigit(char *str)
{

	int i = 0;


	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}

	return (0);
}


/**
 *  _free - Free stack
 *
 *  @stack: Stack pointer
 *
 *  Return: Void
 */


void _free(stack_t *stack)
{
	if (stack)
	{
		_free(stack->next);
		free(stack);
	}
}
