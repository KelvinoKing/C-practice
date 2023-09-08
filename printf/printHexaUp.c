#include "main.h"
/**
 * printHexaUp - converts decimal numbers to hexadecimal
 * @ap: parameter
 * 
 * Return: int
 */
int printHexaUp(va_list ap)
{
	unsigned int num = va_arg(ap, unsigned int);
  int num_divided = 0;
  unsigned int holder = num;
  int *ptr, i = 0;

  while (num > 0)
   {
     num /= 16;
     num_divided++;
   }
   ptr = malloc(num_divided * sizeof(*ptr));
   if (ptr == NULL)
     return (0);

   while (i < num_divided)
   {
     ptr[i] = holder % 16;
     holder /= 16;
     i++;
   }
    for (i = num_divided - 1; i >= 0; i--)
    {
      if (ptr[i] >= 10)
        _putchar(ptr[i] + 55);
      else
        _putchar(ptr[i] + '0');
    }
    free(ptr);
    return (num_divided);
 }

