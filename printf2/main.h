#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
typedef struct my_struct
{
	char *c;
	int (*f)(va_list);
} op_t;
int _printf(const char *format, ...);
int _putchar(char c);
int _print_char(va_list);
int _print_str(va_list);
#endif /*MAIN_H*/
