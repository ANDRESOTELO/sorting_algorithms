#include "sort.h"

/**
 * bubble_sort - Function sorts an array of int using Bubble sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * Return: Don´t return anything
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i;
	unsigned int j;
	int temp = 0;

	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1 - i; j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
