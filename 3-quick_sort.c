#include "sort.h"

void swap_ints(int *y, int *p);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - this func swaps two integers in an array.
 *
 * @y: This is the 1st integer to swap.
 *
 * @p: This is the 2nd integer to swap.
 *
 */

void swap_ints(int *y, int *p)
{
	int tmp;

	tmp = *y;
	*y = *p;
	*p = tmp;
}

/**
 * lomuto_partition - This func orders a subset of an array
 * of integers according to the
 * lomuto partition scheme (last element as pivot).
 *
 * @array: This is the array of int
 *
 * @size: represents the size of the array.
 *
 * @left: represents the starting index of the subset to order.
 *
 * @right: represents the ending index of the subset to order.
 *
 * Return: This is the final partition index.
 *
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - This func implements the
 * quicksort algorithm through recursion.
 *
 * @array: represents an array of integers to sort.
 *
 * @size: represents the size of the array.
 *
 * @left: represents the starting index of
 * the array partition to order.
 *
 * @right: represents the ending
 * index of the array partition to order.
 *
 * Description: Makes use of the Lomuto partition scheme.
 *
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - This fuc sorts an array of integers in
 * ascending order using the quicksort algorithm.
 *
 * @array: represents an array of integers.
 *
 * @size: represents the size of the array.
 *
 * Description: Makes use of the Lomuto partition scheme,
 * Prints the array after each swap of two elements.
 *
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
