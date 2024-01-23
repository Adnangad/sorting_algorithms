#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * part - Lomuto partition scheme for quicksort.
 * @array: Array to be partitioned.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * @size:siaze of array/
 * Return: The partition index.
 */
int part(int *array, size_t size, int low, int high)
{
	int *pivot = array + high;
	int start, end;

	for (start = end = low; end < high; end++)
	{
		if (array[end] < *pivot)
		{
			if (start < end)
			{
				swap(array + end, array + start);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > *pivot)
	{
		swap(array + start, pivot);
		print_array(array, size);
	}
	return (start);
}

/**
 * helper - Recursive helper function for quicksort.
 * @array: Array to be sorted.
 * @low: Starting index of the array.
 * @high: Ending index of the array.
 * @size:size of array
 *
 * Return:none
 */
void helper(int *array, size_t size, int low, int high)
{
	int p;

	if (low < high)
	{
		p = part(array, size, low, high);
		helper(array, size, low, p - 1);
		helper(array, size, p + 1, high);
	}
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	helper(array, size, 0, size - 1);
}

