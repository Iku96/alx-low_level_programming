#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry Point
 * @argc: arguments count
 * @argv: array pointing to arguments
 * Return: 0 if correct input, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int i, result = 0, len, j;
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		len = strlen(argv[i]);
		for (j = 0; j < len; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		result += atoi(argv[i]);
	}
	printf("%d\n", result);
	return (0);
}
