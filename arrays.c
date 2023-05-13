#include <stdio.h>

int main()
{
	int nums[10];
	int i, a;

	puts("Test Data:");
	puts("Input 10 elements in the array:");

	for (i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &nums[i]);
	}

	printf("\nElements in array are: ");
	for (i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");

	return (0);
}
