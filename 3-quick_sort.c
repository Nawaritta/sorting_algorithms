#include "sort.h"

/**
 * quick_sort_rec - recursive function of the quick sorting algorithm
 *                  using the Lomuto Partition scheme
 *                  (the pivot is the last element of the partition).
 * @array: pointer to the array to sort.
 * @size: the size of the array to sort.
 * @partition: pointer to the partition to sort.
 * @part_size: the size of the partition to sort.
 */

void quick_sort_rec(int *array, size_t size, int *partition, size_t part_size)
{
	int pivot, tmp;
	size_t current = 0, cursor = 0;

	if (partition == NULL || part_size < 2)
		return;

	pivot = partition[part_size - 1];

	for (; current < part_size; current++)
	{
		if (partition[current] <= pivot)
		{
			if (current == cursor)
			{
				cursor++;
				continue;
			}
			tmp = partition[cursor];
			partition[cursor++] = partition[current];
			partition[current] = tmp;
			print_array(array, size);
		}
	}
	quick_sort_rec(array, size, partition, cursor - 1);
	partition += cursor;
	part_size -= cursor;
	quick_sort_rec(array, size, partition, part_size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the quick sorting algorithm.
 * @array: The array to sort.
 * @size: the size of the array to sort.
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, size, array, size);
}
