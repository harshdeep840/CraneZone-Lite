#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comparisons = 0; // Global variable to count comparisons

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        comparisons++; // Increment comparison count
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }

    // Free the allocated memory for temporary arrays
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void readFile(const char* filename, int** arr, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d", size);
    *arr = (int*)malloc(*size * sizeof(int));
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &(*arr)[i]);
    }
    fclose(file);
}

void writeFile(const char* filename, int arr[], int size, double executionTime) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fprintf(file, "Number of comparisons: %d\n", comparisons);
    fprintf(file, "Execution time: %.6f seconds\n", executionTime);
    fclose(file);
}

void displaySortedArray(int arr[], int size) {
    printf("Sorted elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void menu() {
    printf("Menu:\n");
    printf("1. Sort from file 1\n");
    printf("2. Sort from file 2\n");
    printf("3. Sort from file 3\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, size, *arr;
    const char* inputFiles[] = {"input1.txt", "input2.txt", "input3.txt"};
    const char* outputFile = "output.txt";

    while (1) {
        menu();
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        if (choice < 1 || choice > 3) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        readFile(inputFiles[choice - 1], &arr, &size);
        comparisons = 0; // Reset comparisons for each sort

        // Start time measurement
        clock_t start = clock();
        mergeSort(arr, 0, size - 1);
        clock_t end = clock();
        
        // Calculate execution time
        double executionTime = (double)(end - start) / CLOCKS_PER_SEC;

        writeFile(outputFile, arr, size, executionTime);
        displaySortedArray(arr, size);
        
        // Display comparisons and execution time
        printf("Number of comparisons: %d\n", comparisons);
        printf("Execution time: %.6f seconds\n", executionTime);

        free(arr);
    }

    return 0;
}