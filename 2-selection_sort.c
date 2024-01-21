#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - sorts array using selection algorithm
 * @array:the array to be sorted
 * @size:the size of the array
 *
 * Return:None
 */
void selection_sort(int *array, size_t size)
{
	size_t min, i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for(j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
