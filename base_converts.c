#include "main.h"

unsigned int sbase_convert(t_buffer *result, long int num, char *base,
		unsigned char flags, int wit, int precs);
unsigned int ubase_convert(t_buffer *result,
		unsigned long int num, char *base,
		unsigned char flags, int wit, int precs);

/**
 * sbase_convert - It converts a signed long to inputted base. Then stores the result to a buffer 
 * 		contained in a struct.
 * @result: t_buffer struct contains a character array.
 * @flags: Flag modifiers.
 * @wit: width modifier.
 * @precs: precision modifier.
 * @base: pointer that points to the string containing the base to convert.
 * @num: signed long to be converted.
 * Return: number of bytes that get stored to the buffer.
 */
unsigned int sbase_convert(t_buffer *result, long int num, char *base,
		unsigned char flags, int wit, int precs)
{
	int siz;
	char figure, padd = '0';
	unsigned int ret = 1;
	for (siz = 0; *(base + siz);)
		siz++;
	if (num >= siz || num <= -siz)
		ret += sbase_convert(result, num / siz, base,
				flags, wit - 1, precs - 1);
	else
	{
		for (; precs > 1; precs--, wit--) /* Handle precision */
			ret += _memcpy(result, &padd, 1);
		if (N_FLAG == 0) /* Handle width */
		{
			padd = (Z_FLAG == 1) ? '0' : ' ';
			for (; wit > 1; wit--)
				ret += _memcpy(result, &padd, 1);
		}
	}
	figure = base[(num < 0 ? -1 : 1) * (num % siz)];
	_memcpy(result, &figure, 1);
	return (ret);
}
/**
 * ubase_convert - This converts an unsigned long to an inputted base. Then stores the result to a buffer 
 * 		contained in a struct.
 *@base: pointer to a string containing the base to convert to.
 * @num: unsigned long to be converted.
 * @flags: Flag modifiers.
 * @wit: A width modifier.
 * @precs: A precision modifier.
 * @result: t_buffer struct contains a character array.
 *Return: number of bytes stored to the buffer.
 */
unsigned int ubase_convert(t_buffer *result, unsigned long int num, char *base,
		unsigned char flags, int wit, int precs)
{
	unsigned int siz, ret = 1;
	char figure, padd = '0', *head = "0x";

	for (siz = 0; *(base + siz);)
		siz++;

	if (num >= siz)
		ret += ubase_convert(result, num / siz, base,
				flags, wit - 1, precs - 1);
	else
	{
		if (((flags >> 5) & 1) == 1)
		{
			wit -= 2;
			precs -= 2;
		}
		for (; precs > 1; precs--, wit--)
			ret += _memcpy(result, &padd, 1);
		if (N_FLAG == 0)
		{
			padd = (Z_FLAG == 1) ? '0' : ' ';
			for (; wit > 1; wit--)
				ret += _memcpy(result, &padd, 1);
		}
		if (((flags >> 5) & 1) == 1)
			ret += _memcpy(result, head, 2);
	}
	figure = base[(num % siz)];
	_memcpy(result, &figure, 1);
	return (ret);
}
