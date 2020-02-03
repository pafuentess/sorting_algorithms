#include "sort.h"
#include <stdio.h>

size_t partition(int *array, size_t size, size_t left, size_t right)
{
	int pivot;
	size_t i, tmp1, parttition;
	
	parttition = left - 1;
	pivot = array[right];
	i = left;

	while (i <= right)
	{
		if (array[i] <= pivot)
		{
			parttition++;
			if (parttition != i)
			{
				tmp1 = array[parttition];
				array[parttition] = array[i];
				array[i] = tmp1;
				print_array(array, size);
			}
		}
		i++;
	}
	return (parttition);
}

void quicksort(int *array, size_t size, ssize_t left, ssize_t right)
{
	ssize_t pivot;

	if (left < right)
	{
		pivot = partition(array, size, left, right);
		quicksort(array, size,  left, pivot - 1);
		quicksort(array, size,  pivot + 1, right);

	}
}

void quick_sort(int *array, size_t size)
{
	quicksort(array, size,  0, size - 1);
}
