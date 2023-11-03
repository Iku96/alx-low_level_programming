#include <stdlib.h>
/**
 * _calloc - function
 * @nmemb: unsigned integer
 * Description: calloc allocator
 * Return: pointer
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char **array;
	int x, y;
	long unsigned int length;

	length = sizeof(int) * nmemb * size;
	array = malloc(length);
	y = 0;

	while(x < (int) length)
	{
		array[y] = 0;
		x += 4;
		y++;
	}

	return (array);
}
