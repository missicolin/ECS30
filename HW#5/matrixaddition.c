#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int** getMatrix(int n, int m);
int** allocateMatrix(int n, int m);
int** addMatrices(int** A, int** B, int n, int m);
void printMatrix(int** A, int n, int m);
void deallocateMatrix(int** A, int n);


// This program reads in two n by m matrices A and B and
// prints their sum C = A + B
//
// This function is complete, you do not need to modify it
// for your homework
int main() {
    int n = 0, m = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &n, &m);
    assert(n > 0 && m > 0);
    printf("Enter matrix A:\n");
    int** A = getMatrix(n, m);
    printf("Enter matrix B:\n");
    int** B = getMatrix(n, m);
    int** C = addMatrices(A, B, n, m);
    printf("A + B = \n");
    printMatrix(C, n, m);
    deallocateMatrix(A, n);
    deallocateMatrix(B, n);
    deallocateMatrix(C, n);
}

// Creates a new n by m matrix whose elements are read from stdin
//
// This function is complete, you do not need to modify it
// for your homework
int** getMatrix(int n, int m) {
    int** M = allocateMatrix(n, m);
    for (int i = 0; i < n; i++) {
        printf("Input row %d elements, separated by spaces: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &M[i][j]);
        }
    }
    return M;
}

// Allocates space for an n by m matrix of ints
// and returns the result
int** allocateMatrix(int n, int m) {
    int** A;
    int** B;
    A = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
	  A[i] = malloc(m * sizeof(int)); 
    }    
    return A;
    B = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
	    B[i] = malloc(m * sizeof(int));
    }
    return B;
    // Homework TODO: Implement this function
}

// Adds two matrices together and returns the result
int** addMatrices(int** A, int** B, int n, int m) {
	int** C;
	C = malloc(n*sizeof(int*));
     for(int i = 0; i < n; i++) {
	     C[i] = malloc(m * sizeof(int));
	     for (int j = 0; j < m; j++) {
		     C[i][j] = A[i][j] + B[i][j];
	     }
     }
     return C;
	// Homework TODO: Implement this function
}

// Prints out the entries of the matrix
void printMatrix(int** A, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", A[i][j]);}
			printf("\n");
	}
	return; 
       	// Homework TODO: Implement this function
}

// Deallocates space used by the matrix
void deallocateMatrix(int** A, int n) {
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
}
