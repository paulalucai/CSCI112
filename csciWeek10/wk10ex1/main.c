/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>
#define MAXLENGTH 5

/* wk10ex1.c: Program that reads data into array to output maximum and index of maximum*/
void main(void) {
	int i, max, index, a[MAXLENGTH];
	
	printf("Enter number: ");
	scanf("%d", &a[0]);
	
	max = a[0];
	index = 0;
	
	for (i = 1; i < MAXLENGTH; i++) {
		printf("Enter number: ");
		scanf("%d", &a[i]);
		if (a[i] > max)
			max = a[i];
			index = i;
	}
	for (i = 0; i < MAXLENGTH; i++) {
		printf("a[%d] is: %d\n", i, a[i]);
	}
		
	printf("The maximum value is: %d\n", max);
	printf("This is stored at index number: %d\n", index);
}
