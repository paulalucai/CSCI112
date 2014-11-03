/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>
#define SIZE 5

/* wk10ex2.c: Program that stores data into arrays to calculate price total */
void main(void)
{	
	int i;
	double prices[] = {9.92, 6.50, 12.63, 5.95, 10.29};
	double items[SIZE], amounts[SIZE], total;
	
	total = 0;
	for (i = 0; i < SIZE; ++i) {
		printf("Enter number of items: ");
		scanf("%lf", &items[i]);
		amounts[i] = items[i] * prices[i];
		total += amounts[i];
	}
	
	printf("\n	Items	Price	Amount\n");
	printf("	-----	-----	------\n");
	for (i = 0; i < SIZE; ++i) {
		printf("	%5.2lf	%5.2lf	%6.2lf\n", items[i], prices[i], amounts[i]);
	}
	printf("		        ------\n");
	printf("	Total:	     	%.2lf", total);
}
