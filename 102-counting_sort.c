#include "sort.h"
/**
 *counting_sort - sorts an array using the Counting sort algorithm
 *@array : array to be sorted
 *@size : size of array
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int *tc, min, max, j, k;

	min = array[0];
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];

	}
	tc = malloc(sizeof(int) * (max + 1));
	for (k = 0; k <= max; k++)
		tc[k] = 0;
	for (i = 0; i < size; i++)
		tc[array[i]] = tc[array[i]] + 1;
	i = 0;
	for (k = 0; k <= max + 1; k++)
		tc[k] = tc[k] + tc[k - 1];
	for (j = 0; j < max; j++)
	{
		array[tc[i]] = j + 1;
		i++;
	}
	print_array(tc, max + 1);
	free(tc);
}
