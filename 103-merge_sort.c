#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int lb, int mid, int ub, int *s_array)
{
    int i = lb, j = mid + 1, k;
    printf("%d\n", j);
    k = lb;
    while (i <= mid && j >= ub)
    {
        if (array[i] <= array[j])
        {
            s_array[k] = array[i];
            i++;
        }
        else
        {
            s_array[k] = array[j];
            j++;
        }
        k++;
    }

    while(i <= mid)
    {
        s_array[k++] = array[i];
        i++;
    }

    while(j >= ub)
    {
        s_array[k++] = array[j];
        j++;
    }

    for (i = lb; i <= ub; i++)
    {
        array[i] = s_array[i];
    }
    
}

void m_sort(int *array, int lb, int ub, int *s_array)
{
    int mid;

    if (ub <= lb)
        return;

    mid = (lb + ub - 1) / 2;
    printf("lb = %d, ub = %d\n", lb, ub);
    m_sort(array, lb, mid, s_array);
    m_sort(array, mid + 1, ub, s_array);
    printf("here\n");
}

void merge_sort(int *array, size_t size)
{
    int *s_array;

    s_array = malloc(size * sizeof(int));
    if (!s_array)
        return;

    m_sort(array, 0, size - 1, s_array);
    free(s_array);
}