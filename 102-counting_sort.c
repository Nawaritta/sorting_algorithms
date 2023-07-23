#include "sort.h"
void counting_sort(int *array, size_t size)
{
	int *countingArr = NULL, *newArr = NULL;
	int value, max;
	size_t i, k, Max, value_ocuurence;


	if (array == NULL || size == 0)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	countingArr = (int*) malloc(sizeof(int) * (max + 1));
	if (!countingArr)
		return;

	newArr = (int*) malloc(sizeof(int) * size);
	if (!newArr)
		return;

	Max = max + 1;
	for (k = 0; k < Max; k++)
		countingArr[k] = 0;
	for (i = 0; i < size; i++)
       		countingArr[array[i]]++;

	k = 1;
	while(k < Max)
	{
		countingArr[k] += countingArr[k - 1];
		k++;
	}
	print_array(countingArr, Max);
	k--;
	while(k > 0)
	{
		countingArr[k] = countingArr[k - 1];
		k--;
	}
	countingArr[0] = 0;

       	for (i = 0; i < size; i++)
	{
		value = array[i];
		value_ocuurence = countingArr[value];
		countingArr[value]++;
		newArr[value_ocuurence] = value;
	}

	for (i = 0; i < size; i++)
		array[i] = newArr[i];

	free(newArr);
	free(countingArr);
}
