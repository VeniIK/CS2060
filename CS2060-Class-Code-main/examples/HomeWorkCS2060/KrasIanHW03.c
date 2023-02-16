#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
* Kras Ian
* Home Work 03
* due 2/16/23
* Desc:
*/

//constants
#define MIN_VALID_HOURS 0
#define MIN_HOURS_AT_FLAT_RATE 3
#define MIN_FLAT_RATE_CHARGE 3.0
#define ADDITIONAL_HOURS_RATE .75
#define MAX_HOURS_ALLOWED 24
#define MAX_CHARGE 12.0

//functions
double getValidHours(int,int,int);

int main(void) {
	int SENTINEL = -1;

	double hours = getValidHours(MIN_VALID_HOURS,MAX_HOURS_ALLOWED,SENTINEL);

	printf("Your hours: %f", hours);
	
	return 0;

}

double getValidHours(int MIN, int MAX, int SENTINEL) {
	double hoursIn = 0;
	bool FLAG = false;

	do {
		puts("Enter hours");
		int scanfReturn = scanf("%f", &hoursIn);

		while ((getchar()) != '\n'); 

		if (scanfReturn == 1) {
			if (hoursIn > MIN && hoursIn <= MAX || hoursIn == SENTINEL) {
				FLAG = true;
			}
			else {
				puts("Please input valid hours");
			}
		}

	} while (!FLAG);

	return hoursIn;
}
