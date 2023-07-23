#include "sort.h"
void counting_sort(int *array, size_t size)
{
	int *countingArr = NULL, max;
	size_t i = 0, k, Max;

	max = array[i];
	for (; i < size; i++)
		if (array[i] > max)
			max = array[i];

	countingArr = (int*) malloc(sizeof(int) * max + 1);
	if (!countingArr)
		return;

	Max = max + 1;
	for (k = 0; k < Max; k++)
		countingArr[k] = 0;
	for (i = 0; i < size; i++)
		countingArr[array[i]]++;

	print_array(countingArr, Max);
	printf("\n");
/**
	for (k = 0; k < Max - 1; k++)
		countingArr[k + 1] += countingArr[k - 1];

	for (; k > 0; k--)
		countingArr[k] = countingArr[k - 1];
	countingArr[0] = [0];
	*/

	i = 0;
	for (k = 0; k < Max; k++)
	{
		while (countingArr[k] != 0)
		{
			array[i++] = k;
			countingArr[k]--;
		}
	}
}
