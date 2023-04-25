#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * int_string - converts integer to string
 * @arg: argument
 * Return: string
 */
char *int_string(va_list arg)
{
	int c = 0;
        int i, k;
        int j = 0;
	int d = va_arg(arg, int); c, i, j, k, l;
	char *m;

	if (d < 0)
	{
		j = 1;
		c++;
	}
	while (dt != 0)
	{
		dt /= 10;
		c++;
	}
	m = malloc(sizeof(char) * c + 1);
	if (m == NULL)
		return (NULL);
	if (j)
		m[0] = '-';
	dt = d;
	for (i = c - 1; i >= 0 + j; i--)
	{
		k = dt % 10;
		m[i] = (k < 0 ? -k : k) + '0';
		dt /= 10;
	}
	m[c] = '\0';
	return (m);

}
/**
 * to_string - converts long integer to string
 * @arg: argument
 * Return: string
 */
char *to_string(va_list arg)
{
	int c = 0;
	int i, k;
	int j = 0;
	long int d = va_arg(arg, long int);
	dt = d;
	char *m;

	if (d < 0)
	{
		j = 1;
		c++;
	}
	while (dt != 0)
	{
		dt /= 10;
		c++;
	}
	m = malloc(sizeof(char) * c + 1);
	if (m == NULL)
		return (NULL);
	if (j)
		output[0] = '-';
	dt = digits;
	for (i = c - 1; i >= 0 + j; i--)
	{
		k = dt % 10;
		m[i] = (k < 0 ? -k : k) + '0';
		dt /= 10;
	}
	m[c] = '\0';
	return (m);

}
/**
 * int_to_string - converts short integer to string
 * @arg: argument
 * Return: string
 */
char *int_to_string(va_list arg)
{
	int c = 0;
	int i, k;
	int j = 0;
	short int d = va_arg(arg, int);
	dt = d;
	char *m;

	if (d < 0)
	{
		j = 1;
		c++;
	}
	while (dt != 0)
	{
		dt /= 10;
		c++;
	}
	m = malloc(sizeof(char) * c + 1);
	if (m == NULL)
		return (NULL);
	if (j)
		m[0] = '-';
	dt = d;
	for (i = c - 1; i >= 0 + j; i--)
	{
		k = dt % 10;
		m[i] = (k < 0 ? -k : k) + '0';
		dt /= 10;
	}
	m[c] = '\0';
	return (m);

}
/**
 * int_tostring - converts integer to string (short short)
 * @arg: argument
 * Return: string
 */
char *int_tostring(va_list arg)
{
	int c = 0;
	int i, k;
	int j = 0;
	char d = (char) va_arg(arg, int);
	dt = d;
	char *m;
	
	if (d < 0)
	{
		j = 1;
		c++;
	}
	while (dt != 0)
	{
		dt /= 10;
		c++;
	}
	m = malloc(sizeof(char) * c + 1);
	if (m == NULL)
		return (NULL);
	if (j)
		output[0] = '-';
	dt = d;
	for (i = c - 1; i >= 0 + j; i--)
	{
		k = dt % 10;
		m[i] = (k < 0 ? -k : k) + '0';
		dt /= 10;
	}
	m[c] = '\0';
	return (m);

}
