#include "sort.h"
/**
 * partitioning - function to sort an array into subarrays to be sorted
 * @array: array to be sorted
 * @low: low index
 * @high: highest index
 *
 * Return: index for partition
 */
int partitioning(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[j] != array[i])
				print_array(array, size);
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;
	if (array[high] != array[i])
		print_array(array, size);
	return (i);
}

/**
 * quicksort - ...
 * @array: array to sort
 * @low: lowest index
 * @high: highest index
 */
void quicksort(int *array, size_t low, size_t high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = partitioning(array, low, high, size);
		if (partition) /*condition to avoid an infinite loop*/
			quicksort(array, low, partition -1, size);
		quicksort(array, partition + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm using lomuto partition scheme.
 * @array: array given
 * @size: total of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}

