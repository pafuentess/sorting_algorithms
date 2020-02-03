#include "sort.h"


/**
* shell_sort - function that sorts an array of
* integers in ascending order using the Shell sort
* @array: array to sort
* @size: lenght to the array
*/

void shell_sort(int *array, size_t size)
{
	size_t interval = 1;
	size_t left = 0, middle = 0;
	int swap = 0;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (left = interval ; left < size ; left++)
		{
			swap = array[left];
			middle = left;

			while (middle > interval - 1 && array[middle - interval] >= swap)
			{
				array[middle] = array[middle - interval];
				middle = middle - interval;
			}
			array[middle] = swap;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
