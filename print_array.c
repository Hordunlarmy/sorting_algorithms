#include "sort.h"

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: size of the array
 * Return: Nothing
 */
void print_array(const int *array, size_t size)
{
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
