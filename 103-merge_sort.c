#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * print_merge - prints how the arrays merge
 * @str: string to be printed
 * @array: array to be printed
 * @lb: lower bound
 * @ub: upper bound
 */

void print_merge(char *str, int *array, int lb, int ub)
{
	int i;

	printf("[%s]:", str);
	for (i = lb; i < ub; i++)
	{
		printf(" %d,", array[i]);
	}
	printf(" %d\n", array[i]);
}

/**
 * merge - merge to side of the array into s_array
 * @array: array in which our merged arrray is copied back
 * @lb: lower bound
 * @mid: mid-point of the array
 * @ub: upper bound
 * @s_array: array in which merge occurs
 */

void merge(int *array, int lb, int mid, int ub, int *s_array)
{
	int i = lb, j = mid + 1, k = lb;

	printf("Merging...\n");
	print_merge("left", array, lb, mid);
	print_merge("right", array, j, ub);
	while (i <= mid && j <= ub)
	{
		if (array[i] <= array[j])
			s_array[k++] = array[i++];
		else
			s_array[k++] = array[j++];
	}

	while (i <= mid)
		s_array[k++] = array[i++];

	while (j <= ub)
		s_array[k++] = array[j++];

	for (i = lb; i <= ub; i++)
		array[i] = s_array[i];
	print_merge("Done", array, lb, ub);
}

/**
 * m_sort - Implementation of merge sort algo
 * @array: array to be split by recursion
 * @lb: lower bound
 * @ub: upper bound
 * @s_array: new array in which merge takes place
 */

void m_sort(int *array, int lb, int ub, int *s_array)
{
	int mid;

	if (ub <= lb)
		return;

	mid = (lb + ub - 1) / 2;
	m_sort(array, lb, mid, s_array);
	m_sort(array, mid + 1, ub, s_array);
	merge(array, lb, mid, ub, s_array);
}

/**
 * merge_sort - MergeSort
 * @array: arrays to sort
 * @size: size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *s_array;

	if (!array || size < 2)
		return;

	s_array = malloc(size * sizeof(int));
	if (!s_array)
		return;

	m_sort(array, 0, size - 1, s_array);
	free(s_array);
}
