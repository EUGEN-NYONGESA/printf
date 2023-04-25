#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * buffer_char - puts format characters in buffer
 *
 * @f: string format
 * @b: buffer output
 * @len: current buffer length
 *
 * Return: number of buffer chars
 */
int buffer_char(char **f, char *b, unsigned int *len)
{
	int i = 0;

	while (**f != 0 && **f != '%')
	{
		b[(*len)++] = **f;
		(*f)++;
		if (*len == 1024)
		{
			write(1, b, 1024);
			*len = 0;
			i += 1024;
		}
	}
	return (i);

/**
 * string - Returns a string
 *
 * @arg: arguments
 * @spec: struct of specifier
 * @free: incase we need to free a malloc
 *
 * Return: string to add to buffer
 */
char *string(va_list arg, specifier spec, unsigned int *free)
{
	static char str[2] = {0, 0};
	char *t;

	switch (spec.specifier)
	{
		case 'n':
			str[0] = 0;
			return (str);
		case '%':
			str[0] = '%';
			return (str);
		case 'c':
			str[0] = (char) va_arg(arg, int);
			*free = 1;
			return (_str(str, spec));
		case 's':
			*free = 1;
			t = va_arg(arg, char*);
			return (_str(t, spec));
		case 'd':
		case 'i':
			*free = 1;
			if (spec.length == 1)
				return (_num(to_string(arg), spec));
			if (spec.length == -1)
				return (_num(int_to_string(arg), spec));
			if (spec.length < -1)
				return (_num(int_tostring(arg), spec));
			return (_num(int_string(arg), spec));
	}
	return (NULL);
}

/**
 * _specifier - gets specifier information
 *
 * @format: format string
 * @list: argument list passed to printf
 *
 * Return: specifier struct with info
 */
specifier _specifier(char **format, va_list list)
{
	specifier spec;
	char *s;

	s = *format;
	spec.just = 0, spec.sign = 0, spec.sp = 0;
	spec.ln = 0, spec.n = 0;
	while (**format == '-' || **format == '+' || **format == ' '
	       || **format == '#' || **format == '0')
	spec.width = 0;	spec.flagw = 0;
	if (**format == '*')
	{
		spec.flagw = 1;
		spec.width = va_arg(list, int);
		(*format)++;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			spec.flagw = 1;
			spec.width *= 10;
			spec.width += **format - '0';
			(*format)++;
		}
	}
	spec.precision = 1; spec.flagp = 0;
	if (**format == '.')
	{
		spec.flagp = 1;
		spec.precision = 0;
		(*format)++;
		if (**format == '*')
		{
			spec.precision = va_arg(list, int);
			(*format)++;
		}
		else
		{
			while (**format >= '0' && **format <= '9')
			{
				spec.precision *= 10;
				spec.precision += **format - '0';
				(*format)++;
			}
		}
	} 
spec.length = 0;
	while (**format == 'h')
	{
		(*format)++;
		if (spec.length > -2)
			spec.length--;
		else
			spec.length = 10;
	}
	while (**format == 'l')
	{
		(*format)++;
		if (spec.length >= 0)
			spec.length = 1;
		else
			spec.length = 10;
	{
		if (**format == '-')
			spec.just = 1;
		else if (**format == '+')
			spec.sign = 1;
		else if (**format == ' ')
			spec.sp = 1;
		else if (**format == '#')
			spec.ln = 1;
		else
			spec.n = 1;
		(*format)++;
	}
	spec.specifier = **format;
	if (**format == 'p')
		spec.ln = 1;
	if (spec.length == 10)
		spec.specifier = 'z';
	switch (spec.specifier)
	{
	case '%': case 's': case 'c': case 'i': case 'd':
			(*format)++;
		break;
	case 0:
		spec.specifier  = 'y';
		if (spec.length == 0)
			break;
	default:
		*format = s;
		if (spec.length != 0)
			(*format)++;
		spec.specifier = '%';
		break;
	}
	return (spec);
}

/**
 * _printf - prints formatted string
 *
 * @format: format string
 *
 * Return: printed characters
 */
int _printf(char *format, ...)
{
	char *t = 0, *p = 0, buffer[1024];
	unsigned int len =  0, k = 0, m;
	unsigned int i = 0;
	int j = 0;
	va_list l;
	specifier s;

	t = buffer;
	if (format == NULL)
		return (-1);
	va_start(l, format);
	if (check_puts(format))
	{
		i = puts(va_arg(l, char *));
		va_end(l);
		return (i);
	}
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 0)
			{
				spec.specifier = 'y';
				break;
			}
			s = _specifier(&format, l);
			if (spec.specifier == 'y')
				break;
			k = 0;
			m = 0;

			t = string(list, spec, &free);
			if (t == NULL)
				break;
			p = t;
			while (*p || spec.width || (m == 0 && spec.specifier == 'c'))
			{
				if (spec.width > 0)
					spec.width--;
				buffer[len++] = *p++;
				m = 1;
				if (len == 1024)
				{
					j = write(1, buffer, 1024);
					if (j == -1)
						return (-1);
					i += j;
					len = 0;
				}
			}
			if (k)
				free(t);
		}
		else
			i += buffer_char(&f, b, &len);
	}
	va_end(l);
	j = write(1, buffer, len);
	if (j == -1 || spec.specifier == 'y')
		return (-1);
	i += j;
	if (t == NULL)
		return (-1);
	return (i);
}
