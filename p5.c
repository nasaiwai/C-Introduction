/*
 * Assignment 5		p5.c		Due July 22, 2015
 *
 * This program sorts 3 student's ages using pointers and functions.
 * The values are swapped to arrange in ascending and desceding sorted order.
 * 
 */

#include <stdio.h>
#define MIN 0		//Minimum age for student's age input
#define MAX 70		//Maximum age for student's age input


/*
 * Function swap(int *p1, int *p2) will switch the values of student 
 * ages using pointers.
 * @parameter *p1, *p2 stores user input for ages
 * The function returns type of void which takes int as parameters.
 */
void swap(int *p1, int *p2)
{
	int temp;	
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


/*
 * Read users input. Driver for functions.
 * Print out after each sorting.
 */
int main (void)
{
	char choice;	//User's choice for the continuation of program
	int age1;	//1st student's age
	int age2;	//2nd student's age
	int age3;	//3rd student's age
	
	do	//Repeat program if user wishes to
	{	
		do	//Repeat if invalid input of ages are typed

		{
			printf("Enter 3 Student ages to sort (%d-%d):	", MIN, MAX);
			scanf("%d", &age1);	//Read 1st student's age
			scanf("%d", &age2);	//Read 2nd student's age
			scanf("%d", &age3);	//Read 3rd student"s age
			getchar();		//Read <ENTER> key	
			if((age1 < MIN || age1 > MAX) || (age2 < MIN || age2 > MAX) || (age3 < MIN || age3 > MAX))
			{
				printf("ERR: Student ages out of range(%d-%d)! \n", MIN, MAX);
				printf("\n");
			}
		} while((age1 < MIN || age1 > MAX) || (age2 < MIN || age2 > MAX) || (age3 < MIN || age3 > MAX));

		/* Before Sorting*/
		printf("Input Student Ages:	%d %d %d \n", age1, age2, age3);

		/* Ascending Sort*/
		if(age1 > age2) swap(&age1, &age2);	//Compare 1st and 2nd age inputs, swap if needed
		if(age2 > age3) swap(&age2, &age3);	//Compare 2nd and 3rd age inputs, swap if needed
		if(age1 > age2) swap(&age1, &age2);	//compare 1st and 2nd age inputs, swap if needed
		printf("ASCENDING ORDER:	%d %d %d \n", age1, age2, age3);
	
		/* Descending Sort */
		if(age1 < age2) swap(&age1, &age2);	//Compare 1st and 2nd age inputs, swap if needed
		if(age2 < age3) swap(&age2, &age3);	//Compare 2nd and 3rd age inputs, swap if needed 
		if(age1 < age2) swap(&age1, &age2);	//Compare 1st and 2nd age inputs, swap if needed
		printf("DESCENDING ORDER:	%d %d %d \n", age1, age2, age3);

		printf("%d", &age2);
		printf("Want to sort more student ages? ");
		scanf("%c", &choice);	//Read user input
		getchar();	//Read <ENTER> key
		printf("\n");
	} while(choice !='n' && choice !='N');
}
