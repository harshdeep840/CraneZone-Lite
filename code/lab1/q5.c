#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

// Function to multiply two complex numbers
void multiplyComplex(struct Complex *num1, struct Complex *num2, struct Complex *result) {
    result->real = (num1->real * num2->real) - (num1->imag * num2->imag);
    result->imag = (num1->real * num2->imag) + (num1->imag * num2->real);
}

int main() {
    struct Complex num1, num2, result;

    printf("Enter real and imaginary parts of first complex number:\n");
    printf("Real part: ");
    scanf("%f", &num1.real);
    printf("Imaginary part: ");
    scanf("%f", &num1.imag);

    printf("\nEnter real and imaginary parts of second complex number:\n");
    printf("Real part: ");
    scanf("%f", &num2.real);
    printf("Imaginary part: ");
    scanf("%f", &num2.imag);

    multiplyComplex(&num1, &num2, &result);

    printf("\nProduct of the complex numbers: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
