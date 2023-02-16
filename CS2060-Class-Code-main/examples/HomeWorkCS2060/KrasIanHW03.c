#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

/*
* Kras Ian
* Home Work 03
* due 2/16/23
* Desc:
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
void summary(double,double,double,double,double,int, int);

int main(void) {
	const int SENTINEL = -1;

	double hours = getValidHours(MIN_VALID_HOURS,MAX_HOURS_ALLOWED,SENTINEL);
	summary(hours, MAX_CHARGE, ADDITIONAL_HOURS_RATE, MIN_FLAT_RATE_CHARGE, MIN_HOURS_AT_FLAT_RATE, SENTINEL, MAX_HOURS_ALLOWED);

	printf("Your hours: %f", hours);
	
	return 0;

}
/*
* calculates total charge and prints the end summary
*/
void summary(double hours, double max_charge, double ADD_HOURS_RATE, double MIN_CHARGE, double time_at_flat_rate, int SENTINEL, int max_hours) {

	double chargeableHours = 0;
	static int car_num = 0;

	puts("Parking Garage Summary\n");

	if (hours != SENTINEL) {
		car_num++;

		chargeableHours = (ciel(hours) - time_at_flat_rate);

		if (chargeableHours > 3) {
			
			//need to check if hours is greater than max

			if (chargeableHours > max_hours) {
				chargeableHours = max_charge;
			}
			else {
				chargeableHours = chargeableHours * ADD_HOURS_RATE;
			}

		}else {
			//chargeable hours is less than 3 hours
			chargeableHours = MIN_CHARGE;
		}
		
		printf("Car\tHours\tCharge\t\n %i\t%.1f\t%.2f",car_num,hours,chargeableHours);


	}else {
		puts("There were no cars parked today");
	}

	
}

/*
Get valid Hours, returns hours, reads in from user hours, if they are not valid repeat the question, clears buffer to prevent buffer overflow.
*/
double getValidHours(int MIN, int MAX, int SENTINEL) {
	double hoursIn = 0;
	bool FLAG = false;

	do {
		puts("Enter the number of hours the car was parked or enter -1 to quit.");

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
}//end getValidHours

