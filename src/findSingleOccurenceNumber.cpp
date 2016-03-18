#include<stdlib.h>
/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

// Sorting the given Array using quickSort -->  (O(nlogn))
void quickSort(int *arr, int left, int right)
{

	int pivot = arr[right], i, leftIndex = left, rightIndex = right;

	while (leftIndex<rightIndex){

		while (arr[leftIndex] < pivot && leftIndex < rightIndex){ leftIndex++; }
		if (leftIndex != rightIndex)  arr[rightIndex] = arr[leftIndex];

		while (arr[rightIndex] >= pivot && leftIndex < rightIndex){ rightIndex--; }
		if (leftIndex != rightIndex) arr[leftIndex] = arr[rightIndex];

	}

	arr[leftIndex] = pivot;

	pivot = leftIndex;
	if (left<pivot)
		quickSort(arr, left, pivot - 1);
	if (pivot<right)
		quickSort(arr, pivot + 1, right);

}


int findSingleOccurenceNumber(int *A, int len) {

	if (A == NULL || len < 1) return -1;

	int i,left = 0, right = len - 1, mid;
	quickSort(A, left, right);
 
	for (i = 0; i < len - 3; i++)
	{

		if (A[i] != A[i + 2]) // if the current and the next 2nd element is not same then return that element
		{
			return A[i];
		}
		else
		{
			i = i + 2;
		}


	}
	// if the Single Occurence element is at the last then return last element
	return A[len - 1];




}