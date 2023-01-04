#include "sort.h"

/**
 * selection_sort - search for the minimum value through an unsorted array
 *                  and swaps positions.
 *@array: list of elements to sort
 *@size: amount of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, min_value, j, temp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_value = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
				min_value = j;
		}
		if (min_value != i)
		{
			temp = array[i];
			array[i] = array[min_value];
			array[min_value] = temp;
			print_array(array, size);
		}
	}
}

