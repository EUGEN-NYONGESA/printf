#include "main.h"

unsigned int di_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int b_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int u_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);
unsigned int o_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len);

/**
 * di_convert - Converts argument to a signed int then stores it to a buffer contained in a struct.
 * @args: va_list points to the argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: A length modifier.
 * @result: t_uffer struct that contains a character array.
 * Return: number of bytes that are stored to the buffer.
 */
unsigned int di_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	long int d, dup;
	unsigned int ret = 0, count = 0;
	char padd, blank = ' ', neg = '-', pos = '+';
	if (len == L_LONG)
		d = va_arg(args, long int);
	else
		d = va_arg(args, int);
	if (len == L_SHORT)
		d = (short)d;
	/**** H_space flag ****/
	if (S_FLAG == 1 && d >= 0)
		ret += _memcpy(result, &blank, 1);
	if (precs <= 0 && N_FLAG == 0) 
	{
		if (d == LONG_MIN)
			count += 19;
		else
		{
			for (dup = (d < 0) ? -d : d; dup > 0; dup /= 10)
				count++;
		}
		count += (d == 0) ? 1 : 0;
		count += (d < 0) ? 1 : 0;
		count += (P_FLAG == 1 && d >= 0) ? 1 : 0;
		count += (S_FLAG == 1 && d >= 0) ? 1 : 0;
		if (Z_FLAG == 1 && P_FLAG == 1 && d >= 0)
			ret += _memcpy(result, &pos, 1);
		if (Z_FLAG == 1 && d < 0)
			ret += _memcpy(result, &neg, 1);
		padd = (Z_FLAG == 1) ? '0' : ' ';
		for (wit -= count; wit > 0; wit--)
			ret += _memcpy(result, &padd, 1);
	}
	if (Z_FLAG == 0 && d < 0)
		ret += _memcpy(result, &neg, 1);
	if (Z_FLAG == 0 && (P_FLAG == 1 && d >= 0))
		ret += _memcpy(result, &pos, 1);
	if (!(d == 0 && precs == 0))
		ret += sbase_convert(result, d, "0123456789",
			flags, 0, precs);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}
/**
 * convert_b - Converts an unsigned int argument to binary then stores it to a buffer contained in a struct.
 * @args: va_list points to argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct contains a character array.
 * Return: The number of bytes stored to the buffer.
 */
unsigned int b_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	unsigned int num;
	num = va_arg(args, unsigned int);
	(void)len;
	return (ubase_convert(result, num, "01", flags, wit, precs));
}
/**
 * o_convert - Converts an unsigned int to octal then stores it to a buffer contained in a struct.
 * @args: va_list points to the argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct contains a character array.
 * Return: number of bytes stored to the buffer.
 */
unsigned int o_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';
	if (len == L_LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == L_SHORT)
		num = (unsigned short)num;
	if (H_FLAG == 1 && num != 0)
		ret += _memcpy(result, &zero, 1);
	if (!(num == 0 && precs == 0))
		ret += ubase_convert(result, num, "01234567",
				flags, wit, precs);
	ret += print_neg_wid(result, ret, flags, wit);
	return (ret);
}

/**
 * u_convert - Converts unsigned int argument to decimal then stores it to a buffer contained in a struct.
 * @args: va_list that points to the argument to be converted.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @len: length modifier.
 * @result: t_buffer struct containing a character array.
 * Return: number of bytes that are stored to the buffer.
 */
unsigned int u_convert(va_list args, t_buffer *result,
		unsigned char flags, int wit, int precs, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	if (len == L_LONG)
		num = va_arg(args, unsigned long int);
	else
		num = va_arg(args, unsigned int);
	if (len == L_SHORT)
		num = (unsigned short)num;
	if (!(num == 0 && precs == 0))
		ret += ubase_convert(result, num, "0123456789",
				flags, wit, precs);
	ret += print_neg_wit(result, ret, flags, wit);
	return (ret);
}
