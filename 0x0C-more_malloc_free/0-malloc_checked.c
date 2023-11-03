#include <stdlib.h>
/**
 * malloc_checked - function
 * @b: unsigned integer
 * Description: malloc allocator
 * Return: pointer
 */

void *malloc_checked(unsigned int b)
{
	char *space;

	space = (char *) malloc(b);

	if (space == NULL)
	{
		exit(98);
	}

	return (space);
}
