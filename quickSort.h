#ifndef _QUICKSORT_H
#define _QUICKSORT_H

class QuickSort {
public:
	void quickSort(int array[], int left, int right); //array index range [left, right]

private:
	int selectPivot(int array[], int left, int right);
	int partition(int *array, int left, int right, int pivotIndex);
};

//ÖÐÎ»Êý
int QuickSort::selectPivot(int array[], int left, int right) {
	int middle = (left + right) >> 1;
	int temp[4] = {array[left], array[right], left, right};
	
	//keep temp[0] > temp[1]
	if (array[left] < array[right]) {
		temp[0] = array[right];
		temp[1] = array[left];
		temp[2] = right;
		temp[3] = left;
	}

	if (array[middle] > temp[0])
		return temp[2];

	if (array[middle] < temp[1])
		return temp[3];

	return middle;
}

int QuickSort::partition(int array[], int left, int right, int pivotIndex) {
	int pivotValue = array[pivotIndex];

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

	if (pivotIndex < right) {
		array[pivotIndex] = array[right];
		array[right] = pivotValue;
	}
	else if (pivotIndex > left){
		array[pivotIndex] = array[left];
		array[left] = pivotValue;
	}

	return right;
}

void QuickSort::quickSort(int array[], int left, int right) {
	if (left < right) {
		int pivotIndex = selectPivot(array, left, right);
		int sortedIndex = partition(array, left, right, pivotIndex);

		quickSort(array, left, sortedIndex - 1);
		quickSort(array, sortedIndex + 1, right);
	}
}

#endif