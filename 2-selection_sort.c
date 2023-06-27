#include "sort.h"

/**
 * selection_sort - sorting algorithm
 *
 * @array: array tp be sorted
 * @size: length of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	if (!array || !size)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}

	}
}
