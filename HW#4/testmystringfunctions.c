
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "mystringfunctions.h"

// Homework TODO: Include mystringfunctions.h here
bool getAndRunTest();
void deepCopyStrTestA();
void deepCopyStrTestB();
void deepCopyStrTestC();
void isLowerOrDigitStrTestA();
void isLowerOrDigitStrTestB();
void isLowerOrDigitStrTestC();
void concatStrsTestA();
void concatStrsTestB();
void concatStrsTestC();


// Homework TODO: Add function prototypes here

// Asks user to pick a unit test to run.
// In practice, we write unit tests using a unit testing framework
// and all unit tests are run when the code is compiled.
// For grading purposes, we ask the user to pick the test.
// DO NOT modify this function for your homework.
int main() {
  // User menu
  printf("Which unit test would you like to run?\n");
  printf("1) deepCopyStr\n");
  printf("\ta) n = 2, src = \"test string\"\n");
  printf("\tb) n = 0 returns \"\\0\"\n");
  printf("\tc) negative n returns NULL\n");
  printf("2) isLowerOrDigitStr\n");
  printf("\ta) n = 4, src = \"testString\"\n");
  printf("\tb) n = 5, src = \"testString\"\n");
  printf("\tc) n = 0\n");
  printf("3) concatStrs\n");
  printf("\ta) n = 5, str1 = \"test\", str2 = \"string\"\n");
  printf("\tb) n = 5, str1 = \"\", str2 = \"test string\" returns \"test \"\n");
  printf("\tc) n = 5, str1 = \"test\", str2 = \"\" returns NULL\n");
  while (!getAndRunTest()) {}
}

// Prompt user once for the test to run. 1a is deepCopyStrTestA,
// 1b is deepCopyStrTestB, 2c is isLowerOrDigitStrTestC, and so on.
// If the user input is valid, run the test and return true.
// If the user input is invalid, print the error according to the homework
// prompt and return false.
bool getAndRunTest() {
	int num, n;
	char cons;
	char* src, str1, str2;

	scanf("%d%c", &num, &cons);

	if (num != 1 || num != 2 || num != 3 || cons != 'a' || cons != 'b' || cons != 'c') {
		while (num != 1 &&  num != 2 && num != 3){ 
		printf("Enter 1, 2, or 3 for the function to test.\n");
		return false;
		}
		while (cons != 'a' && cons != 'b' && cons != 'c') {
		printf("Enter a, b or c for the test case.\n");
		return false;  
		}
	}
	if (num == 1 || num == 2 || num == 3 || cons == 'a' || cons == 'b' || cons == 'c'){
		if (num == 1 && cons == 'a'){
			deepCopyStrTestA(src, n);
		}
		if (num == 1 && cons == 'b'){
			deepCopyStrTestB(src, n);
		}
		if (num == 1 && cons == 'c'){
			deepCopyStrTestC(src, n);
		}
		if (num == 2 && cons == 'a'){
			isLowerOrDigitStrTestA(src, n);
		}
		if (num == 2 && cons == 'b'){
			isLowerOrDigitStrTestB(src, n);
		}
		if (num == 2 && cons == 'c'){
			isLowerOrDigitStrTestC(src, n);
		}
		if (num == 3 && cons == 'a'){
			concatStrsTestA(str1, str2, n);
		}
		if (num == 3 && cons == 'b'){
			concatStrsTestB(str1, str2, n);
		}
		if (num == 3 && cons == 'c'){
			concatStrsTestC(str1, str2, n);
		}
	return true;	
	}
}	
// Homework TODO: complete the code for this function.}
// Test n = 2 and src = "test string" returns "te"
void deepCopyStrTestA() {
      char* result = deepCopyStr("test string", 2);
      // if (result) checks to see something is returned (even if the string is empty).
      //   We will see later in the course this is checking if the result is a NULL pointer
      assert(result && result[0] == 't' && result[1] == 'e' && result[2] == '\0');
      printf("Test successful.\n");
}

// Test n = 0 the returns "\0"
void deepCopyStrTestB() {
	char* result = deepCopyStr("", 0);
	assert(result && result[0] == '\0');
	printf("Test successful.\n");	
     	// Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// Test negative n returns NULL"
void deepCopyStrTestC() {
	char* result = deepCopyStr("", -1);
	if (result == NULL){
	printf("Test successful.\n");
	} 
}
	// Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.


// Test n = 4, src = "testString" returns true
void isLowerOrDigitStrTestA() {
	 bool var = isLowerOrDigitStr("testString", 4);
	 assert(var == true);
	 printf("Test successful. \n");	       
    // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// Test n = 5, src = "testString" returns false
void isLowerOrDigitStrTestB() {
	bool var = isLowerOrDigitStr("testString", 5);
	assert(var == false);
	printf("Test successful.\n");
    // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// Test n = 0, src = "" returns true
void isLowerOrDigitStrTestC() {
	bool var = isLowerOrDigitStr("", 0);
	assert(var == true);
	printf("Test successful.\n");
     // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// Test n = 10, str1 = "test", str2 = "string" returns "teststring"
void concatStrsTestA() {
	char* result = concatStrs("test","string", 10);
	assert(result && result[0] == 't' && result[1] == 'e' && result[2] == 's' && result[3] == 't' && result[4] == 's' && result[5] == 't' && result [6] == 'r' && result[7] == 'i' && result[8] == 'n' && result[9] == 'g' && result [10] == '\0');
	printf("Test successful.\n");
    // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// n = 5, str1 = "", str2 = "test string" returns "test "
void concatStrsTestB() {
	char* result = concatStrs("","test string",5);
	assert(result && result[0] == 't' && result[1] == 'e' && result[2] == 's' && result[3] == 't' && result[4] == ' ' && result[5] == '\0');
	printf("Test successful.\n");
    // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}

// n = 5, str1 = "test", str2 = "" returns NULL
void concatStrsTestC() {
	char* result = concatStrs("test","",5);
	if(result == NULL){
	printf("Test successful.\n");
	}
    // Homework TODO: write code for this test case according to the
    // specifications in the comment above the function.
}
// Flush stdin buffer
void flushStdin() {
	char c;
	while( (c = getchar()) != EOF && c!= '\n' && c!= '\r') {};
}

    // Homework TODO: see 1/30/17 lecture notes to understand what this
    // function will do and how it should be written.


