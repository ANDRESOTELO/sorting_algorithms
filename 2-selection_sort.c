#include "sort.h"

/**
 * selection_sort - Func. sorts an array of int using Selection sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * Return: Don´t return anything
 */

void selection_sort(int *array, size_t size)
{
	unsigned int min_value, temp;
	unsigned int i, j;

	for (i = 0; i < size - 1; i++)
	{
		min_value = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_value])
				min_value = j;
		}
		if (min_value != i)
		{
			temp = array[i];
			array[i] = array[min_value];
			array[min_value] = temp;
			print_array(array, size);
		}
	}
}
