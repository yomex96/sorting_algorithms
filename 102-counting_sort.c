#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, p;

	for (max = array[0], p = 1; p < size; p++)
	{
		if (array[p] > max)
			max = array[p];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, p;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (p = 0; p < (max + 1); p++)
		count[p] = 0;
	for (p = 0; p < (int)size; p++)
		count[array[p]] += 1;
	for (p = 0; p < (max + 1); p++)
		count[p] += count[p - 1];
	print_array(count, max + 1);

	for (p = 0; p < (int)size; p++)
	{
		sorted[count[array[p]] - 1] = array[p];
		count[array[p]] -= 1;
	}

	for (p = 0; p < (int)size; p++)
		array[p] = sorted[p];

	free(sorted);
	free(count);
}
