#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    FILE *output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    int a, b;
    while (fscanf(input_file, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(output_file, "The GCD of %d and %d is %d\n", a, b, result);
    }

    fclose(input_file);
    fclose(output_file);

    printf("GCD calculations stored in %s.\n", argv[2]);

    return 0;
} `