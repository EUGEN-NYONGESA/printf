#include "main.h"

unsigned int s_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int S_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int r_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int R_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
/**
 * s_convert - Converts argument to a string, also stores it to a buffer that is contained in a struct.
 * @args: va_list that points to the argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes that is stored to the buffer.
 */
unsigned int s_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char *str, *null = "(null)";
	int siz;
	unsigned int ret = 0;
	(void)flags;
	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));
	for (siz = 0; *(str + siz);)
		siz++;
	ret += print_string_wid(result, flags, wit, precs, siz);
	precs = (precs == -1) ? siz : precs;
	while (*str != '\0' && precs > 0)
	{
		ret += _memcpy(result, str, 1);
		precs--;
		str++;
	}
	ret += print_neg_wid(output, ret, flags, wit);
	return (ret);
}
/**
 * S_convert - Converts argument to a string. Also stores it to a buffer contained in a struct.
 * @args: va_list that points to an argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes that are stored to the buffer.
 *
 * Description: Non-printable characters (ASCII values < 32 or >= 127)
 *              stored as \x, followed by the ASCII code hex value.
 */
unsigned int S_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char *str, *null = "(null)", *hex = "\\x", zero = '0';
	int siz, index;
	unsigned int ret = 0;

	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));
	for (siz = 0; str[siz];)
		siz++;
	ret += print_str_wid(result, flags, wit, precs, siz);
	precs = (precs == -1) ? siz : precs;
	for (index = 0; *(str + index) != '\0' && index < precs; index++)
	{
		if (*(str + index) < 32 || *(str + index) >= 127)
		{
		ret += _memcpy(result, hex, 2);
		if (*(str + index) < 16)
			ret += _memcpy(result, &zero, 1);
		ret += ubase_convert(result, *(str + index),
				"0123456789ABCDEF", flags, 0, 0);
		continue;
		}
		ret += _memcpy(result, (str + index), 1);
	}
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * r_convert - Reverse a string. Also stores it to a buffer contained in a struct.
 * @args: va_list that points to the string to be reversed.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes stored to the buffer.
 */
unsigned int r_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char *str, *null = "(null)";
	int siz, end, m;
	unsigned int ret = 0;
	(void)flags;
	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));
	for (siz = 0; *(str + siz);)
		siz++;
	ret += print_str_wid(result, flags, wit, precs, siz);
	end = siz - 1;
	precs = (precs == -1) ? siz : precs;
	for (m = 0; end >= 0 && m < precs; m++)
	{
		ret += _memcpy(result, (str + end), 1);
		end--;
	}
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * R_convert - Converts string to ROT13. Also stores it to a buffer contained in a struct.
 * @args: va_list that points to a string to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: lenth modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes that are stored to the buffer.
 */
unsigned int R_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char *letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *rot13 = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str, *null = "(null)";
	int m, n, siz;
	unsigned int ret = 0;
	(void)flags;
	(void)len;
	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(result, null, 6));
	for (siz = 0; *(str + siz);)
		siz++;
	ret += print_str_wid(result, flags, wit, precs, siz);
	precs = (precs == -1) ? siz : precs;
	for (m = 0; *(str + m) != '\0' && m < precs; m++)
	{
		for (n = 0; n < 52; n++)
		{
		if (*(str + m) == *(letters + n))
		{
		ret += _memcpy(result, (rot13 + n), 1);
			break;
		}
	}
	if (n == 52)
		ret += _memcpy(result, (str + m), 1);
	}
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
