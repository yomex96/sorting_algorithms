#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - This func gets maximum value in an array of int
 *
 * @array: This an array of int
 *
 * @size: This is the size of the array.
 *
 * Return: The max int in the array.
 *
 */

int get_max(int *array, int size)
{
	int max, eye;

	for (max = array[0], eye = 1; eye < size; eye++)
	{
		if (array[eye] > max)
			max = array[eye];
	}

	return (max);
}

/**
 * radix_counting_sort - This func will sort the significant
 * digits of an array of int in ascending order using
 * counting sort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * @sig: This is the significant digit to sort on.
 *
 * @buff: Represents the buffer to store the sorted array.
 *
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t eye;

	for (eye = 0; eye < size; eye++)
		count[(array[eye] / sig) % 10] += 1;

	for (eye = 0; eye < 10; eye++)
		count[eye] += count[eye - 1];

	for (eye = size - 1; (int)eye >= 0; eye--)
	{
		buff[count[(array[eye] / sig) % 10] - 1] = array[eye];
		count[(array[eye] / sig) % 10] -= 1;
	}

	for (eye = 0; eye < size; eye++)
		array[eye] = buff[eye];
}

/**
 * radix_sort - This func will sort an array of int
 * in ascending order using the radix sort algorithm.
 *
 * @array: This is an array of int
 *
 * @size: This is the size of the array.
 *
 * Description: Only implements the LSD radix sort algorithm.
 * Prints the array after each significant digit increase.
 *
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
