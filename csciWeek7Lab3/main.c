/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>
#include <stdlib.h>

/* your #defines go here */
#define GROSSH 20
#define GROSSP 15
#define GROSSC 600
#define ITEMS 30
#define OVERTIMETHRESH 40
#define SALESTHRESH1 5000
#define SALESTHRESH2 3000
#define SALESTHRESH3 2000
#define LOWSALES 1000
#define SALESPEN 50.0
#define TAXRATE 0.07

/* function prototypes */
void initialize(double *totalNet);
void printHeader(void);
void hourly(int id, double hours, double *totalNet);
void commission(int id, double sales, double *totalNet);
void piecework(int id, double sales, double *totalNet);
void calcTaxNet(double grossPay, double penalty, double *tax, double *netPay);
void printSummary(double totalNet);

/* Payroll.c:  Produce weekly payroll.  Lab 3 */
void main(void)
{
    char   type;     // employee type
    int    id;       // employee ID
    double num,      // employee productivity info
           totalNet; // total of all net pays, for summary info
    FILE *fp;

    initialize(&totalNet); // sets totalNet to 0.0

    fp = fopen("Payroll.dat", "r"); // open the data file
    if (fp == NULL) {
        printf("Payroll.dat file not found.\n");
        exit(1);
    }
    printHeader(); // prints column headers
    while (!feof(fp)) {                // loop until every employee processed
        fscanf(fp, "%d %c %lf\n", &id, &type, &num); // reads info for next employee

        if (type == 'H')
            hourly(id, num, &totalNet); // prints line for hourly
        else if (type == 'P')
            piecework(id, num, &totalNet); // prints line for piecework
        else
            commission(id, num, &totalNet); // prints line for commission
    }
    fclose(fp);
    printSummary(totalNet); // prints summary info at foot of table
}

void initialize(double *totalNet)
{
	*totalNet = 0.0;
}

void printHeader(void)
{
	printf("ID    Gross    Penalty    Tax    Net    Comment\n");
	printf("--    -----    -------    ---    ---    -------\n");
}

void hourly(int id, double hours, double *totalNet)
{
	double grossPay, tax, penalty, netPay;
	grossPay = hours * GROSSH; // pay rate is $20/hour for any number of hours worked
	penalty = 0.0; // notice no penalty for hourly employees
	calcTaxNet(grossPay, penalty, &tax, &netPay);
	// output "Overtime" in report if more than 40 hours were worked
	if (hours > OVERTIMETHRESH) {
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  %-7s\n", id, grossPay, penalty, tax, netPay, "Overtime");
	}
	else {
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  \n", id, grossPay, penalty, tax, netPay);
	}
	*totalNet += netPay; // add netPay to totalNet for printSummary
}

void commission(int id, double sales, double *totalNet)
{
	double grossPay, tax, penalty, netPay;
	grossPay = GROSSC; // pay is $600 base plus a commission on sales according to the following schedule:
	if (sales >= SALESTHRESH1) {
		grossPay += (sales * 0.05); // additional 5% commission on sales
	}
	else if (sales >= SALESTHRESH2) {
		grossPay += (sales * 0.03); // additional 3% commission on sales
	}
	else if (sales >= SALESTHRESH3) {
		grossPay += (sales * 0.02); // additional 2% commission on sales
	}
	else {
		grossPay = GROSSC;
	}
	// penalty of $50 is incurred if sales are less than $1,000
	if (sales < LOWSALES) {
		penalty = SALESPEN;
	}
	else {
		penalty = 0.0;
	}
	calcTaxNet(grossPay, penalty, &tax, &netPay);
	// output "Low sales" if penalty applies
	if (sales < LOWSALES) { 
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  %-7s\n", id, grossPay, penalty, tax, netPay, "Low sales");
	}
	else {
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  \n", id, grossPay, penalty, tax, netPay);
	}
	*totalNet += netPay; // add netPay to totalNet for printSummary
}

void piecework(int id, double sales, double *totalNet)
{
	double grossPay, tax, penalty, netPay;
	grossPay = sales * GROSSP;
	// if number of items is less than 30, a penalty of $5 times number of items less than 30 is incurred
	if (sales < ITEMS) { 
		penalty = (ITEMS - sales) * 5;
	}
	else {
		penalty = 0.0;
	}
	calcTaxNet(grossPay, penalty, &tax, &netPay);
	// output "Low production" if the penalty applies
	if (sales < ITEMS) { 
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  %-7s\n", id, grossPay, penalty, tax, netPay, "Low production");
	}
	else {
		printf("%d  %5.2lf  %9.2lf  %3.2lf  %2.2lf  \n", id, grossPay, penalty, tax, netPay);
	}
	*totalNet += netPay; // add netPay to totalNet for printSummary
}

void calcTaxNet(double grossPay, double penalty, double *tax, double *netPay)
{
	*tax = (grossPay - penalty) * TAXRATE; // tax withholding rate is 7%, not including penalty amount
	*netPay = grossPay - (penalty + *tax); // seems self-explanatory
}

void printSummary(double totalNet)
{
	printf("\nTotal net: %.2lf", totalNet); // output accumulated netPay from all employees
}

