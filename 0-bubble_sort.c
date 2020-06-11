#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 *sort algorithm
 * @array: The arry to be sorted
 *@size: the size of array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, aux;


	for (i = size - 1; i >= 1; i--)
	{
		for (j = 0; j <= i - 1; j++)
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;
				print_array(array, size);
			}
	}
}
