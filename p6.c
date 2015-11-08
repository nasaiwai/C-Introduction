/*
 * Assignment 6		p6.c		Due July 24, 2015
 *
 * This program will use functions and a one-dimensional array 
 * to sort and print lowest and highest of temperatures.
 * Pointer notation is used in function swap().
 * 
 */

#include <stdio.h>
#define NUM_TEMP 6	//The number of user input of tempratures

void readInput(double a[]);		//Input tempratures to fill array
void bubbleSort(double a[]);		//Sort using bubble sort
void swap(double *p, double *q);	//Swap two inputs

/*
 * Read users input. Driver for functions.
 * Print out sorted and unsorted array and highest and lowest temperatures.
 */
int main (void)
{
	char choice;	//User's choice for the continuation of the program
	double weather[NUM_TEMP] = {77.7, 55.5, 88.8, 99.9, 66.6, 100};


	do	//Repeat program if user wishes to
	{	

	/* Print out unsorted temperature array */
	printf("Temperatures:	");
	for(int i=0; i< NUM_TEMP; i++)
		printf("%.1lf ", weather[i]);
	printf("\n");

	/* Print out sorted temperature array */
	bubbleSort(weather);
	printf("Sorted:		");
	for(int i=0; i<NUM_TEMP; i++)
		printf("%.1lf ", weather[i]);
	printf("\n");

	/* Print out lowest and highest temperature */
	printf("Lowest:		%.1lf \n", weather[0]);
	printf("Highest:	%.1lf \n", weather[NUM_TEMP-1]);

	printf("Want to calculate temperature? ");
	scanf("%c", &choice);	//Read user input
	getchar();		//Read <ENTER> key
	printf("\n");
	if(choice !='n' && choice !='N')
		readInput(weather);
	} while(choice !='n' && choice !='N');	//Stop if user input is 'n' or 'N'
}



/*
 * Function readInput(double a[]) will read user input into a temporary variable.
 * If input is valid, then assign into the 1-dimensional array.
 * If input is invalid, repeat the prompt until valid number is entered.
 * @parameter a[] stores all six user input for tempratures
 * The function returns type of void which takes double as parameter
 */
void readInput(double a[])
{
	double num;			//Temporary input number
	for(int i=0; i<NUM_TEMP; i++) {	//Loop through array elements
		printf("ENTER Temperature #%d: ", i+1);		//1st, 2nd, 3rd, ...
		scanf("%lf", &num);	//Read input into temp variable
		getchar();		//Read <ENTER> key
		if(num < 0 || num > 100) {
			printf("ERROR! Enter a number (0-100)! \n");
			i--;
		}
		else a[i] = num;	//Valid input, assign into array
	}
}



/*
 * Function bubbleSort(double a[]) use "bubble sort" algorithm by bubbling up 
 * the smallest value into first element.
 * @parameter a[] stores user input for tempraturess
 * The function returns type of void which takes double as parameters.
 */
void bubbleSort(double a[])
{
	int i, j;
	for(i=0; i<NUM_TEMP-1; ++i)
		for(j=NUM_TEMP-1; i<j; --j)
			if(a[j-1] > a[j])
				swap(&a[j-1], &a[j]);	//Swap 2 elements
}



/*
 * Function swap(int *p1, int *p2) will switch the values of temperatures 
 * using pointers.
 * @parameter *p1, *p2 stores user input for tempratures
 * The function returns type of void which takes double as parameters.
 */
void swap(double *p1, double *p2)
{
	double temp;	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

