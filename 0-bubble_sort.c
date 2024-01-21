#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - an algorithm that sorts an array
 * @array:the array to be sorted
 * @size:the size of the array
 *
 * Return:none
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp;
	size_t j = 0;

	while (j < size)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
		j++;
	}
}
