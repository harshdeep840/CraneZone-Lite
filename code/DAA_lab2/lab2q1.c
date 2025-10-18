 #include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, char *binary, int index) {
    if (n > 0) {
        decimalToBinary(n / 2, binary, index - 1);
        binary[index] = (n % 2) + '0';  
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *input_file = fopen(argv[2], "r");
    FILE *output_file = fopen(argv[3], "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file(s).\n");
        return 1;
    }

    int decimal;
    char binary[17]; 
    binary[16] = '\0'; 

    for (int i = 0; i < n && fscanf(input_file, "%d", &decimal) == 1; i++) {
        for (int j = 0; j < 16; j++) {
            binary[j] = '0';
        }
        
        
        decimalToBinary(decimal, binary, 15);


        fprintf(output_file, "The binary equivalent of %d is %s\n", decimal, binary);
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(argv[3], "r");
    if (output_file == NULL) {
        printf("Error opening output file for reading.\n");
        return 1;
    }

    char line[100];
    while (fgets(line, sizeof(line), output_file)) {
        printf("%s", line);
    }

    fclose(output_file);
    return 0;
}