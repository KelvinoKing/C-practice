#include <stdio.h>

void disp_array(int nums[], int len)
{
	int i;

	printf("The values stored into the array are:\n");
	for (i = 0; i < len; i++)
	{
		printf("%d ", nums[i]);
	}
}

void disp_rev(int nums[], int len)
{
	int i;

	printf("\nThe values stored in the array in reverse are:\n");
	for (i = len - 1; i >= 0; i--)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

int main()
{
	int len, i;
	int nums[100];

	do{
       printf("Input the numbers of elements to store in the array: ");
	     scanf("%d", &len);

	}while (len <= 0 || len > 100);

 printf("\nInput %d number of elements in the array:\n", len);

 for (i = 0; i < len; i++)
	{
		printf("element - %d: ", i);
		scanf("%d", &nums[i]);
	}

	disp_array(nums, len);
	disp_rev(nums, len);

	return (0);
}
