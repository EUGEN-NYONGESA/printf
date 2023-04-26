#include "main.h"

unsigned int c_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int percent_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int p_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);

/**
 * c_convert - Converts argument to unsigned char. Then stores it to a buffer contained in a struct.
 * @args: va_list points to argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct contains a character array.
 * Return: number of bytes that is stored to the buffer.
 */
unsigned int c_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char c;
	unsigned int ret = 0;

	(void)precs;
	(void)len;
	c = va_arg(args, int);
	ret += print_wid(result, ret, flags, wit);
	ret += _memcpy(result, &c, 1);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * percent_convert - stores the percent sign to a buffer contained in a struct.
 * @args: va_list that points to the argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: A length modifier.
 * @result: t_buffer struct contains a character array.
 * Return: number of bytes that to be stored to the buffer (always 1).
 */
unsigned int percent_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	char percent = '%';
	unsigned int ret = 0;
	(void)args;
	(void)precs;
	(void)len;
	ret += print_wid(result, ret, flags, wit);
	ret += _memcpy(result, &percent, 1);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * p_convert - Converts the address of argument to hex. Them stores it to a buffer contained in a struct.
 * @args: va_list points to argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct contains a character array.
 * Return: number of bytes that get stored to the buffer.
 */
unsigned int p_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int pres, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int ret = 0;
	(void)len;
	address = va_arg(args, unsigned long int);
	if (address == '\0')
		return (_memcpy(result, null, 5));
	flags |= 32;
	ret += ubase_convert(result, address, "0123456789abcdef",
			flags, wit, precs);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
