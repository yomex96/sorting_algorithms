#include "sort.h"

/**
 * swap_pos - swaps position of values in array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * selection_sort - uses the selection algo to sort
 * an array
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t m, n;
	int min_val, min_index, flag;

	if (size < 2)
		return;

	for (m = 0; m < size; m++)
	{
		min_val = array[m];
		min_index = m;
		flag = 0;

		for (n = m + 1; n < size; n++)	/* start from the unsorted part */
		{
			if (min_val > array[n])  /* check for min value */
			{
				min_val = array[n];
				min_index = n;
				flag = 1;
			}
		}

		if (flag)
		{
			swap_pos(&array, m, min_index);
			print_array(array, size);
		}
	}
}
