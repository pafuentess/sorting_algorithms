#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - function that sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i, count = 0;
	int tmp = 0;
	size_t flag = 0;


	count = size;
	while (count > 0)
	{
		flag = 0;
		for (i = 0 ; i < count - 1 ; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				flag = i + 1;
			}
		}
		count = flag;
	}
}
