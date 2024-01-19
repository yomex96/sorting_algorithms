#include "sort.h"

void swap_ints(int *u, int *v);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - This func will swap
 * two integers in an array.
 *
 * @u: This is the 1st int to swap.
 *
 * @v: This is the 2nd int to swap.
 *
 */

void swap_ints(int *u, int *v)
{
	int tmp;

	tmp = *u;
	*u = *v;
	*v = tmp;
}

/**
 * hoare_partition - This func orders a subset of an array
 * of int according to the hoare partition scheme.
 *
 * @array: This is the array of int
 *
 * @size: This is the size of the array.
 *
 * @left: This is the starting index of the subset
 *
 * @right: This is the ending index of the subset
 *
 * Return: Final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 *
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Thi func implements the
 * quick sort algorithm through recursion.
 *
 * @array: This is an array of int to sort.
 *
 * @size: This is the size of the array.
 *
 * @left: This is the starting index of the array partition
 *
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 *
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int myPart;

	if (right - left > 0)
	{
		myPart = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, myPart - 1);
		hoare_sort(array, size, myPart, right);
	}
}

/**
 * quick_sort_hoare - This func will sort an array of int
 * in ascending order using the quicksort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 * Prints the array after each swap of two elements.
 *
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
