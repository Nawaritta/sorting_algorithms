#include "sort.h"

/**
 * maximum - gets the maximun value of an array of integers
 * @array: the array to get the maximum value of
 * @size: the array size.
 * Return: the maximum value of all the array elements
 */

int maximum(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	return (max);
}

/**
 * counting_sort - sorts an arrays of integers in an ascending order
 *                 using the counting sort algorithm
 *@array: the array to sort
 *@size: the array size
 */
void counting_sort(int *array, size_t size)
{
	int *countingArr = NULL, *newArr = NULL, max;
	size_t i, k, Max;


	if (array == NULL || size < 2)
		return;

	max = maximum(array, size);

	countingArr = (int *) malloc(sizeof(int) * (max + 1));
	if (!countingArr)
		return;
	newArr = (int *) malloc(sizeof(int) * size);
	if (!newArr)
		return;
	Max = max + 1;
	for (k = 0; k < Max; k++)
		countingArr[k] = 0;
	for (i = 0; i < size; i++)
		countingArr[array[i]]++;
	k = 1;
	while (k < Max)
	{
		countingArr[k] += countingArr[k - 1];
		k++;
	}
	print_array(countingArr, Max);
	k--;
	while (k > 0)
	{
		countingArr[k] = countingArr[k - 1];
		k--;
	}
	countingArr[0] = 0;
	for (i = 0; i < size; i++)
		newArr[countingArr[array[i]]++] = array[i];
	for (i = 0; i < size; i++)
		array[i] = newArr[i];
	free(newArr);
	free(countingArr);
}
