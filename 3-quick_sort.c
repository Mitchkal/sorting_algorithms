#include "sort.h"
/**
 * swap - swaps two values in an array
 * @a : value a
 * @b : value b
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition- partitions an array
 * picks right most value as pivot
 * @array : the array
 * @size : the array size
 * @hi : biggest array index
 * @lo : lowest index
 * Return: partition index
 */
size_t partition(int *array, int lo, int hi, int size)
{
	int pivot = array[hi];/*holds the pivot*/
	int j = lo;
	int i = lo - 1; /*index of smallest element*/

	for (j = lo; j <= (hi - 1); j++)
	{
		if (pivot >= array[j])
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i != hi)
	{
		swap(&array[i + 1], &array[hi]);
		print_array(array, size);
	}
	return (i + 1);/*return partition index*/
}

/**
 * quick_sort - wrapper for quick_sort function
 * @array : the array
 * @size: the array size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}
/**
 * sort - does the recursive quick sort
 * @lo : lowest index
 * @hi : highest index
 * @array : the array
 * @size : the array size
 */
void sort(int *array, int lo, int hi, int size)
{
	 /*partition index*/
	size_t p_index;

	if (lo < hi)
	{
		p_index = partition(array, lo, hi, size);

		sort(array, lo, p_index - 1, size);
		sort(array, p_index + 1, hi, size);
	}
}
