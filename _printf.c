#include "main.h"

void clean(va_list args, t_buffer *result);
int start_printf(const char *format, va_list args, t_buffer *output);
int _printf(const char *format, ...);

/**
 * clean - peforms cleanup operations for _printf.
 * @args: va_list of arguments provided to _printf.
 * @result: A t_buffer struct.
 */
void clean(va_list args, t_buffer *output)
{
	va_end(args);
	write(1, result->start, result->len);
	f_buffer(output);
}

/**
 * start_printf - Reads through the format string for _printf.
 * @format: Character string to print - may contain directives.
 * @result: buffer_t struct containing a buffer.
 * @args: va_list of arguments.
 * Return: The number of characters stored to output.
 */
int start_printf(const char *format, va_list args, t_buffer *result)
{
	int m, wit, precs, ret = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, t_buffer *,
			unsigned char, int, int, unsigned char);
	for (m = 0; *(format + m); m++)
	{
		len = 0;
		if (*(format + m) == '%')
		{
			tmp = 0;
			flags = flag_handle(format + m + 1, &tmp);
			wid = width_handle(args, format + m + tmp + 1, &tmp);
			precs = precision_handle(args, format + m + tmp + 1,
					&tmp);
			len = length_handle(format + m + tmp + 1, &tmp);
			f = handle_specifiers(format + m + tmp + 1);
			if (f != NULL)
			{
				m += tmp + 1;
				ret += f(args, result, flags, wit, precs, len);
				continue;
			}
			else if (*(format + m + tmp + 1) == '\0')
			{
				ret = -1;
				break;
			}
		}
		ret += _memcpy(result, (format + m), 1);
		m += (len != 0) ? 1 : 0;
	}
	clean(args, result);
	return (ret);
}
/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	t_buffer *result;
	va_list args;
	int ret;
	if (format == NULL)
		return (-1);
	result = buffer_innit();
	if (result == NULL)
		return (-1);
	va_start(args, format);
	ret = start_printf(format, args, result);
	return (ret);
}
