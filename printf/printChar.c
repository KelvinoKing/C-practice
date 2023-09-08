#include "main.h"
/**
 * printChar - prints characters
 * @ap : arguments
 *
 * Return: int
 */
int printChar(va_list ap)
{
	char c = va_arg(ap, int);
	write(1, &c, 1);
	return (1);
}
