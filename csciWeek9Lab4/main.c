/* Paula Caixeta; CSCI 112; online section */
#include <stdio.h>
#include <stdlib.h>

/* #defines */
#define BEGIN 1900
#define DAYS_IN_WEEK 7

/* function prototypes */
void getMonthYear(int *month, int *year);
int toJulian(int month, int year);
int daysInMonth(int month, int year);
int leapYear(int year);
long yearsToDays(int year);
void printCalendar(int startDay, int numDays);
void printHeader();

/* Calendar.c:  Prints monthly calendar.  Lab 4 / Week 9 */
void main(void)
{
    int month, year;
    int startDay;   // what day is first day of month.  1/1/1900 was Monday, so...
                    // day 1 is Mon, day 2 is Tue, ... , day 0 is Sun
    
    getMonthYear(&month, &year);
    startDay = (1 + toJulian(month, year) + yearsToDays(year)) % DAYS_IN_WEEK;
    printCalendar(startDay, daysInMonth(month, year));
}
void getMonthYear(int *month, int *year) {
	printf("Enter month: ");
	scanf("%d", month);
	printf("Enter year: ");
	scanf("%d", year);
	printf("\n"); 
}
int toJulian(int month, int year) {
    int count;
    int julian = 0;
    for(count = 1; count < month; ++count) {
        julian += daysInMonth(count, year);    
    }
    return julian;
}
int daysInMonth(int month, int year) {
	int numDays;
	switch (month) {
    case 1: numDays = 31;
    	break;
    case 2: numDays = 28 + leapYear(year);
    	break;
    case 3: numDays = 31;
    	break;
    case 4: numDays = 30;
    	break;
    case 5: numDays = 31;
    	break;
    case 6: numDays = 30;
    	break;
    case 7: numDays = 31;
    	break;
    case 8: numDays = 31;
    	break;
    case 9: numDays = 30;
    	break;
    case 10: numDays = 31;
    	break;
    case 11: numDays = 30;
    	break;
    case 12: numDays = 31;
    	break;
	default:

            printf("Bad month param in daysInMonth()");

            exit(1);

            break;
    }
	return numDays;
}
int leapYear(int year) {
   int ret = 0;
   if ( year % 4 != 0 )
   {
      ret = 0;
   }
   else 
   {
      if ( year % 100 != 0 )
      {
         ret = 1;
      }
      else 
      {
         ret = (year % 400 == 0);
      }
   }

   return ret;
}
long yearsToDays(int year) {
    int count;
    long days = 0;
    for (count = BEGIN; count < year; ++count) {
        days += 365;
        days += leapYear(count);
    }
    return days;
}
void printCalendar(int startDay, int numDays) {
	int dayid;
	printHeader();
	// Shifts position for the first date... sort of
		for ( dayid = 0; dayid < startDay; dayid++ ) {
            printf("    ");
        }
			
		// Supposedly prints all the dates for one month
		for ( dayid = 1; dayid <= numDays; dayid++ ) {
			printf("%3d", dayid );
				
			// If the day is not before Saturday, start next line on Sun
			if ( ( dayid + startDay ) % DAYS_IN_WEEK > 0 ) {
				printf(" ");
			}
			else {
				printf("\n" );
			}
		}
}
void printHeader() {
	printf(" Su   M  Tu   W  Th   F  Sa\n");
}