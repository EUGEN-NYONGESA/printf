#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
/*** Flag Modifier ***/
#define FM_PLUS 1
#define FM_SPACE 2
#define FM_HASH 4
#define FM_ZERO 8
#define FM_NEG 16
#define P_FLAG (flags & 1)
#define S_FLAG ((flags >> 1) & 1)
#define H_FLAG ((flags >> 2) & 1)
#define Z_FLAG ((flags >> 3) & 1)
#define N_FLAG ((flags >> 4) & 1)
/* Length Modifier Macros */
#define L_SHORT 1
#define L_LONG 2
/**
 * struct s_buffer - new type that defines a buffer struct.
 * @onset: pointer that points to the start of buffer.
 * @buffer: pointer that points to a character array.
 * @siz: length of the string stored in buffer.
 */

typedef struct s_buffer
{
<<<<<<< HEAD
        char *buffer;
        char *onset;
        unsigned int siz;
}
t_buffer;
/**
 * struct s_converter - new type defining converter struct.
 * @funct: pointer to a conversion function that corresponds to a specifier.
 * @spec: A character that represents a conversion specifier.
 */
typedef struct s_converter
{
        unsigned char spec;
        unsigned int (*funct)(va_list, t_buffer *,
        unsigned char, int, int, unsigned char);
}
t_converter;
/**
 * struct s_flag - new type defining flags struct.
 * @val: integer value of flag.
 * @flag: character that represents a flag.
 */
typedef struct s_flag
{
        unsigned char flag;
        unsigned char val;
}
t_flag;
int _printf(const char *format, ...);
/**** Specifier Functions ****/
unsigned int b_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int c_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int di_convert(va_list args, s_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int s_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int percent_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int o_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int u_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int p_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int r_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int R_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int S_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int x_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
unsigned int X_convert(va_list args, t_buffer *result,
                unsigned char flags, int wid, int precs, unsigned char len);
/**** Handle Functions ****/
unsigned char flag_handle(const char *flags, char *index);
unsigned char length_handle(const char *modf, char *index);
int precision_handle(va_list args, const char *modf, char *index);
int width_handle(va_list args, const char *modf, char *index);
unsigned int (*spec_handle(const char *spec))(va_list, t_buffer *,
                unsigned char, int, int, unsigned char);
/**** Modifya Functions ****/
unsigned int print_wid(t_buffer *result, unsigned int printd,
                unsigned char flags, int wit);
unsigned int print_neg_wid(t_buffer *result, unsigned int printd,
                unsigned char flags, int wit);
unsigned int print_str_wid(t_buffer *result,
                unsigned char flags, int wit, int precs, int siz);
/**** Help Functions ****/
t_buffer *buffer_innit(void);
void fr_buffer(t_buffer *result);
unsigned int _memcpy(t_buffer *result, const char *src, unsigned int n);
unsigned int sbase_convert(t_buffer *result, long int num, char *base,
                unsigned char flags, int wit, int precs);
unsigned int ubase_convert(t_buffer *result, unsigned long int num, char *base,
                unsigned char flags, int wit, int precs);
=======
	int length;
	unsigned int width;
	unsigned int precision;
	char flagw;
	char flagp;
	char just;
	char sign;
	char sp;
	char n;
	char ln;
	char specifier;
}specifier;

int _printf(char *format, ...);
char *_str(char *s, specifier spec);
char *_num(char *str, specifier spec);
int _strlen(char *s);
int _puts(char *s);
char *int_string(va_list arg);
char *int_to_string(va_list arg);
char *to_string(va_list arg);
char *int_tostring(va_list arg);

>>>>>>> c1485743bdbbeedbe7da72aacbe743c311f38961
#endif
