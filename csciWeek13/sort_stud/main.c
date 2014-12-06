/* Peter Cline, Aug 1
	Sorting arrays of structures
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	double gpa;
	char firstName[20];
	char lastName[20];
} Student;

Student initStudent();
Student getNewStudent_FILE(FILE *);
void printTableHeaders();
void printOneStudent(Student);
int displayMenu();

// sorting functions
void swap(Student [], int, int);
int findMin_id(Student [], int);
void sortStudents_id(Student [], int);
int findMin_gpa(Student [], int);
void sortStudents_gpa(Student [], int);
int findMin_name(Student [], int);
void sortStudents_name(Student [], int);

int main() {
	Student students[20];
   char input_filename[50] = "Students.dat";
	int numStudents = 0; // counter for student
	int i;
	int menuOption;

	// can ask user for filename input if desired
	FILE *STUDENT_IN = fopen(input_filename, "r");

	// check for file open problems
	if (STUDENT_IN == NULL) {
   	printf("Error opening file %s\n", input_filename);
		exit(-1);
	}
	
	// continue to get new students until we see an EOF
	while (!feof(STUDENT_IN)) {
		students[numStudents] = getNewStudent_FILE(STUDENT_IN);
		numStudents++;
	}

	// if the EOF was found in the function (because of
	// an empty line) then we need to decrement numStudents
	if (students[numStudents].id = -1) {
   	numStudents--;
	}

	menuOption = displayMenu();
	while (menuOption != -1) {
   	switch (menuOption) {
      	case 1:
				printTableHeaders();
   			for (i = 0; i < numStudents; i++) {
   				printOneStudent(students[i]);
				}
				break;
		  case 2:
		  		sortStudents_gpa(students, numStudents);
				break;
		  case 3:
		  		sortStudents_id(students, numStudents);
				break;
		  case 4:
				sortStudents_name(students, numStudents);
				break;
		  default:
		  		printf("Invalid option, try again.\n");
		}
		printf("\n");

   	menuOption = displayMenu();
	}

	return 0;
}

/* sets default values in a new Student */
Student initStudent() {
	Student newStudent;

	newStudent.id = -1;
	newStudent.gpa = 0;
	strcpy(newStudent.firstName, "");
	strcpy(newStudent.lastName, "");

	return newStudent;
}

/* gets a single student from the input file IN, 
	returns it as a new Student structure */
Student getNewStudent_FILE(FILE * IN) {
	Student newStudent = initStudent();
	char line[200];
	char *curToken = NULL;

	curToken = fgets(line, 200, IN);
	if (curToken == NULL) {
   	// occurs if first thing fgets reads is EOF--no data
		// to read.
		// this is why we init the student first, so 
		// it isn't full of junk if we have to return now
		return newStudent;
	}

	// tokenize current line, fill newStudent
	curToken = strtok(line, ", ");
	newStudent.id = atoi(curToken);
	curToken = strtok(NULL, ", ");
	newStudent.gpa = atof(curToken);
	curToken = strtok(NULL, ", ");
	strcpy(newStudent.firstName, curToken);
	curToken = strtok(NULL, ", ");
	strcpy(newStudent.lastName, curToken);
	
	// strcpy includes the \n, so get rid of it if it's there
	if (newStudent.lastName[strlen(newStudent.lastName)-1] == '\n') {
   	newStudent.lastName[strlen(newStudent.lastName)-1] = '\0';
	}

	return newStudent;
}

/* prints table headers to the screen */
void printTableHeaders() {
	printf("\n");
	printf("%15s, %-15s %7s %8s\n",
				"Last Name",
				"First Name",
				"Student ID",
				"GPA");
	printf("\n");
}

/* prints one student to the screen */
void printOneStudent(Student studentToPrint) {
	printf("%15s, %-15s %d %10.2lf\n",
				studentToPrint.lastName,
				studentToPrint.firstName,
				studentToPrint.id,
				studentToPrint.gpa);
}

// print the menu
// return an integer translation of the user's input
int displayMenu() {
	char userInput[BUFSIZ];

	printf("User Options:\n");
	printf("  (1) Print All Students\n");
	printf("  (2) Sort Students by GPA\n");
	printf("  (3) Sort Students by ID\n");
	printf("  (4) Sort Students by Name\n");
	printf("\nPlease enter an option, or -1 to quit: ");

	fgets(userInput, BUFSIZ, stdin);
	return atoi(userInput);
}

// take an array and two indices, swap the elements in the two indices
void swap(Student students[], int i, int j) {
	Student temp;

	temp = students[i];
	students[i] = students[j];
	students[j] = temp;
}

// searches array, returns index of minimum id #
int findMin_id(Student students[], int numStudents) {
	int i;
	int minIndex = 0;

	for (i = 1; i < numStudents; i++) {
   	if (students[i].id < students[minIndex].id) 
			minIndex = i;
	}

	return minIndex;
}

// recursive selection sort on ID
void sortStudents_id(Student students[], int numStudents) {
	int minIndex;

	if (numStudents == 1)
		return;

	minIndex = findMin_id(students, numStudents);
	swap(students, 0, minIndex);
	sortStudents_id(&students[1], numStudents - 1);
}

// searches array, returns index of minimum gpa
int findMin_gpa(Student students[], int numStudents) {
	int i;
	int minIndex = 0;

	for (i = 1; i < numStudents; i++) {
   	if (students[i].gpa < students[minIndex].gpa) 
			minIndex = i;
	}

	return minIndex;
}

// recursive selection sort on GPA
void sortStudents_gpa(Student students[], int numStudents) {
	int minIndex;

	if (numStudents == 1)
		return;

	minIndex = findMin_gpa(students, numStudents);
	swap(students, 0, minIndex);
	sortStudents_gpa(&students[1], numStudents - 1);
}  

// searches array, returns index of alphabetically first last name
int findMin_name(Student students[], int numStudents) {
	int i;
	int minIndex = 0;

	for (i = 1; i < numStudents; i++) {
   	if (strcmp(students[i].lastName, students[minIndex].lastName) < 0) 
			minIndex = i;
	}

	return minIndex;
}

// recursive selection sort on last name
void sortStudents_name(Student students[], int numStudents) {
	int minIndex;

	if (numStudents == 1)
		return;

	minIndex = findMin_name(students, numStudents);
	swap(students, 0, minIndex);
	sortStudents_name(&students[1], numStudents - 1);
}  
