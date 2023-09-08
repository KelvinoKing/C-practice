#include "main.h"
/**
 * printStr - prints a string
 * @ap: arguments
 *
 * Return: int
 */
int printStr(va_list ap)
{
	int i = 0;
	char c;
	char *str = va_arg(ap, char*);
	int lenStr = strlen(str);

	while (i < lenStr)
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
	return (lenStr);
}
