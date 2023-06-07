#include <stdio.h>

/**
 * factorial - Returns the factorial of passed value
 *
 * @n: parameter
 *
 * Return: int
 */
int factorial(int n)
{
	if (n == 0)
		return (1);

	return (n * factorial(n - 1));
}

/**
 * main - Entry point of programme
 *
 * Return: void
 */
int main(void)
{
	int f;

	f = factorial(5);
	printf("5! = %d\n", f);
	return (0);
}
