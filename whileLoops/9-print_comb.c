#include <stdio.h>

int main(void)
{
	unsigned int c = 0;

	while (c < 10)
	{
		putchar(c + '0');
		if (c != 9)
		{
			putchar(',');
			putchar(' ');
		}
		c++;
	}
	putchar('\n');

	return (0);
}
