#include "sort.h"
/**
 * merge - helping function that merges the partitions
 *@leftArr: left partition
 *@rightArr: right partition
 *@array: the array to sort
 *@size:the size of the array to sort
 */
void merge(int *leftArr, int *rightArr, int *array, size_t size)
{
	size_t leftSize = size / 2, rightSize = size - leftSize;
	size_t i = 0, lef = 0, rig = 0;

	printf("Merging...\n[left]: ");
	while (lef < leftSize)
	{
		if (lef < leftSize - 1)
			printf("%d, ", leftArr[lef++]);
		else
			printf("%d\n", leftArr[lef++]);
	}
	printf("[right]: ");
	while (rig < rightSize)
	{
		if (rig < rightSize - 1)
			printf("%d, ", rightArr[rig++]);
		else
			printf("%d\n", rightArr[rig++]);
	}
	lef = 0;
	rig = 0;
	while (lef < leftSize && rig < rightSize)
	{
		if (leftArr[lef] < rightArr[rig])
			array[i++] = leftArr[lef++];
		else
			array[i++] = rightArr[rig++];
	}
	while (lef < leftSize)
		array[i++] = leftArr[lef++];
	while (rig < rightSize)
		array[i++] = rightArr[rig++];
	free(leftArr);
	printf("[Done]: ");
	for (i = 0; i < size; i++)
		if (i < size - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
}
/**
 * merge_sort - sorts an array of integers using the merge sorting algorithm
 *@array: a pointer to the array to sort
 *@size:the size of the array to sort
 */
void merge_sort(int *array, size_t size)
{
	size_t middle;
	int *leftArr = NULL;
	int *rightArr = NULL;
	size_t i = 0, j = 0;

	if (size < 2)
		return;
	middle = size / 2;

	leftArr = (int *) malloc(sizeof(int) * size);
	if (!leftArr)
		return;
	rightArr = leftArr + middle;

	for (; i < size; i++)
	{
		if (i < middle)
			leftArr[i] = array[i];
		else
			rightArr[j++] = array[i];
	}
	merge_sort(leftArr, middle);
	merge_sort(rightArr, size - middle);
	merge(leftArr, rightArr, array, size);
}
