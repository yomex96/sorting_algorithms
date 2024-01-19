#include "sort.h"

/**
 * arr_zero_init - initialize array by 0
 *
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int p;

	for (p = 0; p < size; p++)
		array[p] = 0;
}

/**
 * get_max - gets the maximum value in the array
 *
 * @array: array to get max value from
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int maxi;
	size_t p;

	if (size < 2)
		return (0);

	maxi = array[0];	/* start from first index */

	for (p = 1; p < size; p++)
	{
		if (maxi < array[p])
			maxi = array[p];
	}

	return (maxi);
}

/**
 * counting_sort - sorts an array using the counting
 * sort algorithm
 *
 * @array: initial array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int n = get_max(array, size), m, *position, *sumPosition, *sorted;
	size_t p;

	if (n == 0)
		return;

	position = malloc(sizeof(int) * (n + 1));
	if (!position)
		return;
	arr_zero_init(position, n + 1);

	for (p = 0; p < size; p++)
		position[array[p]] += 1;    /* set one to the positions */

	sumPosition = malloc(sizeof(int) * (n + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, n + 1);
	sumPosition[0] = position[0];   /* make first index equal */

	for (m = 1; m < (n + 1); m++)
		sumPosition[m] = position[m] + sumPosition[m - 1];

	free(position), print_array(sumPosition, n + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (p = 0; p < size; p++)  /* get the sorted array */
	{
		sumPosition[array[p]] -= 1;
		sorted[sumPosition[array[p]]] = array[p];
	}
	free(sumPosition);

	for (p = 0; p < size; p++)  /* update array */
	
		array[p] = sorted[p];
	free(sorted);
}
