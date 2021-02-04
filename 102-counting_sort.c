#include "sort.h"

/**
 * max_value - Find max integer in an array
 * @array: Entry data structure
 * @size: size of data structure
 * Return: Max integer
 */

int max_value(int *array, size_t size)
{
	unsigned int i;
	/*Set first index value as a max integer*/
	int max = array[0];

	/*Finds max value in an array*/
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return (max);
}

/**
 * counting_sort - Counting sort algorithm
 * @array: Entry data structure
 * @size: size of data structure
 * Return: Don´t return anything
 */

void counting_sort(int *array, size_t size)
{
	size_t k;
	size_t i;
	/*Declare an array when we set a sorted array*/
	int *copy_array = NULL;
	/*Declare an array when we set the sum of repetition numbers*/
	int *count = NULL;

	if (size < 2 || array == NULL)
		return;

	k = max_value(array, size);

	/*Create an array for count the numbers*/
	count = malloc(sizeof(int) * (k + 1));

	/*Store count of each character*/
	for (i = 0; i < size; i++)
		count[array[i]] = count[array[i]] + 1;
	/*Change count[i] so that count[i] now contains actual*/
	/*position of this character in output array*/
	for (i = 1; i <= k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k + 1);

	copy_array = malloc(sizeof(int) * size);

	/*Build the output character array*/
	for (i = 0; i < size; i++)
	{
		count[array[i]] = count[array[i]] - 1;
		copy_array[count[array[i]]] = array[i];
	}

	/*Copy the sorted copy_array to original array*/
	for (i = 0; i < size; i++)
		array[i] = copy_array[i];
	free(count);
	free(copy_array);
}
