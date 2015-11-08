/*
 * Assignment 4		p4.c		Due July 15, 2015
 *
 * This program gives users 5 choices for the command.
 * Depending on users' choice, the program prints out a triangle or pyramid.
 * Users can also change length and character for triangle and pyramid through command.
 *
 */

#include <stdio.h>	/* printf, scanf */
#include<ctype.h>	/* isgraph */
#define MIN 0

void menu(void);
void print_triangle(int, char);
int read_iterations(void);
int iterations(void);
char read_character(void);
void print_pyramid(int, char);


/*
 * Read users input. Driver for functions.
 */
int main (void)
{
	int choice;		//Store user input
	char ch = '*';		//character modified by read_character() function
	int it = 3;		//Integer modified by read_iterations() function
	menu();
	do
	{
		printf("\nEnter a number (1-5) to choose an option from the menu above: ");
		scanf("%d", &choice);	//Read user input
		getchar();	//Read <ENTER> key

		switch (choice)
		{
			case 1:
				print_triangle(it, ch);
				break;
			case 2:
				print_pyramid(it, ch);
				break;
			case 3:
				it = read_iterations();
				break;
			case 4:
				ch = read_character();
				break;
			case 5:
				printf("Exiting...\n");
				break;
		}
	} while (choice != 5);
}



/*
 * Function menu() displays the menu of options to the user.
 */
void menu(void)
{
	printf("Menu: \n");
	printf("1) Print Triangle \n");
	printf("2) Print Pyramid \n");
	printf("3) Change Line Length \n");
	printf("4) Change Symbolic Character \n");
	printf("5) Exit \n");
}



/*
 * Function read_triangle() displays the char entered as a parameter to the terminal repeatedly
 * with imcreasing line length as to create a sideways triangle.
 * @parameter int n: determines the maximum line length
 * @parameter char c: is displayed to the terminal
 * The function returns a type of void which takes an int and a char as parameters
 */
void print_triangle(int n, char c)
{
	for(int i=0; i < n; i++)	//Repeat until last row has length n
	{
		for(int x = 0; x < i; x++)	//Create each row of a triangle
			printf("%c", c);
		printf("%c\n", c);	//Create the right side edge of a triangle
	}
}



/*
 * Function read_iterations() takes user input until a valid positive integer
 * is entered (0 is neither positive or negative).
 * @variable iterations: stores user input for number
 * The function returns iterations type int which takes no parameters.
 */
int read_iterations(void)
{
	int iterations;		//Stores user input
	do	//Repeat until user puts valid input(positive number)
	{
		printf("Enter a positive number of iterations: ");
		scanf("%d", &iterations);	//Read user input
		getchar();	//Read <ENTER> key
		if(iterations <= MIN) printf("ERROR: Enter positive number! \n\n");
	} while(iterations <= MIN);
	return iterations;
}


/*
 * Function read_character() takes user input until a valid alphanumeric or
 * symbolic character is entered (ASCII decimal 33-126 inclusive).
 * @variable character: stores user input 
 * @variable result stores result of isgraph()
 * The function returns character type char which takes no argument.
 */
char read_character(void)
{
	char character;		//Stores user input
	int result;		//Stores result of isgraph()
	do	//Repeat until user puts valid input
	{
		printf("Enter a alphanumeric or symbolic character: ");
		scanf("%s", &character);	//Read user's input
		getchar();		//Read <ENTER> key
		result = isgraph(character);	//Take ONLY a symbol, number, or letter
		if(!result)
			printf("ERROR: Enter an alphanumeric or Sysmbolic character! \n\n");
	} while(!result);
	return character;
}



/*
 * Function print_pyramid() displays the char entered as a parameter to the terminal repeatedly
 * in such a way as to create a sideways pyramid.
 * @parameter int n: determines BOTH the maximum line length as well as the number of peaks
 * @parameter char c: is displays to the terminal
 * The function returns type of void which takes an int and a char as parameters.
 */
void print_pyramid(int n, char c)
{
	for(int i=0; i < n; i++)	//Repeat making n number of pyramid
	{	
		for(int i=0; i < n; i++)	//Create first half of pyramid(, which is triangle)
		{
			for(int x = 0; x < i; x++)
				printf("%c", c);
			printf("%c\n", c);
		}

		for(int i = n-1; i > 0; i--)	//Create second half of pyramid(, which is trangle)
		{
			for(int x = i-1; x > 0; x--)
				printf("%c", c);
			if(i != 1) printf("%c\n", c);
		}
	}
	printf("%c\n", c);
}


