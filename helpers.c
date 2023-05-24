#include <ctype.h>
#include <stddef.h>


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
