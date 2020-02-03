#include "sort.h"
#include <stdio.h>

/**
 * partition -  function that split the array with an pivot
 * @array: array of integers
 * @size: size of array
 * @left: to the left
 * @right: to the right
 * Return: nothing
 */

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

/**
 * quicksort - sort an array of integers using partition
 * @array: array of integers
 * @size: size of array
 * @left: to the left
 * @right: to the right
 * Return: nothing
 */

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

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	quicksort(array, size,  0, size - 1);
}
