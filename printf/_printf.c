#include "main.h"
/**
 * _printf - produces output according to format
 * @format: format to be used
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list ap;
	char c;

	op_t op[] = {
		{'c', printChar},
		{'s', printStr},
		{'d', printInt},
		{'i', printInt},
		{'b', printBin},
		{'u', printUnsigned},
		{'o', printOctal},
		{'x', printHexaLow},
		{'X', printHexaUp},
		{'\0', NULL}
	};

	int i = 0, j = 0;
	int numChars = 0;

	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (op[j].c != '\0')
			{
				if (format[i + 1] == op[j].c)
				{
					numChars = numChars + op[j].f(ap);
					i++;
				}
				j++;
			}
		}
		else
		{
			c = format[i];
			write(1, &c, 1);
			numChars++;
		}
		i++;
	}
	va_end(ap);
	return (numChars);
}
