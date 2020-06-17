#include "sort.h"
/**
 * shell_sort -  sorts an array in ascending order using the Shell sort
 *@array : array to be sorted
 *@size : size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, h = 1, j;
	int v;

	while (h <= size)
		h = 3 * h + 1;
	while (h > 1)
	{
		h = h / 3;
		for (i = h; i < size; i++)
		{
			if (array[i] < array[i - h])
			{
				v = array[i];
				j = i;
				while (j >= h  &&  array[j - h] > v)
				{
					array[j] = array[j - h];
					j = j - h;
				}
				array[j] = v;
			}
		}
		print_array(array, size);
	}
}
