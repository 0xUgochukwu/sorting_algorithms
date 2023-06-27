#include "sort.h"


/**
 * swap - swap two integers using aritmetic operations
 * without using an intermediate/temporary variable
 *
 * @array: array to be printed after swap
 * @size: size of the array
 *
 * @a: pointer to the first integer
 * @b: pointer to the secod integer
 */
void swap(int array[], size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;

		print_array((const int *) array, size);
	}
}



/**
 * lomuto_partition - partitions the array
 *
 * @array: array to be patitioned
 * @size: size of the array
 *
 * @li: lower index of the range to be sorted
 * @hi: higher index of the range to be sorted
 *
 * Return: pivot
 */

size_t lomuto_partition(int array[], size_t size, ssize_t li, ssize_t hi)
{
	int i, j, pivot = array[hi];

	for (i = j = li; j < hi; j++)
		if (array[j] < pivot)
			swap(array, size, &array[j], &array[i++]);
	swap(array, size, &array[i], &array[hi]);

	return (i);
}


/**
 * inner_sort - recursively sort the left and right handsides of a pivot
 *
 * @array: array being sorted
 * @size: length of the array
 *
 * @li: lower index of range to be sorted
 * @hi: higher index of range to be sorted
 */
void inner_sort(int array[], size_t size, ssize_t li, ssize_t hi)
{
	size_t pivot;

	if (li < hi)
	{
		pivot = lomuto_partition(array, size, li, hi);

		inner_sort(array, size, li, pivot - 1);
		inner_sort(array, size, pivot + 1, hi);
	}
}

/**
 * quick_sort - sort an arry using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */


void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	inner_sort(array, size, 0, size - 1);

}
