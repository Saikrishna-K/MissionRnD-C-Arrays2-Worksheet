/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdlib.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare(char *date1, char *date2) {

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




int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	if (Arr == NULL || len < 1){ return -1; }


	int first = 0, last = len - 1, value = -1, value1 = -1, mid, result;
	//binary search
	while (first < last)
	{
		mid = (first + last) / 2;


		value = compare(date, Arr[mid].date);


		if (value == 0)// if dates are same 
		{
			if (0 != compare(date, Arr[mid + 1].date)){// if there are more than one transaction on the same day

				return 	result = len - mid - 1;
			}
			else {

				first = mid + 1;
			}

		}

		else if (value == 2)
		{
			first = mid + 1;

		}
		else if (value == 1)
		{
			last = mid - 1;
		}


	}

	if (first >= last)
		return 0;

	return -1;

}