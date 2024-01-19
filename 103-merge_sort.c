#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - This funcs will sort a subarray of int
 *
 * @subarr: This is a subarray of an array of integers to sort.
 *
 * @buff: This is a buffer to store the sorted subarray.
 *
 * @front: This is the front index of the array.
 *
 * @mid: This is the middle index of the array.
 *
 * @back: This is the back index of the array.
 *
 */

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t o, p, q = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (o = front, p = mid; o < mid && p < back; q++)
		buff[q] = (subarr[o] < subarr[p]) ? subarr[o++] : subarr[p++];
	for (; o < mid; o++)
		buff[q++] = subarr[o];
	for (; p < back; p++)
		buff[q++] = subarr[p];
	for (o = front, q = 0; o < back; o++)
		subarr[o] = buff[q++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - This func will implement
 * the merge sort algorithm through recursion.
 *
 * @subarr: This is the subarray of an array of integers to sort.
 *
 * @buff: This is the buffer to store the sorted result.
 *
 * @front: This is the front index of the subarray.
 *
 * @back: This is the back index of the subarray.
 *
 */

void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - This func sorts an array of int
 * in ascending order using merge sort algorithm.
 *
 * @array: This is an array of integers.
 *
 * @size: This is the size of the array.
 *
 * Description: only implements the top-down merge sort algorithm.
 *
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
