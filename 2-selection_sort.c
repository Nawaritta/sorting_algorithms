#include "sort.h"
/**
 *selection_sort - sorts an array of integers in ascending order
 *                using selection sorting algorithm
 * @array: the array of integers to sort
 * @size: the array size
 */
void selection_sort(int *array, size_t size)
{

	size_t i, j, min_index;
	int tmp, swap = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				swap = 1;
				min_index = j;
			}
		}
		if (swap)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
			swap = 0;
		}
	}
}
