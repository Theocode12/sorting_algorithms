#include "sort.h"

/**
 * shell_sort - Implementation of shell sort algorithm
 * @array: array of integers
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
    int gap = 1, i, val, idx_min;

    if (size < 2)
        return;
    while (gap < (int)size / 3)
        gap = gap * 3 + 1;

    while (gap > 0)
    {
        for (i = gap; i < (int)size; i++)
        {
            val = array[i];
            idx_min = i;
            while(idx_min >= gap && val < array[idx_min - gap])
            {
                array[idx_min] = array[idx_min - gap];
                idx_min -= gap;
            }
            array[idx_min] = val;
        }
        gap = (gap - 1) / 3;
        print_array(array, size);
    }
}
