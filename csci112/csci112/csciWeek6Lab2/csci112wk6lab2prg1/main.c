/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>
#define TWENTY 2000
#define TEN 1000
#define FIVER 500
#define ONE 100
#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNY 1

/* Week 6: Lab 2 - Program 1 (Change) */
int round(double num);

void main(void) {
	int change, twenties, tenners, fivers, ones, quarters, dimes, nickels, pennies;
	double cost, paid;
	
	printf("Enter cost ($): ");
	scanf("%lf", &cost);
	printf("Enter amount tendered ($): ");
	scanf("%lf", &paid);
	printf("\nChange is $%.2lf\n", paid - cost);
	
	int round(double num) {
		return (int) (num + 0.5);
	}
	
	change = round((paid - cost) * 100.0);
	
	twenties = change / TWENTY;
	printf("\n$20 bills: %d", twenties);
	change = change % TWENTY;
	
	tenners = change / TEN;
	printf("\n$10 bills: %d", tenners);
	change = change % TEN;
	
	fivers = change / FIVER;
	printf("\n$5 bills: %d", fivers);
	change = change % FIVER;
	
	ones = change / ONE;
	printf("\n$1 bills: %d", ones);
	change = change % ONE;
	
	quarters = change / QUARTER;
	printf("\nquarters: %d", quarters);
	change = change % QUARTER;
	
	dimes = change / DIME;
	printf("\ndimes: %d", dimes);
	change = change % DIME;
	
	nickels = change / NICKEL;
	printf("\nnickels: %d", nickels);
	change = change % NICKEL;
	
	pennies = change / PENNY;
	printf("\npennies: %d", pennies);
}
