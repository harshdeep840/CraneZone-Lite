#include <stdio.h>

// Function to find the number of nonzero elements in the matrix
int countNonZero(int matrix[][10], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

// Function to display the upper triangular matrix
void displayUpperTriangular(int matrix[][10], int n) {
    printf("Upper Triangular Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) {
                printf("%d ", matrix[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

// Function to display elements just above and below the main diagonal
void displayAboveBelowDiagonal(int matrix[][10], int n) {
    printf("\nElements just above and below the main diagonal:\n");
    printf("Above diagonal:\n");
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("Below diagonal:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int matrix[10][10];

    printf("Enter the size of the square matrix (max 10): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int nonzeroCount = countNonZero(matrix, n);
    printf("\nNumber of nonzero elements in the matrix: %d\n", nonzeroCount);

    displayUpperTriangular(matrix, n);

    displayAboveBelowDiagonal(matrix, n);

    return 0;
}
