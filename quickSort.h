#ifndef _QUICKSORT_H
#define _QUICKSORT_H

#include <stdio.h>

class QuickSort {
public:
	void quickSort(int array[], int left, int right, int pivotIndex);

	void printArray(int array[], int length) {
		for (int i = 0; i < length; ++i) {
			printf("%d ", array[i]);
		}
	}

private:
	int partition(int *array, int left, int right, int pivotIndex, int pivotValue);
};

int QuickSort::partition(int array[], int left, int right, int pivotIndex, int pivotValue) {
	while (left < right) {
		while (left <= right && array[left] <= pivotValue)
			++left;

		while (right >= left && array[right] >= pivotValue)
			--right;

		if (left < right) {
			int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}

	if (right >= 0 && pivotIndex <= right) {
		array[pivotIndex] = array[right];
		array[right] = pivotValue;
	}

	return right;
}

void QuickSort::quickSort(int array[], int left, int right, int pivotIndex) {
	int currentLeft = partition(array, left, pivotIndex - 1, left, array[left]);
	int currrentRight = partition(array, pivotIndex + 1, right, pivotIndex + 1, array[pivotIndex + 1]);

	if (left < pivotIndex - 1)
		quickSort(array, left, pivotIndex - 1, currentLeft);
	
	if (pivotIndex + 1 < right)
		quickSort(array, pivotIndex + 1, right, currrentRight);
	
}

#endif