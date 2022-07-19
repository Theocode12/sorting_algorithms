#include "sort.h"

/**
 * selection_sort - Implementation of selection sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j, idx_min, tmp, flag;

    if (size < 2)
        return;

    for (i = 0; i < size; i++)
    {
        idx_min = i;
        flag = 0;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[idx_min])
            {
                idx_min = j;
                flag = 1;
            }
        }
        tmp = array[idx_min];
        array[idx_min] = array[i];
        array[i] = tmp;
        if (flag)
            print_array(array, size);
    }
}
