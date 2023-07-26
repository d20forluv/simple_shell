#include "shell.h"

/**
 * main - main file
 * @ac: Number of arguments passed
 * @argv: arrays of pointers to the argument
 *
 * Return: 0 on success
 */
int main(int ac __attribute__((unused)), char *argv[])
{
	hsh(argv[0]);
	return (0);
}
