#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - Hoare partition scheme for Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 * Return: The final partition index
 */
ssize_t hoare_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return j;

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursive - Recursive helper function for Quick Sort
 * @array: The array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare_recursive(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t partition = hoare_partition(array, low, high, size);
		quick_sort_hoare_recursive(array, low, partition, size);
		quick_sort_hoare_recursive(array, partition + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick Sort algorithm (Hoare partition scheme)
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1, size);
}
