#include <stdlib.h>
#include <string.h>

/**
 * malloc_checked - function
 * @s1: first string
 * @s2: second string
 * @n: n spaces
 * Description: string concatenator
 * Return: pointer
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *allocated;
	unsigned int length, x, y;

	length = strlen(s1) + n + 1;

	allocated = (char *) malloc(length);

	for (x = 0; x < strlen(s1); x++)
	{
		allocated[x] = s1[x];
	}

	for (y = 0; y < n; y++)
	{
		allocated[x + y] = s2[y];
	}
	allocated[x + y + 1] = '\0';

	return (allocated);
}
