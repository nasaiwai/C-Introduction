/*
 * Assignment 2		p2.c:		Due July8, 2015
 * login #: cs5uao
 * 
 * This program converts the number of kilometers to miles using the while, for, and do loop.
 * Use the conversion factor of "1 killometers is equal to .62 miles".
 */

#include <stdio.h>
#define KM_TO_MILE 0.62

int main(void)
{
	double count;		//Loop counter
	double km;		//Input killometers
	double mile;		//mile after conversion
	char answer;		//User's anwer if they want to continue conversion or not(y/n)
	
	do		//This do loop is for repeating conversion until users put n for the answer
	{

		do		//This do loop is for repeating asking input until users put non-zero numbers
		{
			printf("Enter a positive non-zero number of kilometers of the rate: ");
			scanf("%lf", &km);		//Read type double input
			getchar();			//Read <ENTER> key
		} while(km <=0);


		/* While Loop*/ 
		printf(" KILOMETERS       MILES (while loop)\n");
		printf(" ==========       ===== \n");
	
		count = 1;
		while (count < km)
		{
			mile = count * KM_TO_MILE;		//Calculate from kilometers to miles except the last row
			printf("%8.3lf %14.3lf \n", count, mile);
			++count;
		}	
		mile = km * KM_TO_MILE;				//Calculate from kilometers to miles for the last row
		printf("%8.3lf %14.3lf \n", km, mile);
		printf("\n");			//insert a blank line between while and for loop
	

		/* For Loop*/
		printf(" KILOMETERS       MILES (for loop)\n");
		printf(" ==========       ===== \n");

		for(count = 1; count < km; count++)
		{		
			mile = count * KM_TO_MILE;		//Calculate from kilometers to miles except the last row
			printf("%8.3lf %14.3lf \n", count, mile);
		}	
		mile = km * KM_TO_MILE;				//Calculate from kilimeters to miles for the last row
		printf("%8.3lf %14.3lf \n", km, mile);
		printf("\n");			//insert a blank line between for and do loop

	
		/* Do Loop*/
		printf(" KILOMETERS       MILES (do loop)\n");
		printf(" ==========       ===== \n");

		count = 1;
		do
		{	
			mile = count * KM_TO_MILE;		//Calculate from kilometers to miles expect for the last row
			printf("%8.3lf %14.3lf \n", count, mile);
			++count;
		} while(count < km);
		mile = km * KM_TO_MILE;			//Calculate from kilometers to miles for the last row
		printf("%8.3lf %14.3lf \n", km, mile);
		printf(" ======================\n");

		printf("Want to convert more kilometers (y/n)? \n");
		answer = getchar();		//Read y/n to see if users want to continue or not
		getchar();			//Read <ENTER> key
	} while(answer == 'y'); 
}	
