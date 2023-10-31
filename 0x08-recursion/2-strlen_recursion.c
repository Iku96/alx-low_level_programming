#include "main.h"
/**
 * _strlen_recursion - Returns length of the string
 * @s: the string to be measured
 * Return: The length of the strinig
 */

/* main.c */

#include "main.h"

int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
