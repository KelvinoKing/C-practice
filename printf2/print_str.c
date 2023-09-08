#include "main.h"

int _print_str(va_list ap)
{
	char *str = va_arg(ap, char*);
	int lenstr;

	if (str == NULL)
		str = "(null)";

	lenstr = 0;
	while (str[lenstr] != '\0')
	{
		lenstr = lenstr + _putchar(str[lenstr]);
	}

	return (lenstr);
}
