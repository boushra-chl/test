#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 * @plus_flag: one if plus_flag is specified
 * @space_flag: one if hashtag_flag is specified
 * @hashtag_flag: one if _flag is specified
 * @zero_flag: one if _flag is specified
 * @minus_flag: one if _flag is specified
 *
 * @width: field width specified
 * @precision: field precision specified
 * 
 * @h_modifier: one if h_modifier is specified
 * @l_modifier: one if l_modifier is specified
 */

typedef struct parameters
{
	unsigned int unsign;
	unsigned int plus_flag;
	unsigned int space_flag;
	unsigned int hashtag_flag;
	unsigned int zero_flag;
	unsigned int minus_flag;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier;
	unsigned int l_modifier;
}params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */

typedef struct sprcifier
{
	char *specifier;
	int (*f)(va_list, params_t, *);
}specifier_t;

/*_put.c module */
int _puts(char *str);
int _putchar(int c);

/*print_functions.c module */
int print_char(va_list args, params_t *params);
int print_int(va_list args, params_t *params);
int print_string(va_list args, params_t *params);
int print_percent(va_list args, params_t *params);
int print_S(va_list args, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list args, params_t *params);
int print_adress(va_list args, params_t *params);

/*specifier.c module */
int (*get_specifier(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list args);

/*convert_number.c module */
int print_hex(va_list args, params_t *params);
int print_HEX(va_list args, params_t *params);
int print_binary(va_list args, params_t *params);
int print_octal(va_list args, params_t *params);

/*simple_printers.c module */
int print_from_to(char* start, char *stop, char *except);
int print_rev(va_list args, params_t *params);
int print_rot13(va_list args, params_t *params);

/*print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/*params.c module */
void init_params(params_t *params, va_list args);

/*string_fields.c */
char *get_precision(char *p, params_t *params, va_list args);

/*_printf.c module */
int _printf(const char *format, ...);

#endif

