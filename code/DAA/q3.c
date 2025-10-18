#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 
void findDuplicatesAndMostRepeating(int arr[], int n) {
    int count[MAX_SIZE] = {0}; 
    int totalDuplicates = 0;
    int mostRepeatingElement = arr[0];
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        if (count[i] > 1) {
            totalDuplicates += count[i] - 1; 
        }
        if (count[i] > maxCount) {
            maxCount = count[i];
            mostRepeatingElement = i; 
        }
    }

    printf("Total number of duplicate values: %d\n", totalDuplicates);
    printf("The most repeating element in the array: %d (repeats %d times)\n", mostRepeatingElement, maxCount);
}

int main() {
    int n;
    int *arr;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        free(arr);
        return 1; 
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file); 

    findDuplicatesAndMostRepeating(arr, n);

    free(arr);
    return 0;
}