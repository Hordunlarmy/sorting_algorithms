#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm.
 *
 * @array: the array to be sorted.
 * @size: the size of the array.
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_sub(array, 0, size - 1, size);
}

/**
 * quick_sort_sub - recursively sorts the array of
 *              integers in ascending order.
 *
 * @array:the array to be sorted.
 * @start: the starting index.
 * @end: the final index.
 * @size: the size of the array.
 * Return: Nothing
 */
void quick_sort_sub(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = lomuto_partition_scheme(array, start, end, size);
		quick_sort_sub(array, start, pivot_index - 1, size);
		quick_sort_sub(array, pivot_index + 1, end, size);
	}
}
/**
 * lomuto_partition_scheme - partitions the array
 *              using the Lomuto partition scheme.
 * @array: the array to be partitioned.
 * @start: the starting index of the partition.
 * @end: the final index of the partition.
 * @size: the size of the array.
 * Return: the index of the pivot after partition.
 */
int lomuto_partition_scheme(int *array, int start, int end, size_t size)
{
	int i, j, pivot_value, temp;

	pivot_value = array[end];
	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] < pivot_value)
		{
			if (i < j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > array[end])
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (i);
}
