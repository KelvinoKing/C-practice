#include <stdio.h>

void quicksort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *a, int *b);

int main(void)
{
	int i;
	int array[] = {8, 7, 6, 1, 0, 9, 2};
	int size = sizeof(array) / sizeof(array[0]);

	quicksort(array, 0, size - 1);
	printf("Sorted array: \n");
	for (i = 0; i < size; i++)
	{
		printf("%d, ", array[i]);
	}
	printf("\n");
	return 0;
}

void quicksort(int array[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(array, low, high);

		/*Handle both the right side and left side of pivot*/
		quicksort(array, low, pi - 1);
		quicksort(array, pi + 1, high);
	}
}

int partition(int array[], int low, int high)
{
	int i = low - 1;
	int j;
	int pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}

	}
	/*swap the greatest element with the pivot*/
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
