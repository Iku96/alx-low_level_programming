#include <stdlib.h>

/**
 * array_range - function
 * @min: minimum number
 * @max: Maximum number
 * Description: ranging values of an array
 * Return: Pointer
 */

int *array_range(int min, int max)
{
	int *array = (int *) malloc(sizeof(int) * (max - min));
	int x;

	if (min > max || array == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < max - min; x++)
	{
		array[x] = min + x;
	}

	return (array);
}
