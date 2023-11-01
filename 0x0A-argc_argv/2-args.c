#include <stdio.h>

/**
 * main - Entry Point
 * @argc: arguments count
 * @argv: array pointing to arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
