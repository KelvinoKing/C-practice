char *_strcpy(char *dest, char *str)
{
	int i = 0;

	while (i < strlen + 1)
	{
		if (str[i] != '\0')
		    dest[i] = *(str + i);
		else
			dest[i] = '\0';
		i++;
	}
	return (dest);
}

char str[7] = "Kelvin\0";
