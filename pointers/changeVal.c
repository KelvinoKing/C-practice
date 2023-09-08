#include <stdio.h>

void change(int *j)
{
	*j = 98;
	printf("Inside change: %d\n", *j);
}


int main(void)
{
	int j = 1042;
	int *ptr;

	ptr = &j;

	printf("Before change: %d\n", j);

	change(ptr);

	printf("After change: %d\n", j);
}
