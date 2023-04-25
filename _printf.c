#include <stddef.h>
#include <stdarg.h>
#include "main.h"

/**
 * get_op - select function for character conversion
 * @c: char to be checked
 * Return: pointer
 */

int (*get_op(const char c))(va_list)
{
	int a = 0;

	flags_p fp[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_nbr},
		{"d", print_nbr},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hexa_lower},
		{"X", print_hexa_upper},
		{"u", print_unsigned},
		{"S", print_str_unprintable},
		{"r", print_str_reverse},
		{"p", print_ptr},
		{"R", print_rot13},
		{"%", print_percent}
	};
	while (a < 14)
	{
		if (c == fp[a].c[0])
		{
			return (fp[a].f);
		}
		a++;
	}
	return (NULL);
}

/**
 * _printf - Replicate behavior of printf function
 * @format: format string
 * Return: printed chars value
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int sum = 0, a = 0;
	int (*func)();

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);

	while (format[a])
	{
		if (format[a] == '%')
		{
			if (format[a + 1] != '\0')
				func = get_op(format[a + 1]);
			if (func == NULL)
			{
				_putchar(format[a]);
				sum++;
				a++;
			}
			else
			{
				sum += func(ap);
				a += 2;
				continue;
			}
		}
		else
		{
			_putchar(format[a]);
			sum++;
			a++;
		}
	}
	va_end(ap);
	return (sum);
}
