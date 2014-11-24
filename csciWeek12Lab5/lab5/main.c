/* Paula Caixeta; CSCI 112; online class */
#include <stdio.h>
#include <ctype.h> // to include isalpha() and tolower()
#define LEN 100 // maximum length of array input
#define ABC 26 // amount of letters from A to Z starting from 0


/* lab5.c: Compares user input to determine if they are anagrams */
void initialize(char s1[], char s2[], int count[]); // clears string and count arrays for new user input
void getString(char s[]); // reads user input using gets()
void setLetters(char s1[], int count[]); // increments count with input from first string
void checkLetters(char s2[], int count[]); // decrements count with input from second string
void isZero(int count[]); // inspects count value to determine whether strings were anagrams

int main() {

    char string1[LEN];
	char string2[LEN];
	int count1[ABC] = {0}; // initilaize the 26 elements in count to 0
	
	while (1 == 1) { // while (true), aka infinite loop
	
		initialize(string1, string2, count1);

		getString(string1); // read the first string
		setLetters(string1, count1); // count how many times a letter has been seen
		getString(string2); // read the second string
		checkLetters(string2, count1); // decrement each letter's count from the value generated by first string
		
		isZero(count1); // determine whether the second string letter count decremented completely
	}
}
void initialize(char s1[], char s2[], int count[]) {
	int i; // counter variable
	
	for (i = 0; s1[i] != '\0'; i++) { // for every element in string1
		s1[i] = '\0'; // replace it with a null character
		count[i] = 0; // set the value to 0 to clear
	}
	for (i = 0; s2[i] != '\0'; i++) { // for every element in string2
		s2[i] = '\0'; // replace it with a null character
	}
}
void setLetters(char s1[], int count[]) {
	int i = 0; // counter variable
 
    for (i = 0; s1[i] != '\0'; i++) { // for each character in string1
      if (isalpha(s1[i])) { // if value is a letter
		count[tolower(s1[i]) - 'a']++; // convert it to lowercase; subtract 'a' from it
        // increment the count of that index in count array
		}
	}
	return count; // not sure if I need this, but keeping it just in case...
}
void checkLetters(char s2[], int count[]) {
	int i; // counter variable
	
	for (i = 0; s2[i] != '\0'; i++) { // for each character in string2
      if (isalpha(s2[i])) { // if value is a letter
		count[tolower(s2[i]) - 'a']--; // convert it to lowercase; subtract 'a' from it
        // decrement the count of that index in count array
		}
	}
	return count; // not sure if I need this, but keeping it just in case...
}
void getString(char s[]) {
	
	printf("Enter the string: "); // prompts user for string input
    gets(s); // reads input into the string, terminates with null character
	// I read that gets() is not widely used anymore because of "serious security issues"...
	// so people recommend using fgets(), getline(), or scanf() instead. 
	// What are your thoughts on this? :)
}
void isZero(int count[]) {
	int i; // counter variable
	int x = 0; // variable to track if there's a FALSE value
	
	for (i = 0; i < ABC; i++) { // for every element in the count array
		if (count[i] != 0) // if there are any values that were not decremented by the second string
			x = 1; // return FALSE
	}
	if (x == 1) { // if count array is not completely "empty"
		printf("Not Anagram\n\n"); // FALSE: the words are not anagrams
	}
	else { // otherwise...
		printf("Anagram\n\n"); // TRUE: the words match, yay!
	}
}