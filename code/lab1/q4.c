#include <stdio.h>
struct Complex {
    float real;
    float imag;
};

// Function to add two complex numbers
struct Complex addComplex(struct Complex num1, struct Complex num2) {
    struct Complex sum;
    sum.real = num1.real + num2.real;
    sum.imag = num1.imag + num2.imag;
    return sum;
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

    result = addComplex(num1, num2);

    printf("\nSum of the complex numbers: %.2f + %.2fi\n", result.real, result.imag);

    return 0;
}
