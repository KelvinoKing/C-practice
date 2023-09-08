#include "main.h"

int _print_char(va_list ap)
{
	return (_putchar(va_arg(ap, int)));
}
