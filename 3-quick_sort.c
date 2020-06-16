#include "sort.h"
/**
 * permuter - swap
 * @array: array
 * @i: indice
 * @j: indice
 */
void permuter(int *array, int i, int j)
{
	int aux;

	aux = array[i];
	array[i] = array[j];
	array[j] = aux;
}

/**
 * decomp - initialize quick sort
 * @array : array to be sorted
 * @d : debut
 * @f : fin
 * @size : size
 * Return: le indice grand valeur
 */
size_t decomp(int *array, size_t d, size_t f, size_t size)
{
	size_t  i;
	int verif;

	for (i = d; i < f; i++)
	{
		verif = 0;
		if (array[f] > array[i])
		{
			verif = 1;
			if (i != d)
			{
				permuter(array, i, d);
				print_array(array, size);
			}
			if (verif)
				d++;
		}
	}

	if (array[f] < array[d])
	{
		permuter(array, f, d);
		f = d;
		print_array(array, size);
	}
	return (f);
}
/**
 * tri_rapide - sorts an array of integers using the Quick sort algorithm
 * @array : array to be sorted
 * @d : var
 * @f : var
 * @size : size of array
 */
void tri_rapide(int *array, size_t d, size_t f, size_t size)
{
	size_t pivot;

	if (array == NULL)
		return;
	if (size == 0)
		return;
	if (d <= f)
	{
		pivot = decomp(array, d, f, size);
		if (pivot != 0 && pivot > d)
			tri_rapide(array, d, pivot - 1, size);
		if (pivot < size - 1)
			tri_rapide(array, pivot + 1, f, size);
	}
}
/**
 * quick_sort - sort array
 * @array : array to be sorted
 * @size : size of array
 */
void quick_sort(int *array, size_t size)
{
	tri_rapide(array, 0, size - 1, size);
}
