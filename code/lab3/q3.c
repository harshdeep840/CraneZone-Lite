#include <stdio.h>

#define MAX_DEGREE 10

// Function to display a polynomial equation
void displayPolynomial(int poly[], int degree) {
    printf("Polynomial: ");
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            if (i != degree) {
                printf(" + ");
            }
            printf("%dx^%d", poly[i], i);
        }
    }
    printf("\n");
}

// Function to add two polynomial equations
void addPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[]) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++) {
        result[i] = ((i <= degree1) ? poly1[i] : 0) + ((i <= degree2) ? poly2[i] : 0);
    }
}

// Function to multiply two polynomial equations
void multiplyPolynomials(int poly1[], int degree1, int poly2[], int degree2, int result[]) {
    for (int i = 0; i <= degree1 + degree2; i++) {
        result[i] = 0;
    }

    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}

int main() {
    int degree1, degree2;
    int poly1[MAX_DEGREE + 1], poly2[MAX_DEGREE + 1];
    int resultAdd[MAX_DEGREE + 1], resultMul[MAX_DEGREE * 2 + 1];

    printf("Enter the degree of the first polynomial equation: ");
    scanf("%d", &degree1);
    printf("Enter the coefficients of the first polynomial equation (from highest to lowest degree):\n");
    for (int i = degree1; i >= 0; i--) {
        scanf("%d", &poly1[i]);
    }

    printf("\nEnter the degree of the second polynomial equation: ");
    scanf("%d", &degree2);
    printf("Enter the coefficients of the second polynomial equation (from highest to lowest degree):\n");
    for (int i = degree2; i >= 0; i--) {
        scanf("%d", &poly2[i]);
    }

    printf("\nFirst ");
    displayPolynomial(poly1, degree1);
    printf("Second ");
    displayPolynomial(poly2, degree2);

    addPolynomials(poly1, degree1, poly2, degree2, resultAdd);
    printf("\nAddition of the two polynomials: ");
    displayPolynomial(resultAdd, (degree1 > degree2) ? degree1 : degree2);

    multiplyPolynomials(poly1, degree1, poly2, degree2, resultMul);
    printf("\nMultiplication of the two polynomials: ");
    displayPolynomial(resultMul, degree1 + degree2);

    return 0;
}
