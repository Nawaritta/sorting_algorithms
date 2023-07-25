#include "sort.h"
#include "102-counting_sort.c"
/**
 * counting_s - does the counting sort based on the significant digit.
 * @array: Pointer to the array of integers.
 * @size: the array size.
 * @exp: The current significant digit for counting sort.
 */
void counting_s(int *array, size_t size, int exp)
{
	int *count_s = malloc(size * sizeof(int)), bins[10], j;
	size_t i;

	for (j = 0; j < 10; j++)
		bins[j] = 0;

	if (count_s == NULL)
		return;

	for (i = 0; i < size; ++i)
		bins[(array[i] / exp) % 10]++;

	for (j = 1; j < 10; ++j)
		bins[j] += bins[j - 1];

	for (j = size - 1; j >= 0; --j)
	{
		count_s[bins[(array[j] / exp) % 10] - 1] = array[j];
		bins[(array[j] / exp) % 10]--;
	}

	for (i = 0; i < size; ++i)
		array[i] = count_s[i];

	free(count_s);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort.
 * @array: Pointer to the array of integers to be sorted.
 * @size: Number of elements in the array.
 *
 */
void radix_sort(int *array, size_t size)
{

	int exp, max;

	if (!array || size < 2)
		return;

 	max = maximum(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_s(array, size, exp);
		print_array(array, size);
	}
}
