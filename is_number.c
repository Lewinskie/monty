#include "monty.h"

/**
 * is_number - Checks if a string is a number.
 * @str: The string to check.
 * Return: 1 if it's a number, 0 otherwise.
 */
int is_number(char *str)
{
	if (str == NULL)
		return (0);

	if (*str == '-')
		str++;

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}

	return (1);
}
