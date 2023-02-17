#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
* Kras Ian
* Home Work 03
* due 2/16/23
* Desc: read in number of hours a car was parked. If not valid ask again, gives chargeable amount.
*/

//constants
#define MIN_VALID_HOURS 0
#define MIN_HOURS_AT_FLAT_RATE 3.0
#define MIN_FLAT_RATE_CHARGE 3.0
#define ADDITIONAL_HOURS_RATE .75
#define MAX_HOURS_ALLOWED 24
#define MAX_CHARGE 12.0

//functions
double getValidHours(int,int,int);
void summary(double);

int main(void) {

	const int SENTINEL = -1;
	bool FLAG = false;
	double hours = 0;

	do {
		//if returned hours == -1 set flag to true output summary and return 0
		hours = getValidHours(MIN_VALID_HOURS, MAX_HOURS_ALLOWED, SENTINEL);

		if (hours == SENTINEL) {
			FLAG = true;
		}

		summary(hours, SENTINEL);

	} while (!FLAG);

	return 0;

}//end main

/*
* calculates total charge and prints the end summary
* if less than charge = flat rate
* if greater charge = max charge
* else charge = hours - min hours. multiplied by add charge by hour then add the flat rate.
*/
void summary(double hours, int SENTINEL) {


	int overheadHours = 0;
	double chargeableHours = 0;
	static int car_num = 0;

	puts("Parking Garage Summary\n---------------------------------");

	car_num++;

	if (hours = SENTINEL) {
		puts("No cars today!");
	}
	else {
		if (hours <= MIN_HOURS_AT_FLAT_RATE) {

			chargeableHours = MIN_FLAT_RATE_CHARGE;
		}
		else if (hours > MAX_HOURS_ALLOWED) {
			chargeableHours = MAX_CHARGE;
		}
		else {

			chargeableHours = (hours - MIN_HOURS_AT_FLAT_RATE * ADDITIONAL_HOURS_RATE) + MIN_FLAT_RATE_CHARGE;
		}

		printf("Car\tHours\tCharge\t\n %i\t%.1f\t%.2f",car_num,hours,chargeableHours);
	}
	
	

	
}

/*
Get valid Hours, returns hours, reads in from user hours, 
if they are not valid repeat the question, clears buffer to prevent buffer overflow.
*/
double getValidHours(int MIN, int MAX, int SENTINEL) {

	double hoursIn = 0;
	bool FLAG = false;


	do {
		puts("\nEnter the number of hours the car was parked or enter -1 to quit.");

		int scanfReturn = scanf("%lf", &hoursIn);

		while ((getchar()) != '\n');

		if (scanfReturn == 1) {

			if (hoursIn == SENTINEL || hoursIn <= MAX || hoursIn > MIN) {
				FLAG = true;
			}
			else {
				puts("Invalid Range");
			}
			
		}
		else {
			puts("You did not enter a number");
		}

	} while (!FLAG);

	return hoursIn;
}//end getValidHours

