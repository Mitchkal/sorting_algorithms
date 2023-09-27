#include "sort.h"
/**
 * selection_sort - performs a selection sort on array'
 * @array: the array
 * @size: the array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t imin;
	int temp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/*assume first is minimum*/
		imin = i;
		/*loop through remainder*/
		for (j = imin + 1; j < size; j++)
		{
			/*change imin to index of min if found*/
			if (array[j] < array[imin])
				imin = j;
		}
		/*swap if imin is not equal to first value*/
		if (imin != i)
		{
			/*swap*/
			temp = array[i];
			array[i] = array[imin];
			array[imin] = temp;
			print_array(array, size);
		}
	}
}
