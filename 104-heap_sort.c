#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Performs the sift-down operation on a heap
 * @array: Array representing the heap
 * @start: Start index of the subtree to sift down
 * @end: End index of the subtree to sift down
 * @size: Size of the array
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	while (root * 2 + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);
		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Build the heap (rearrange the array) */
	for (int i = size / 2 - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	/* One by one extract elements from the heap */
	for (int i = size - 1; i > 0; i--)
	{
		/* Move the current root (maximum element) to the end */
		swap(&array[0], &array[i]);
		print_array(array, size);

		/* Call sift_down on the reduced heap */
		sift_down(array, 0, i - 1, size);
	}
}
