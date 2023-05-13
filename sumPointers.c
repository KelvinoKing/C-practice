#include <stdio.h>

int main()
{
	int a, b, sum = 0;
	int *ptrA = &a;
	int *ptrB = &b;

	printf("Input first number: ");
	scanf("%d", &a);
	printf("Input second number: ");
	scanf("%d", &b);

	sum = *ptrA + *ptrB;

	printf("The sum of the entered numbers is: %d\n", sum);
	return (0);
}
