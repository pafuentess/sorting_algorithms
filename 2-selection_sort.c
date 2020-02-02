#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, i_tmp, tmp;

	for (i = 0; i < size - 1; i++)
	{
		j = i;

		for (i_tmp = i + 1; i_tmp < size; i_tmp++)
		{
			if (array[i_tmp] < array[j])
				j = i_tmp;
		}
		if (i != j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
}
