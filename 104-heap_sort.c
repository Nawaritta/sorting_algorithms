#include "sort.h"
/**
 * heap_build - The heapify procedure that used for building the max-heap
 * @array: the array to turn to a heap structure
 * @size: the size of the array
 * @start: the index of the node (in the array) from where
 *        the heap-building process starts.
 * @end: The end index of the heap.
 */
void heap_build(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;
	int tmp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;

		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;

		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts an array of integers using the heap sorting algorithm
 * @array: pointer to the array to sort
 * @size: the size of the array to sort
 */
void heap_sort(int *array, size_t size)
{
	int tmp;
	ssize_t root;

	if (array == NULL || size < 2)
		return;

	for (root = size / 2 - 1; root >= 0; root--)
		heap_build(array, root, size - 1, size);

	for (root = size - 1; root > 0; root--)
	{
		tmp = array[root];
		array[root] = array[0];
		array[0] = tmp;
		print_array(array, size);
		heap_build(array, 0, root - 1, size);
	}
}
