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

void addSparseMatrices(int mat1[][3], int totalElements1, int mat2[][3], int totalElements2) {
    int result[MAX_SIZE][3];
    int resultIndex = 1;

    int i = 1, j = 1;
    result[0][0] = mat1[0][0]; // Rows of result matrix
    result[0][1] = mat1[0][1]; // Columns of result matrix

    while (i <= totalElements1 && j <= totalElements2) {
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1])) {
            result[resultIndex][0] = mat1[i][0];
            result[resultIndex][1] = mat1[i][1];
            result[resultIndex][2] = mat1[i][2];
            i++;
        } else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1])) {
            result[resultIndex][0] = mat2[j][0];
            result[resultIndex][1] = mat2[j][1];
            result[resultIndex][2] = mat2[j][2];
            j++;
        } else {
            result[resultIndex][0] = mat1[i][0];
            result[resultIndex][1] = mat1[i][1];
            result[resultIndex][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
        }
        resultIndex++;
    }

    while (i <= totalElements1) {
        result[resultIndex][0] = mat1[i][0];
        result[resultIndex][1] = mat1[i][1];
        result[resultIndex][2] = mat1[i][2];
        i++;
        resultIndex++;
    }

    while (j <= totalElements2) {
        result[resultIndex][0] = mat2[j][0];
        result[resultIndex][1] = mat2[j][1];
        result[resultIndex][2] = mat2[j][2];
        j++;
        resultIndex++;
    }

    result[0][2] = resultIndex - 1; // Total non-zero elements in result matrix
    displaySparseMatrix(result, resultIndex - 1);
}

int main() {
    int mat1[MAX_SIZE][3], mat2[MAX_SIZE][3];
    int totalElements1, totalElements2;

    printf("Enter the number of rows, columns, and non-zero elements in the first sparse matrix: ");
    scanf("%d %d %d", &mat1[0][0], &mat1[0][1], &totalElements1);

    printf("Enter elements of the first sparse matrix in 3-tuple format (row column value):\n");
    for (int i = 1; i <= totalElements1; i++) {
        scanf("%d %d %d", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }

    printf("Enter the number of rows, columns, and non-zero elements in the second sparse matrix: ");
    scanf("%d %d %d", &mat2[0][0], &mat2[0][1], &totalElements2);

    printf("Enter elements of the second sparse matrix in 3-tuple format (row column value):\n");
    for (int i = 1; i <= totalElements2; i++) {
        scanf("%d %d %d", &mat2[i][0], &mat2[i][1], &mat2[i][2]);
    }

    printf("\nFirst Sparse Matrix:\n");
    displaySparseMatrix(mat1, totalElements1);

    printf("\nSecond Sparse Matrix:\n");
    displaySparseMatrix(mat2, totalElements2);

    printf("\nAddition of the two sparse matrices:\n");
    addSparseMatrices(mat1, totalElements1, mat2, totalElements2);

    return 0;
}
