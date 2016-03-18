/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare2(char *date1, char *date2) {// compares the date and returns the value accordingly 

	int i, year1 = 0, year2 = 0;


	for (i = 6; i<10; i++)
	{
		year1 *= 10;
		year2 *= 10;
		year1 += date1[i] - '0';
		year2 += date2[i] - '0';


	}



	int mon1 = 0, mon2 = 0;
	for (i = 3; i < 5; i++)
	{
		mon1 *= 10;
		mon2 *= 10;
		mon1 += date1[i] - '0';
		mon2 += date2[i] - '0';
	}
	if (mon1 >12 || mon2> 12) return -1;


	int	day1 = 0, day2 = 0;
	for (i = 0; i < 2; i++)
	{
		day1 *= 10;
		day2 *= 10;
		day1 += date1[i] - '0';
		day2 += date2[i] - '0';
	}



	if (year1 < year2)
	{
		return 1;
	}
	else if (year1 > year2)
		return 2;

	if (mon1 < mon2)
	{
		return 1;
	}
	else if (mon2 < mon1)
		return 2;


	if (day1 < day2)
	{
		return 1;
	}
	else if (day2 < day1)
		return 2;


	return 0;
}




struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (ALen < 1 || BLen < 1 || A == NULL || B == NULL) return NULL;

	int TLen = ALen + BLen, i = 0, j = 0, k = 0, value;

	struct transaction *result = (struct transaction*)calloc(TLen, sizeof(struct transaction));

	while (i != ALen && j != BLen)// copies the values into result array in ascending order
	{
		value = compare2(A[i].date, B[j].date);
		if (value == 0)
		{
			result[k++] = A[i++];
			result[k++] = B[j++];

		}
		else if (value == 1)
		{
			result[k++] = A[i++];
		}
		else if (value == 2)
		{
			result[k++] = B[j++];
		}

	}

	if (i < ALen)
	{
		while (i != ALen)
		{
			result[k++] = A[i++];
		}

	}
	else if (j != BLen)
	{

		while (j != BLen)
		{
			result[k++] = B[j++];
		}
	}


	return result;
}