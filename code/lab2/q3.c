#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_SIZE 100

void displaySparseMatrix(int sparseMatrix[][3], int totalElements) {
    printf("Sparse Matrix in 3-tuple format:\n");
    printf("Row\tColumn\tValue\n");
    printf("-------------------\n");
    for (int i = 0; i <= totalElements; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i][0], sparseMatrix[i][1], sparseMatrix[i][2]);
    }
}

void convertToSparseMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    int sparseMatrix[MAX_SIZE][3];
    int totalElements = 0;

    // Creating 3-tuple format for sparse matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix[totalElements][0] = i;
                sparseMatrix[totalElements][1] = j;
                sparseMatrix[totalElements][2] = matrix[i][j];
                totalElements++;
            }
        }
    }

    sparseMatrix[0][2] = totalElements; // Store total number of non-zero elements
    displaySparseMatrix(sparseMatrix, totalElements);
}

int main() {
    int matrix[MAX_ROWS][MAX_COLS];
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix (max 10 each): ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix entered:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    convertToSparseMatrix(matrix, rows, cols);

    return 0;
}
