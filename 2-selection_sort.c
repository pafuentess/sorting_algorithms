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
	size_t i, j, tmp1, tmp2;

	for (i = 0; i < size - 1; i++)
	{
		j = i;

		for (tmp1 = i + 1; tmp1 < size; tmp1++)
		{
			if (array[tmp1] < array[j])
				j = tmp1;
		}
		if (i != j)
		{
			tmp2 = array[i];
			array[i] = array[j];
			array[j] = tmp2;
			print_array(array, size);
		}
	}
}
