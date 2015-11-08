/*
 * Assignment 3		p3.c		Due July 10, 2015
 * login #: cs5uao
 *
 * This program displays a (cardinal) whole number in Spanish text using if-else and in French text using switch statement.
 * Only a number in the range of 1 through 29 will be converted.
 * The user is allowed to repeat these calculations until entering 'N' or 'n'.
 *
 */

#include <stdio.h>
#define MIN 1
#define MAX 29

int main (void)
{
	int number;		//Input numbers
	int mod;		//Use mod to avoid redundancy of if-else and switch statement 
	int division;		//Use division to avoid redundancy of if-else and swicth statement
	char answer;		//User's input for continuation of the program

	printf("This program displays a number in Spanish and French. \n");
	
	do		//Repeat program if user wishes to
	{
		do		//Repeat if invalid input of numbers are typed
		{
			printf("Enter a number (1-29) to display in Spanish and French text: ");
			scanf("%d", &number);		//Read type int input
			getchar();			//Read <ENTER> key
			if(number > 29 || number < 1)		//To catch invalid input
				printf("ERROR: OUT of the RANGE of 1 through 29 \n");
		} while(number > 29 || number < 1);

		mod = number % 10;		//To display first digit
		division = number / 10;		//To display second digit

		/* Spanish numbers*/
		printf(" In Spanish the number %d is ", number);
		
		/* 1. Exeptions(number: 10-15, 20) */		//To display unique expressions of numbers
		if(number == 10) printf("diez \n");
		else if(number == 11) printf("once \n");
		else if(number == 12) printf("doce \n");
		else if(number == 13) printf("trece \n");
		else if(number == 14) printf("catorce \n");
		else if(number == 15) printf("quince \n");
		else if(number == 20) printf("veinte \n");

		/* 2. Numbers build on combination of other numbers (number: 1-9, 16-19, 21-29) */
		else
		{
			if(division == 1) printf("diec");		//To display second digit
			else if(division == 2) printf("veinti");	
		
			if(mod == 1) printf("uno \n");			//To display first digit
			else if(mod == 2) printf("dos \n");
			else if(mod == 3) printf("tres \n");	
			else if(mod == 4) printf("cuatro \n");
			else if(mod == 5) printf("cinco \n");
			else if(mod == 6) printf("seis \n");
			else if(mod == 7) printf("siete \n");
			else if(mod == 8) printf("ocho \n");
			else if(mod == 9) printf("nueve \n");
		}


		/* French numbers */
		printf(" In French the number %d is ", number);
		
		/* 1. Exeption(number: 10-16, 20, 21) */		//To display unique expressios of numbers
		switch(number)
		{
			case 10: printf("dix \n"); break;
			case 11: printf("onze \n"); break;
			case 12: printf("douze \n"); break;
			case 13: printf("treize \n"); break;
			case 14: printf("quatorze \n"); break;
			case 15: printf("quinze \n"); break;
			case 16: printf("seize \n"); break;
			case 20: printf("vingt \n"); break;
			case 21: printf("vingt et un \n"); break;		

		/* 2. Numbers build on combination of other numbers (number: 1-9, 17-19, 22-29) */
			default:
				switch(division)		//To display second digit
				{
					case 1: printf("dix-"); break;
					case 2: printf("vingt-"); break;
				}
		
		
			switch(mod)		//To display first digit
			{	
				case 1: printf("un \n"); break;	
				case 2: printf("deux \n"); break;
				case 3: printf("trois \n"); break;	
				case 4: printf("quatre \n"); break;
				case 5: printf("cinq \n"); break;
				case 6: printf("six \n"); break;
				case 7: printf("sept \n"); break;
				case 8: printf("huit \n"); break;
				case 9: printf("neuf \n"); break;
			}
		}
		
		printf("Want to convert another number (y/n)? ");
		scanf("%c", answer);		//Read type char input
		getchar();		//Read <ENTER> key
	} while(answer != 'n' || answer != 'N');
}
