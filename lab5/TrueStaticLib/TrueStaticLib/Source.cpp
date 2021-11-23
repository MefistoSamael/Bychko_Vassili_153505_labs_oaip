#include "Header.h"
#include "pch.h"

void search(int* array, int size, int& min, int k)
{
	if (min > array[k]) min = array[k];
	k--;

	if (k == 0)
	{
		return;
	}
	search(array, size, min, k);
}