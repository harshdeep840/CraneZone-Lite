#include <stdio.h>

#define MAX_SIZE 100

void displaySparseMatrix(int sparseMatrix[][3], int totalElements) {
    printf("Sparse Matrix in 3-tuple format:\n");
    printf("Row\tColumn\tValue\n");
    printf("-------------------\n");
    for (int i = 0; i <= totalElements; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

void transposeSparseMatrix(int sparseMatrix[][3], int totalElements) {
    int transpose[MAX_SIZE][3];

    // Initializing the transpose matrix
    transpose[0][0] = sparseMatrix[0][1]; // Number of columns becomes number of rows
    transpose[0][1] = sparseMatrix[0][0]; // Number of rows becomes number of columns
    transpose[0][2] = totalElements; // Total number of elements remains the same

    int position = 1;

    // Finding transpose by switching row and column indices
    for (int col = 0; col < sparseMatrix[0][1]; col++) {
        for (int i = 1; i <= totalElements; i++) {
            if (sparseMatrix[i][1] == col) {
                transpose[position][0] = sparseMatrix[i][1]; // Column index becomes row index
                transpose[position][1] = sparseMatrix[i][0]; // Row index becomes column index
                transpose[position][2] = sparseMatrix[i][2]; // Value remains the same
                position++;
            }
        }
    }

    displaySparseMatrix(transpose, totalElements);
}

int main() {
    int sparseMatrix[MAX_SIZE][3];
    int totalElements;

    printf("Enter the number of rows, columns, and non-zero elements in the sparse matrix: ");
    scanf("%d", &sparseMatrix[0][0]); // Rows
    scanf("%d", &sparseMatrix[0][1]); // Columns
    scanf("%d", &totalElements); // Total non-zero elements

    printf("Enter the elements of the sparse matrix in 3-tuple format (row column value):\n");
    for (int i = 1; i <= totalElements; i++) {
        scanf("%d %d %d", &sparseMatrix[i][0], &sparseMatrix[i][1], &sparseMatrix[i][2]);
    }

    displaySparseMatrix(sparseMatrix, totalElements);

    printf("\nTranspose of the given sparse matrix:\n");
    transposeSparseMatrix(sparseMatrix, totalElements);

    return 0;
}
