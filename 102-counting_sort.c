#include "sort.h"

/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int i, k;
	int *count, *cpy;
	size_t j, tmp, final_arr = 0;

	if (array == NULL || size < 2)
		return;

	cpy = malloc(size * sizeof(int));
	if (cpy == NULL)
		return;
	for (j = 0, k = 0; j < size; j++)
	{
		cpy[j] = array[j];
		if (array[j] > k)
			k = array[j];
	}
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(cpy);
		return;
	}
	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]] += 1;
	for (i = 0; i <= k; i++)
	{
		tmp = count[i];
		count[i] = final_arr;
		final_arr += tmp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[cpy[j]]] = cpy[j];
		count[cpy[j]] += 1;
	}
	print_array(count, k + 1);
	free(count);
	free(cpy);
}
