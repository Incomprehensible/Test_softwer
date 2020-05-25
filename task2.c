#include <stdio.h>

void multiply_by8(int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		arr[i] *= 8;
}

void bubble_sort(int *arr, int sz)
{
	int tmp;

	for (int i = 0; i < sz; ++i)
	{
		for (int j = 0; j<sz-i-1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = { 1, 90, -500, 0, 0, 1, 234, 12345, 700, -50, -5, -100};
	int sz = sizeof(arr) / sizeof(int);
	
	printf("Before routine: ");
	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);

	putchar('\n');
	
	bubble_sort(&arr[0], sz);

	printf("After routine: ");
	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);

	putchar('\n');
	return 0;
}
