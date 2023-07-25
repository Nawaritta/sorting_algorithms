#include "sort.h"

/**
 * swap - swaps two integers.
 * @a: the first integer to be swapped.
 * @b: the second integer to be swapped.
 */
void swap(int *a, int *b)
{
	int tmp;

	if (a != b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * bitonic_updown - divides the subarray into two halves and compares elements
 *                   from each half to sort them in the specified order
 *                   (ascending or descending).
 *                   subarray.
 * @ascend: If 1, sort in ascending order; if 0, sort in descending order.
 * @subarray: pointer to the current subarray to be sorted
 * @subsize: the subarray size.
 */
void bitonic_updown(int ascend, int *subarray, size_t subsize)
{
	size_t half, i;

	half = subsize / 2;

	for (i = 0; i < half; i++)
	{
		if ((subarray[i] > subarray[i + half]) == ascend)
		{
			swap(subarray + i, subarray + (i + half));

		}
	}
}

/**
 * bitonic_merge -  Merges two sorted subarrays into a larger sorted subarray.
 * @ascend: if 1, sort in ascending order; if 0, sort in descending order.
 * @subarray: pointer to the previous subarray.
 * @subsize: the subarray size.
 * @size: The array size.
 */
void bitonic_merge(int ascend, int *subarray, size_t subsize, size_t size)
{
	int *sub1, *sub2;

	if (subsize > 1)
	{
		sub1 = subarray;
		sub2 = subarray + (subsize / 2);

		bitonic_updown(ascend, subarray, subsize);
		bitonic_merge(ascend, sub1, subsize / 2, size);
		bitonic_merge(ascend, sub2, subsize / 2, size);
	}
}

/**
 * bitonic_recursive - Recursively divides the array into subarrays until
 *                     each subarray has a size of 1 and sorts them
 *                     in the specified order (ascending or descending)before
 *                     merging them back into larger sorted subarrays.
 *
 * @ascend: If 1, sort in ascending order; if 0, sort in descending order.
 * @subarray:  pointer to the current subarray to be sorted.
 * @subsize: the subarray size.
 * @size: Number of elements in the source array being sorted.
 */
void bitonic_recursive(int ascend, int *subarray, size_t subsize, size_t size)
{
	int *sub1, *sub2;

	if (subsize <= 1)
		return;

	sub1 = subarray;
	sub2 = subarray + (subsize / 2);

	printf("Merging [%lu/%lu] ", subsize, size);
	printf("(%s):\n", (ascend ? "UP" : "DOWN"));

	print_array(subarray, subsize);

	bitonic_recursive(1, sub1, subsize / 2, size);
	bitonic_recursive(0, sub2, subsize / 2, size);
	bitonic_merge(ascend, sub1, subsize, size);

	printf("Result [%lu/%lu] ", subsize, size);
	printf("(%s):\n", (ascend ? "UP" : "DOWN"));

	print_array(subarray, subsize);
}

/**
 * bitonic_sort - sorts an array of integers in ascending order
 *                using a bitonic sort algorithm.
 * @array: Array of values to be sorted.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursive(1, array, size, size);
}
