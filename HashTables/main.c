#include "hash.h"

int main(void)
{
	char str1[] = "Hel";
	char str2[] = "Cau";

	printf("%lu\n", hash_function(str1));
	printf("%lu\n", hash_function(str2));

	return (0);
}
