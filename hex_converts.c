#include "main.h"

unsigned int x_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int X_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
/**
 * x_convert - Converts unsigned int argument to hex using abcdef. Then stores it to
 * 		a buffer contained in a struct.
 * @args: va_list points to argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes stored to the buffer.
 */
unsigned int x_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *head = "0x";
	if (len == L_LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == L_SHORT)
		num = (unsigned short)num;
	if (H_FLAG == 1 && num != 0)
		ret += _memcpy(output, head, 2);
	if (!(num == 0 && precs == 0))
		ret += ubase_convert(result, num, "0123456789abcdef",
				flags, wit, precs);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * X_convert - Converts an unsigned int argument to hex using ABCDEF. Then stores it to a buffer 
 * 		contained in a struct.
 * @args: va_list that points to argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct that contains a character array.
 * Return: number of bytes that is stored to the buffer.
 */
unsigned int X_convert(va_list args, t_buffer *output,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char *head = "0X";
	if (len == L_LONG)
		num = va_arg(args, unsigned long);
	else
		num = va_arg(args, unsigned int);
	if (len == L_SHORT)
		num = (unsigned short)num;
	if (H_FLAG == 1 && num != 0)
		ret += _memcpy(result, head, 2);
	if (!(num == 0 && precs == 0))
		ret += ubase_convert(result, num, "0123456789ABCDEF",
				flags, wit, precs);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
