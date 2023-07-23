#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 *              using Knuth sequence.
 * @array: pointer to the array to be sorted.
 * @size: the size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int tmp;


	if (array == NULL || size < 2)
		return;

	while (interval <= size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			tmp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > tmp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = tmp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
