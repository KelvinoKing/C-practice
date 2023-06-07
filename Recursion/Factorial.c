#include <stdio.h>

/*
 *factorial - Gets the factorial of the passed value
 *@n: parameter
 *Return: int
 */
int factorial(int n)
{
	int res;
	int i;

	res = 1;
	i = 1;

	while (i <= n)
	{
		res = res * i;
		i++;
	}
	return (res);
}

/**
 * main - Entry point
 * Return: void
 */
int main(void)
{
	int f;

	f = factorial(5);
	printf("5! = %d\n", f);
}
