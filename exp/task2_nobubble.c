#include <stdio.h>


void multiply_by8() __attribute__((section (".patch")));

__attribute__ ((noinline))
void multiply_by8(int *arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		arr[i] *= 8;
}

int main()
{
	int arr[] = { 1, 90, -500, 0, 0, 1, 234, 12345, 700, -50, -5, -100};
	int sz = sizeof(arr) / sizeof(int);
	
	printf("Before routine: ");
	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);

	putchar('\n');
	
	multiply_by8(&arr[0], sz);

	printf("After routine: ");
	for (int i = 0; i < sz; ++i)
		printf("%d ", arr[i]);

	putchar('\n');
	return 0;
}
