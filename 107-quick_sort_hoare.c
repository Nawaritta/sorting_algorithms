#include "sort.h"

/**
 * hoare_partition - The Hoare partition scheme is used to partition the array
 * @array: The array to be partitioned
 * @down: The starting index of the partition
 * @up: The ending index of the partition
 * @size: The size of the array
 * Return: The index of the pivot after partition
 */

int hoare_partition(int *array, size_t down, size_t up, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[up];
	i = down - 1;
	j = up + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * hoare_recursive - sorts the array of integers by separating into two
 *                   partitions, using Hoare quick sort
 * @array: array of integers to be sorted
 * @down: The starting index of the partition
 * @up: The ending index of the partition
 * @size: The size of the array
 */
void hoare_recursive(int *array, size_t down, size_t up, size_t size)
{
	size_t i;

	if (down < up)
	{
		i = hoare_partition(array, down, up, size);
		hoare_recursive(array, down, i, size);
		hoare_recursive(array, i + 1, up, size);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order
 *                    using the Hoare quick sort scheme alogrithm
 * @array: array to be sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_recursive(array, 0, size - 1, size);
}
