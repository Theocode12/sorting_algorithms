#include "sort.h"

/**
 * swap - swap the elements in the array
 * @array: array
 * @curr_index: current index
 * @p_index: pivot index
 */

void swap(int *array, int curr_index, int p_index)
{
	int temp;

	temp = array[curr_index];
	array[curr_index] = array[p_index];
	array[p_index] = temp;
}

/**
 * qs_partition - partitions the array
 * @array: array
 * @lb: lower bound
 * @up: upper bound
 * @size: size of array
 * Return: pivot index
 */

int qs_partition(int *array, int lb, int up, int size)
{
	int i, pivot, p_index;

	pivot = array[up];
	p_index = lb;
	for (i = lb; i < up; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, i, p_index);
			if (p_index != i)
				print_array(array, size);
			p_index++;
		}
	}
	swap(array, i, p_index);
	if (p_index != i)
		print_array(array, size);

	return (p_index);
}

/**
 * q_sort_algo - Implementation of quick sort algorithm
 * @array: array
 * @lb: lower bound
 * @up: upper bound
 * @size: size of array
 */

void q_sort_algo(int *array, int lb, int up, size_t size)
{
	int p_index;

	if (lb < up)
	{
		p_index = qs_partition(array, lb, up, size);

		q_sort_algo(array, lb, p_index - 1, size);
		q_sort_algo(array, p_index + 1, up, size);
	}
}

/**
 * quick_sort - quick sort
 * @array: array
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	q_sort_algo(array, 0, size - 1, size);
}
