/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare1(char *date1, char *date2) {

	int i, year1 = 0, year2 = 0;



	for (i = 6; i<10; i++)
	{
		year1 *= 10;
		year2 *= 10;
		year1 += date1[i] - '0';
		year2 += date2[i] - '0';


	}
	if (year1 != year2) return 0;


	int mon1 = 0, mon2 = 0;
	for (i = 3; i < 5; i++)
	{
		mon1 *= 10;
		mon2 *= 10;
		mon1 += date1[i] - '0';
		mon2 += date2[i] - '0';
	}
	if (mon1 != mon2) return 0;


	int	day1 = 0, day2 = 0;
	for (i = 0; i < 2; i++)
	{
		day1 *= 10;
		day2 *= 10;
		day1 += date1[i] - '0';
		day2 += date2[i] - '0';
	}




	if (day1 != day2) return 0;


	return 1;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	if (A == NULL || B == NULL || ALen<1 || BLen <1) return NULL;
	int i, j, k = 0;

	struct transaction *result = NULL;
	for (i = 0; i < ALen; i++)
	{
		for (j = 0; j < BLen; j++)
		{

			if (compare1(A[i].date, B[j].date))
			{

				result = (struct transaction *)realloc(result, ++k*sizeof(struct transaction));
				result[k - 1] = B[j];
				break;
			}

		}
	}

	if (result != NULL)
	{
		
		return result;
	}

	return NULL;
}


