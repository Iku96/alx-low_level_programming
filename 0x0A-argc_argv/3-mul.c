#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 * @argc: arguments count
 * @argv: array pointing to arguments
 * Return: 0 if correct input, 1 otherwise
 */
int main(int argc, char *argv[])
{
	int a;
	int b;
	int result;
	
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	a = atoi(argv[1]);
	b = atoi(argv[2]);
	result = a * b;
	printf("%d\n", result);
	return (0);
}
