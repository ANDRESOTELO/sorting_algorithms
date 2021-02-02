#include "sort.h"

/**
 * partition - Funcion that create partition of array based on pivot
 * @array: Entry data estructure
 * @low: low element
 * @high: high element
 * @size: size of array
 * Return: integer
 */

int partition(int *array, unsigned int low, unsigned int high, size_t size)
{
	int pivot;
	unsigned int i, j;
	int temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i);
}

/**
 * _quick - Func. sorts an array of int using quick sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * @low: lower element
 * @high: higher element
 * Return: Don´t return anything
 */

void _quick(int *array, unsigned int low, unsigned int high, size_t size)
{
	if (low < high)
	{
		unsigned int p = partition(array, low, high, size);

		_quick(array, low, p - 1, size);
		_quick(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Func. sorts an array of int using quick sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * Return: Don´t return anything
 */

void quick_sort(int *array, size_t size)
{
	if (size == 0)
		return;

	_quick(array, 0, size - 1, size);
}
