#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * _specifier - contains specifiers for printf
 *
 * @length: modifies length type.
 * @width: print field width
 * @precision: print field precision.
 * @flagw: tells whether width is set
 * @flagp: tells whether precision is set
 * @just: justifies 0 for right, 1 for left
 * @sign: Sign +, 0 for no, 1 for yes
 * @sp: left side space of positive numbers
 * @n: zero pad numbers leading to width.
 * @ln: 0 for no, 1 for yes
 * @specifier: data type to be printed.
 */
typedef struct _specifier
{
	int length;
	unsigned int width;IN_H
	unsigned int precision;
	char flagw;
	char flagp;
	char just;
	char sign;
	char sp;
	char n;
	char ln;
	char specifier;
} specifier;

int _printf(char *format, ...);
char *_str(char *s, specifier spec);
char *_num(char *str, specifier spec);
int _strlen(char *s);
int _puts(char *s);
int check_puts(char *s)
char *int_string(va_list arg);
char *int_to_string(va_list arg);
char *to_string(va_list arg);
char *int_tostring(va_list arg);

#endif
