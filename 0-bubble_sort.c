#include "sort.h"
/**
 * bubble_sort - bubblesorts integer array in ascening
 * @array: the array
 * @size: the array size
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	int temp = 0;
	size_t i, j;

	for (i = 0 ; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
		}
		print_array(array, size);
		if (!swapped)
			break;
	}
}
