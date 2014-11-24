/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>

// function prototype
void strsub(char buf[], char s[], int start, int size); 

/* Week 13 strsub.c: Function to extract substring from given string */
void main(void) {
	char source[100] = "Stockport County AFC";
	char dest[100];
	
	strsub(source, dest, 10, 5);
	puts(dest);
}
void strsub(char buf[], char s[], int start, int size) {
	int i;
	
	for (i = 0; i < size && buf[start + i] != '\0'; i++) { 
		// loops as long as iterator is less than size 
		// and while string has not run out of characters
		s[i] = buf[i + start];
	}
	s[i] = '\0';
}
