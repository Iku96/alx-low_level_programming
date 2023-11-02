#include <stdio.h>
#include <stdlib.h>

/*
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 *
 * This program takes one argument, a number representing the number of bytes
 * of the main function to print in hexadecimal. It will print the opcodes of
 * the main function in lowercase, two characters per opcode. Each opcode is
 * separated by a newline. If the number of arguments is not correct, it will
 * print "Error" followed by a newline and exit with status 1. If the number of
 * bytes is negative, it will print "Error" followed by a newline and exit with
 * status 2.
 */
int main(int argc, char *argv[])
{
	int i, j, num_bytes;
	unsigned char *main_addr = (unsigned char *)main;

	if (argc != 2)
	{
		puts("Error");
		return (1);
	}
	num_bytes = atoi(argv[1]);
	if (num_bytes < 0)
	{
		puts("Error");
		return (2);
	}
	for (i = 0; i < num_bytes; i++)
	{
		printf("%.2x", main_addr[i]);
		if ((i + 1) < num_bytes)
			putchar('\n');
	}
	putchar('\n');
	return (0);
}
