#include "sort.h"

/**
 * partition - Funcion that create partition of array based on pivot
 * @array: Entry data estructure
 * @low: low element
 * @high: high element
 * @size: size of array
 * Return: integer
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = 0;
	int temp = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}

/**
 * _quick_sort - Func. sorts an array of int using quick sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * @low: lower element
 * @high: higher element
 * Return: Don´t return anything
 */

void _quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int p = partition(array, low, high, size);

		_quick_sort(array, low, p - 1, size);
		_quick_sort(array, p + 1, high, size);
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

	_quick_sort(array, 0, size - 1, size);
}
