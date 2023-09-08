#include "main.h"

int check_specifier(const char *format, va_list ap, op_t *op);

int _printf(const char *format, ...)
{
	va_list ap;
	int num_chars = 0;
	op_t op[] = {
		{"c", _print_char},
		{"s", _print_str},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);

	va_start(ap, format);
	num_chars = check_specifier(format, ap, op);
	va_end(ap);
	return (num_chars);
}

int check_specifier(const char *format, va_list ap, op_t *op)
{
	int i = 0, j = 0;
	int num_chars = 0;
	char letters;

	letters = format[i];
	while (letters != '\0')
	{
		if (letters == '%')
		{
			j = 0;
			i++;
			letters = format[i];
			while (op[j].c != NULL && letters != *(op[j].c))
			{
				j++;
			}
			if (op[j].c != NULL)
			{
				num_chars = num_chars + op[j].f(ap);
			}
			else
			{
				if (letters == '\0')
				{
					return (-1);
				}
				if (letters == '%')
					num_chars += _putchar('%');
				else
				  num_chars += _putchar(letters);
			}
		}
		else
		{
			num_chars += _putchar(letters);
		}
		i++;
		letters = format[i];
	}
	return (num_chars);
}
