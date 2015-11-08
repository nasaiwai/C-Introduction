/*
 * Assignment 7		p7.c		Due July 29, 2015
 * login #: cs5uao
 *
 * This program will use character strings, functions, and pointer notation 
 * to translate and print an input string into a simplified Pig Latin*
 * and its reversed form.
 * 
 */

#include <stdio.h>	//printf, fgets, getchar
#include <string.h>	//strncpy, memset, strlen
#include <ctype.h>
#define MAX_STR 81

void pig_latin(char *s, char *d);
void reverse(char *p);


/*
 * Driver allows input of entire line and prompts for program repeat
 */
int main(void)
{
	char answer;			//Repeat program
	char inputStr[MAX_STR];		//Holds input string
	char pigLatinStr[MAX_STR];	//Holds pig latin string
	char reversedStr[MAX_STR];	//Holds reversedStr string
	int len;			//length input string

	do
	{
		memset(inputStr, 0, MAX_STR);	//Reset bits to 0 in inputStr
		memset(pigLatinStr, 0, MAX_STR);//Reset bits to 0 in pigLatinStr
		memset(reversedStr, 0, MAX_STR);//Reset bits to 0 in reversedStr

		printf("\n%-20s", "Enter a sentense:");
		fgets(inputStr, MAX_STR, stdin);	//Read input line including newline
		len = strlen(inputStr);			//Length of input string incl. newline
		inputStr[len - 1] = '\0';		//Delimit with null char
		strncpy(reversedStr, inputStr, len - 1);//Stripped ending newline char

		printf("%-20s%s\n", "Original sentense:", inputStr);
		pig_latin(inputStr, pigLatinStr);
		printf("%-20s%s\n", "Pig latin:", pigLatinStr);	//Left adust
		reverse(reversedStr);
		printf("%-20s%s\n", "Reversed:", reversedStr);

		printf("Want to enter another sentence?	");
		answer = getchar();
		getchar();
	} while(answer != 'n' && answer != 'N');	//Exit on n or N
}


/*
 * Function pig_latin(char *s, char *d) will take the source string pointed to by s
 * and its translated pig latin form in the destination string pointed to by d.
 * The first letter is placed at the end, and the ltters "AY" are appended to the end.
 * @pointer *s (sourse string) will take inputStr passed as parameter.
 * @pointer *d (destination string) will get pigLatinStr and store reversed string.
 * The function returns type of void which takes two char* as parameters.
 */
void pig_latin(char *s, char *d)
{
	int length;	//Stores the length of each word
	char temp;	//Stores first letter of each word
	char *q;	//To count the length of each word

	do
	{
		/* Calculate the length of string user typed*/
		q = s;			//move pointer p pointing same direction as s
		while(*q != ' ' && *q != '\0')
			q++;
		length = q - s;		//calculate the length of a word


		/* Shift letters except first letter to the left */
		temp = *s;		//Store the first letter to temp
		int i;
		for(i=0; i <= length-2; i++)
			*(d + i) = *(s + i + 1); 


		/* Change the first letter of word to upper case */
		if(islower(temp))
			temp = toupper(temp);


		/* Change last word into _AY*/
		*(d + (length - 1)) = temp;	//move the first letter to before AY
		*(d + length) = 'A';
		*(d + (length + 1)) = 'Y';
		if(*q != '\0')
			*(d + (length + 2)) = ' ';

		
		/* move pointers pointing to first letter of next word*/
		d = d + length + 3;
		s = s + length + 1;

	} while(*q);
	
	*(d + (length + 2)) = '\0';	//End pig_latin array with '\0' 
}


/*
 * Function reverse(char *p) will reverse the input string pointed p by place.
 * @pointer *p will get inputStr passed as parameter.
 * The function returns type of void which takes char* as parameters.
 */
void reverse(char *p)
{
	int length;		//Stores the length of user input string
	char temp;		//Store the temporary char in order to swap

	/* Calculate the length of string user typed*/
	char *q = p;		//move pointer q pointing same direction as p
	while(*q)
		q++;
	length = q - p;

	/* Swap two element to make the sentence reverse*/
	int i;			//loop counter
	for(i=0; i <= length/2; i++) {
		temp = *(p + i);
		*(p + i) = *(p + (length - i - 1));
		*(p + (length - i - 1)) = temp; 
	}
}
