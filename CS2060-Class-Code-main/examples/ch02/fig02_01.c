/*
* Ian A Kras
* M/W
* CS2060 
* due: 1/30/23
* desc: This project will prompt and read in from the user: length and width. The function "calculate area" will calculate the area
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int calculateArea(int,int,int);
int main( void )
{
	int area = 0;
	int length, width;

	puts("Enter value for Length: ");
	scanf("%d", &length);

	puts("Enter values for Width: ");
	scanf("%d", &width);

	// send value to function and calculate area
	area = calculateArea(length, width, area);

	printf("The Area is: %d", area );
	return 0;
} // end function main 

int calculateArea(int length, int width, int area) {

	area = length * width; 

	return area;

}



