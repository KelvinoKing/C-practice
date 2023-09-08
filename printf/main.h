#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
/**
 * struct my_struct - Struct to hold char and function pointer
 * @c: hold special characters
 * @f: function pointer
 *
 * Description: My struct
 */
typedef struct my_struct
{
	char c;
	int (*f)(va_list);
} op_t;

int _printf(const char *format, ...);
int printChar(va_list);
int printStr(va_list);
int printInt(va_list);
int printBin(va_list);
int printUnsigned(va_list);
int printOctal(va_list);
int printHexaLow(va_list);
int printHexaUp(va_list);
int _putchar(char c);
#endif /*MAIN_H*/
