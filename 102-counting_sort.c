#include "sort.h"
#include <stdlib.h>

/**
 * _max - max value in an array of integers
 * @array: array of integers
 * @size: size of array
 * Return: max value in an array of integer
 */

int _max(int *array, size_t size)
{
    size_t max, i;

    max = array[0];
    for (i = 0; i <= size; i++)
    {
        if (array[i] > (int)max)
            max = array[i];
    }
    return (max);
}

/**
 * counting_sort - Implementation of counting sort algorithm
 * @array - array of integers
 * @size - size of the array 
 */

void counting_sort(int *array, size_t size)
{
    int max, *count_arr, i, *nw_array;

    if (size < 2)
        return;
    max = _max(array, size - 1);
    max++;
    count_arr = malloc(max * sizeof(int));
    if (!count_arr)
        return;

    for (i = 0; i < max; i++)
        count_arr[i] = 0;

    for (i = 0; i < (int)size; i++)
        count_arr[array[i]]++;
    for (i = 1; i < max; i++)
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    print_array(count_arr, max);

    nw_array = malloc(size * sizeof(int));
    if (!nw_array)
        return;

    for (i = size - 1; i >= 0; i--)
        nw_array[--count_arr[array[i]]] = array[i];

    for (i = 0; i < (int)size; i++)
        array[i] = nw_array[i];

    free(count_arr);
    free(nw_array);
}
