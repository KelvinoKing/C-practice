#include "main.h"
#include <stdio.h>

int main(void)
{
    _printf("Let's try to printf a simple sentence.\n");
    printf("Let's try to printf a simple sentence.\n");
		_printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
		_printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
		_printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");

    return (0);
}
