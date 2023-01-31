/*
* Ian A Kras
* M/W
* CS2060 
* due: 1/30/23
* desc: This project will prompt and read in from the user: length and width. The function "calculate area" will calculate the area
*/
#include <stdio.h>

int calculateArea(int,int,int);

int main( void )
{
	int length = 0, width = 0,area = 0;

	puts("Enter value for Length: ");
	scanf("%d", &length);

	puts("Enter values for Width: ");
	scanf("%d", &width);

	// send value to function and calculate area
	area = calculateArea(length, width, area);

	printf("Length: %d width: %d and area is %d", length,width,area);

	double lenWidthDivided = (double)length / (double)width;

	printf("\nlength and width divided and stored in a double: %.1f\n\n",lenWidthDivided);

	return 0;
} // end function main 

int calculateArea(int length, int width, int area) {

	area = length * width; 

	return area;

}


