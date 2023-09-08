#include "main.h"
int _strlen(const char *s)
{
	int i = 0;
	int count = 0;

	while (*(s + 1) != '\0')
	{
		count++;
		i++;
	}
	 return (count);
}

unsigned int binary_to_uint(const char *b)
{
	int i = 0;
	unsigned int multiplier = 1;

	if (b == NULL)
		return (0);

	while (b[i] != '\0')
	{
		if (b[i] != '1' && b[i] != '0')
			return (0);
		i++;
	}

	i = _strlen(b) - 1;

	while (i >= 0)
	{
		if (b[i] == '0')
			multiplier *= 2;
		else if (b[i] == '1')
		{
			sum += multiplier;
			multiplier *= 2;
		}
		i--;
	}
	return (sum);
}
