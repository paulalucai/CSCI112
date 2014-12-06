/* Paula Caixeta; CSCI 112; online course */
#include <stdio.h>
#include <stdlib.h>

// define constants
#define ARR 100
#define FIRST 7
#define MIDINIT 1
#define LAST 9
#define STREET 16
#define CITY 11
#define STATE 2
#define ZIP 5
#define AGE 3
#define GPA 4
#define START 0
#define FIRSTID 8
#define INITID 10
#define STREETID 20
#define CITYID 37
#define STATEID 49
#define ZIPID 52
#define AGEID 57
#define GPAID 64

// defined structs
typedef struct {
	char street[STREET + 1];
    char city[CITY + 1];
    char state[STATE + 1];
    char zip[ZIP + 1];	
} Address;

typedef struct {
	char firstname[FIRST + 1];
    char initial[MIDINIT + 1];
    char lastname[LAST + 1];
    Address ofstudent;
    int age;
    double gpa;
} Student;

// function prototype
void strsub(char buf[], char s[], int start, int size); 
void processStudent(int *id, Student students[]);
void sortStudentGpa(Student students[], int id); 
void maxGpa(Student *students, int id);
void averageGpa(Student students[], int id);

/* lab6student.c: creates an array of student structures and outputs reports */
int main(void)
{
	Student students[ARR]; // creates an array of student structures
	int id = 0; // counter for student
	
	processStudent(&id, students); 
	maxGpa(students, id); // find student with highest GPA
	averageGpa(students, id); // calculate average GPA and find students above and below average
	sortStudentGpa(students, id); // sort students by lowest to highest GPA
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
void processStudent(int *id, Student students[]) {
	FILE *data;
	char line[ARR];
	int i;
	*id = 0; // counter for student
	
	data = fopen("Students.dat", "r"); // data is the pointer to the file that will be read
	if (data == NULL) {
		printf("Students.dat file not found!\n");
		exit(1);
	}
	
	// continue to process file of students until we see an EOF
	while (!feof(data)) {
        // organize student info into separate arrays
        fgets(line, ARR, data);
        strsub(line, students[*id].firstname, START, FIRST); 
        strsub(line, students[*id].initial, FIRSTID, MIDINIT);
        strsub(line, students[*id].lastname, INITID, LAST);
        strsub(line, students[*id].ofstudent.street, STREETID, STREET);
        strsub(line, students[*id].ofstudent.city, CITYID, CITY);
        strsub(line, students[*id].ofstudent.state, STATEID, STATE);
        strsub(line, students[*id].ofstudent.zip, ZIPID, ZIP);
        students[*id].age = atoi(&line[AGEID]);
        students[*id].gpa = atoi(&line[GPAID]);
        (*id)++;
    }
	// prints data as stored in original file
	printf("Original array: \n");
	for (i = 0; i < *id; ++i) {
		printf("%s %s %s %s %s %s %s %d %.2f\n", students[i].firstname, 
			students[i].initial, students[i].lastname, students[i].ofstudent.street, 
			students[i].ofstudent.city, students[i].ofstudent.state, students[i].ofstudent.zip, 
			students[i].age, students[i].gpa);
	}
	fclose(data);
}
//sorts struct student array containing num (gpa) elements into ascending order
void sortStudentGpa(Student students[], int id) {
	int i, j; // indexes into unsorted and sorted partitions
	Student temp; // temporarily holds an element from the array
	
	for (i = 1; i < id; ++i) {
		temp = students[i];
		j = i - 1;
		while (j >= 0 && temp.gpa < students[j].gpa) {
			students[j + 1] = students[j];
			j = j - 1;
		}
		students[j + 1] = temp;
	}
	// prints data as sorted by lowest to highest GPA
	printf("\nSorted by GPA (low to high): \n");
	for (i = 0; i < id; ++i) {
		printf("%s %s %s %s %s %s %s %d %.2f\n", students[i].firstname, 
			students[i].initial, students[i].lastname, students[i].ofstudent.street, 
			students[i].ofstudent.city, students[i].ofstudent.state, students[i].ofstudent.zip, 
			students[i].age, students[i].gpa);
	}
} 
void maxGpa(Student students[], int id) {
	int best; // will store index of highest GPA
	int i;
    float max = 0;

    for (i = 0; i < id; i++) {
            if (students[i].gpa > max) {
                    max = students[i].gpa; // sets max to highest GPA value until next is found
                    best = i; // index of highest GPA
            }
    }
	// print full name of student with highest GPA
	printf("\nStudent with best GPA is: \n%s %s\n", students[best].firstname, students[best].lastname);
}
void averageGpa(Student students[], int id) {
	int i;
	float sum = 0;
	float average;
	
	for(i = 0; i < id; ++i) {
		sum += students[i].gpa; // loop through student GPA values and add them up
    }
    average = sum / id; // calculate average by dividing sum by number of students (id)
    printf("\nAverage GPA is: %.2f\n", average);
	
	printf("\nStudents with GPA above average: \n");
	for(i = 0; i < id; ++i) { // loop through students
		if (students[i].gpa > average) { // finds students whose GPA is higher than average
			printf("%s %s\n", students[i].firstname, students[i].lastname);
		}
	}
	int youngest;
	int min = students[0].age; // consider min age to be the first student
	
	printf("\nYoungest student with GPA below average: \n");
	for(i = 0; i < id; ++i) { // loop through students
		// if student's age is less than or equal to the current age value of min
		// and if student's GPA is below average
		if (students[i].age <= min && students[i].gpa < average) { 
				min = students[i].age; // min age is the current student
				youngest = i; // youngest is the index of the current student
				printf("%s %s\n", students[youngest].firstname, students[youngest].lastname); // print full name
		}
	}
}
