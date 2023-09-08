#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int len;
	int len2;
	unsigned int ui;

	len = _printf("Let's try to printf a simple sentence.\n");
  len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	_printf("Length:[%d, %i]\n", len, len);
  printf("Length:[%d, %i]\n", len2, len2);
	_printf("Positive:[%d, %i]\n", 34566, -34566);
	printf("Positive:[%d, %i]\n", 34566, -34566);
	_printf("%b\n", 98);
	_printf("Unsigned:[%u]\n", ui);
  printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
  printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
  printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	return (0);
}
