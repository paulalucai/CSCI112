/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>

/* Week 6: Lab 2 - Program 2 (Retirement) */
void main(void) {
	int year;
    double balance, target, deposit, rate, interest;

    printf("Enter starting balance ($): ");
    scanf("%lf", &balance);
    printf("Enter amount deposited every year ($): ");
    scanf("%lf", &deposit);
    printf("Enter estimated annual interest rate (\%%): ");
    scanf("%lf", &rate);
    printf("Enter target balance ($): ");
    scanf("%lf", &target);

    year = 0;
    interest = 0;
    rate = rate / 100.0;

    printf("\nYear    Deposit    Interest    Balance");
    printf("\n----    -------    --------    -------");
    printf("\n%d    %.2lf    %.2lf    %.2lf", year, balance, interest, balance);
    do {
		year += 1;
		interest = (balance + deposit) * rate;
		balance = balance + deposit + interest;
        printf("\n%d    %.2lf    %.2lf    %.2lf", year, deposit, interest, balance);
    } while (balance <= target);

    printf("\nIn year %d, balance %.2lf reaches target %.2lf", year, balance, target);
}
