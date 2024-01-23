#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * part - Partition the array for quicksort
 * @arr: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot element after partition
 */
int part(int *arr, size_t low, size_t high)
{
	int start, end, temp, temp1, pivot;

	start = high;
	end = low - 1;
	pivot = arr[high];

	while (start > end)
	{
		while (arr[start] >= pivot)
			start--;

		while (arr[end] < pivot)
			end++;

		if (start > end)
		{
			temp = arr[start];
			arr[start] = arr[end];
			arr[end] = temp;
			print_array(arr, high + 1);
		}
	}

	temp1 = arr[high];
	arr[high] = arr[end];
	arr[end] = temp1;
	print_array(arr, high + 1);

	return (end);
}

/**
 * helper - Recursive function to perform quicksort
 * @arr: Array to be sorted
 * @low: Starting index of the partition to be sorted
 * @high: Ending index of the partition to be sorted
 */
void helper(int *arr, size_t low, size_t high)
{
	int pi;

	if (low < high)
	{
		pi = part(arr, low, high);

		if (pi > 0)
			helper(arr, low, pi - 1);

		if ((size_t)(pi + 1) <= high)
			helper(arr, pi + 1, high);
	}
}

/**
 * quick_sort - Function to sort an array using quicksort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	helper(array, 0, size - 1);
}

