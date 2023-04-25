#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _num - numeric string to be printed
 *
 * @s: string to be printed
 * @spec: specifier
 *
 * Return: char * to new string
 */
char *_num(char *s, specifier spec)
{
	char *ret, *pt, *i = s;
	unsigned int len, d, j = 0;
	char k = ' ', m = 0;

	if (s == NULL)
	{
		free(i);
		return (NULL);
	}
	if (spec.specifier == 'p' && *s == 0)
	{
		free(i);
		return (nil());
	}
	if (spec.specifier == 'b' || spec.specifier == 'x' ||
	    spec.specifier == 'X' || spec.specifier == 'p')
		j = 1;
	if (spec.specifier == 'p')
		spec.specifier = 'x';
	d = _strlen(s);
	len = d;
	if (spec.n == 1 && spec.just == 0 && spec.flagp == 0)
		fill = '0';

	if (*s == '-')
	{
		s++;
		m = '-';
		d--;
		len--;
	}
	else if (spec.sign == 1 && (spec.specifier == 'd' || spec.specifier == 'i'))
	{
		m = '+';
	}
	else if (spec.sp == 1 && (spec.specifier == 'd' || spec.specifier == 'i'))
	{
		m = ' ';
	}
	if (len < spec.precision)
		len = spec.precision;
	if (m)
		len++;
	if (spec.ln == 1 && j == 1)
		len += 2;
	else if (spec.ln == 1 && spec.specifier == 'o')
	{
		if (spec.precision <= d)
			spec.precision = d + 1;
		len = spec.precision;
		spec.ln = 0;
	}
	else
		spec.ln = 0;
	if (spec.width > len)
	{
		if (spec.precision == len && m)
			spec.width--;
		spec.width -= len;
		len += spec.width;
	}
	else
		spec.width = 0;

	if (m)
		len++;
	ret = malloc((len + 1) * sizeof(char));
	if (ret == NULL)
	{
		free(i);
		return (NULL);
	}
	pt = ret;
	if (spec.ln == 1 && (k == '0' || spec.just == 1) && *s)
	{
		*pt++ = '0';
		if (j)
			*pt++ = spec.specifier;
	}
	if (k == '0' && m)
		*pt++ = m;
	while (spec.just == 0 && spec.width--)
		*pt++ = k;
	if (k == ' ' && spec.ln == 1 && spec.just == 0 && (*s))
	{
		*pt++ = '0';
		if (j)
			*pt++ = spec.specifier;
	}
	if (k != '0' && m)
		*pt++ = m;
	while (spec.precision-- > d)
		*pt++ = '0';
	while (*s)
		*pt++ = *s++;
	while (spec.just == 1 && spec.width--)
		*pt++ = ' ';
	*pt = 0;
	free(i);
	return (ret);
}

/**
 * _str - string to be printed
 *
 * @str: string
 * @spec: specifier info
 *
 * Return: char * to new string
 */
char *_str(char *str, specifier spec)
{
	char *ret, *pt, *i = str;
	unsigned int len;

	if (str == NULL)
	{
		if (spec.specifier != 's' && spec.specifier != 'c')
			free(i);
		return (null());
	}
	len = _strlen(str);
	if (spec.specifier == 'c' && *str == 0)
		len++;
	if (len > spec.precision && spec.flagp == 1)
		len = spec.precision;

	if (len < spec.width && spec.flagw == 1)
	{
		ret = malloc((spec.width + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(i);
			return (NULL);
		}
		pt = ret;
		if (spec.just == 0)
		{
			while (len < spec.width--)
				*pt++ = ' ';
			while (len--)
				*pt++ = *str++;
			*pt = 0;
		}
		else
		{
			spec.width -= len;
			while (len--)
				*pt++ = *str++;
			while (spec.width--)
				*pt++ = ' ';
			*pt = 0;
		}
	}
	else
	{
		ret = malloc((len + 1) * sizeof(char));
		if (ret == NULL)
		{
			if (spec.specifier != 's' && spec.specifier != 'c')
				free(i);
			return (NULL);
		}
		pt = ret;
		while (len--)
			*pt++ = *str++;
		*pt = 0;
	}
	if (spec.specifier != 's' && spec.specifier != 'c')
		free(i);
	return (ret);
}
