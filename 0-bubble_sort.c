#include "sort.h"
/**
 * bubble_sort - sort using the Bubble sort algorithm.
 * @array: Variable for array of integers.
 * @size: Size of the array.
 *
 **/
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;
	int tmp;

	if (size < 2)
	{
		return;
	}
	for (i = 0; size > i; i++)
	{
		for (j = 0; size - i - 1 > j; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
