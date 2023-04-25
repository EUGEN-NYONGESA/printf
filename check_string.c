#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _strlen - returns length of a string
 *
 * @s: string to calculate
 *
 * Return: string length
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * _puts - writes string to the output, stdout
 * @s: string to output
 *
 * Return: string
 */
int _puts(char *s)
{
	long int len;

	while (*s)
	{
		write(1, s, 1);
		len++;
		s++;
	}
	return (len);
}

/**
 * check_puts - checks if the string format is puts
 * @s: string to check
 *
 * Return: 1 if puts, 0 of not
 */
int check_puts(char *s)
{
	if (s[0] == '%' && s[1] == 's' && s[2] == '\n' && s[3] == 0)
		return (1);
	return (0);
}
