#include "main.h"

unsigned char flag_handle(const char *flag, char *index);
unsigned char length_handle(const char *modf, char *index);
int width_handle(va_list args, const char *modf, char *index);
int precision_precision(va_list args, const char *modf, char *index);
unsigned int (*spec_handle(const char *spec))(va_list, t_buffer *,
		unsigned char, int, int, unsigned char);
/**
 * flag_handle - Matches flags with corresponding values.
 * @index: index counter for the original format string.
 * @flag: pointer to a string of flags.
 * Return: If flag characters are matched - a corresponding value.
 *         Otherwise - 0.
 */
unsigned char flag_handle(const char *flag, char *index)
{
	int m, n;
	unsigned char ret = 0;
	t_flag flags[] = {
		{'+', FM_PLUS},
		{' ', FM_SPACE},
		{'#', FM_HASH},
		{'0', FM_ZERO},
		{'-', FM_NEG},
		{0, 0}
	};
	for (m = 0; flag[m]; m++)
	{
	for (n = 0; flags[n].flag != 0; n++)
		{
		if (flag[n] == flags[n].flag)
			{
			(*index)++;
			if (ret == 0)
			ret = flags[n].value;
			else
			ret |= flags[n].value;
			break;
			}
		}
		if (flags[n].value == 0)
		break;
	}
	return (ret);
}
/**
 * length_handle - Match the length modifiers with corresponding value.
 * @modf: pointer to a length modifier.
 * @index: index counterfor the original format string.
 * Return: if length modifier is matched - its corresponding value.
 *         Otherwise - 0.
 */
unsigned char length_handle(const char *modf, char *index)
{
	if (*modf == 'h')
	{
		(*index)++;
		return (L_SHORT);
	}
	else if (*modf == 'l')
	{
		(*index)++;
		return (L_LONG);
	}
	return (0);
}
/**
 * width_handle - Match width modifier with corresponding value.
 * @args: va_list of arguments.
 * @modf: pointer pointing to a width modifier.
 * @index: An index counter for the original format string.
 * Return: If width modifier is matched - its value.
 *         Otherwise - 0.
 */
int width_handle(va_list args, const char *modf, char *index)
{
	int val = 0;
	while ((*modf >= '0' && *modf <= '9') || (*modf == '*'))
	{
		(*index)++;
		if (*modf == '*')
		{
		val = va_arg(args, int);
		if (val <= 0)
			return (0);
		return (val);
		}
		val *= 10;
		val += (*modf - '0');
		modf++;
	}
	return (val);
}
/**
 * precision_handle - Match the precision modifier with corresponding value.
 * @args: va_list of arguments.
 * @modf: A pointer to a potential precision modifier.
 * @index: index counter for the original format string.
 * Return: If precision modifier is matched - its value.
 *         If precision modifier is negative, zero, or empty - 0.
 *         Otherwise - -1.
 */
int handle_precision(va_list args, const char *modifier, char *index)
{
	int val = 0;
	if (*modf != '.')
		return (-1);
	modf++;
	(*index)++;
	if ((*modf <= '0' || *modf > '9') &&
	     *modf != '*')
	{
		if (*modf == '0')
			(*index)++;
		return (0);
	}
	while ((*modf >= '0' && *modf <= '9') ||
	       (*modf == '*'))
	{
		(*index)++;

		if (*modf == '*')
		{
			val = va_arg(args, int);
			if (val <= 0)
				return (0);
			return (val);
		}
		val *= 10;
		val += (*modf - '0');
		modf++;
	}
	return (val);
}
/**
 * spec_handle - Match the conversion specifier with corresponding conversion function.
 * @spec: pointer to the conversion specifier.
 *
 * Return: If conversion function is matched - a pointer to the function.
 *         Otherwise - NULL.
 */
unsigned int (*spec_handle(const char *spec))(va_list, t_buffer *,
		unsigned char, int, int, unsigned char)
{
	int m;
	t_converter converters[] = {
		{'c', c_convert},
		{'s', s_convert},
		{'d', di_convert},
		{'i', di_convert},
		{'%', percent_convert},
		{'b', b_convert},
		{'u', u_convert},
		{'o', o_convert},
		{'x', x_convert},
		{'X', X_convert},
		{'S', S_convert},
		{'p', p_convert},
		{'r', r_convert},
		{'R', R_convert},
		{0, NULL}
	};
	for (m = 0; converters[m].funct; m++)
	{
	if (converters[m].spec == *spec)
		return (converters[m].funct);
	}
	return (NULL);
}
