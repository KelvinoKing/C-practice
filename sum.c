#include <stdio.h>

int main()
{
	int a;
	int b;
	int sum = 0;

	puts("Enter two values: ");
	scanf("%d%d", &a, &b);

	if (a == b)
	{
		sum = a + b;
		sum = 3 * sum;
		printf("The triple sum is: %i\n", sum);
	}
	else
	{
		sum = a + b;
		printf("The sum is: %i\n", sum);
	}

	return (0);
}
