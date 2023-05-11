#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
	int len = strlen(s) - 1;

	while (len >= 0)
	{
		printf("%c", s[len]);
		len--;
	}
	printf("\n");
}

int main()
{
	char str[] = "Kelvin";
	
	print_reverse(str);
	return (0);
}
