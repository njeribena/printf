#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

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
