#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printOptimalParenthesization(int S[][10], int i, int j) {
    if (i == j) {
        printf("A%d", i + 1); 
    } else {
        printf("(");
        printOptimalParenthesization(S, i, S[i][j]);
        printOptimalParenthesization(S, S[i][j] + 1, j);
        printf(")");
    }
}

void matrixChainMultiplication(int p[], int n) {
    int M[10][10] = {0}; 
    int S[10][10] = {0}; 

    // Length of chain
    for (int l = 2; l <= n; l++) { 
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            M[i][j] = INT_MAX; 
            
            for (int k = i; k < j; k++) {
                int q = M[i][k] + M[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    S[i][j] = k; 
                }
            }
        }
    }

    printf("Minimum number of scalar multiplications: %d\n", M[0][n - 1]);
    printf("Optimal parenthesization: ");
    printOptimalParenthesization(S, 0, n - 1);
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Number of matrices must be at least 1.\n");
        return 1;
    }

    int *p = (int *)malloc((n + 1) * sizeof(int)); 
    printf("Enter the dimensions of the matrices (row and column):\n");
    for (int i = 0; i < n; i++) {
        int rows, cols;
        printf("Matrix A%d (rows and columns): ", i + 1);
        scanf("%d %d", &rows, &cols);

        if (i == 0) {
            p[i] = rows; 
        } else if (p[i] != rows) {
            printf("Incompatible dimensions: The number of rows of matrix A%d must match the number of columns of matrix A%d.\n", i, i - 1);
            free(p);
            return 1;
        }
        p[i + 1] = cols; 
    }

    matrixChainMultiplication(p, n);
    free(p);
    return 0;
}
