#include "main.h"

/**
 * _puts - prints a string with a newline
 * @str: string to print
 *
 * Return: void
 */
int _puts(char *str)
{
	int i = 0;
	while (str[i])
	{
		_putchar(str[i]);
		str++;
	}
	return (str - str[0]);
}

/**
 * _putchar - writes the character to stdout
 * @c: the character to print
 *
 * Return: 1 on success and -1 on failure
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

