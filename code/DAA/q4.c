#include <stdio.h>

void EXCHANGE(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

void ROTATE_RIGHT(int *p1, int p2) {
    int last = *(p1 + p2 - 1);
    for (int i = p2 - 1; i > 0; i--) {
        EXCHANGE(p1 + i, p1 + i - 1);
    }
    *p1 = last;
}

int main() {
    FILE *inputFile;
    int n, p2, i;

    inputFile = fopen("numbers.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    fscanf(inputFile, "%d", &n);

    fscanf(inputFile, "%d", &p2);

    int arr[n];

    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    ROTATE_RIGHT(arr, p2);
    printf("Rotated array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    fclose(inputFile);

    return 0;
}