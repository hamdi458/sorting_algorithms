#include "sort.h"
/**
 * selection_sort -  sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, aux;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[i])
			{
				aux = array[j];
				array[j] = array[i];
				array[i] = aux;
				print_array(array, size);
			}
		}
	}
}