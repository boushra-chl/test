#include "main.h"

int _printf(const char *format, ...)
{
	char *p; *start;
	int sum = 0;
	params_t params = PARAMS_INIT;
	
	va_list args;

	va_start(args, format);

	if (!format || format[0] == '%' && !format[1])
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, args);
		if (*p != '%')
		{
			sum = sum + _putchar(*p);
			continue;
		}

