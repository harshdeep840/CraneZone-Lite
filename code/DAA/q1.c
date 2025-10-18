#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void findSecondSmallestAndLargest(int arr[], int n, int *secondSmallest, int *secondLargest) {
    int smallest = INT_MAX, largest = INT_MIN;

    *secondSmallest = INT_MAX;
    *secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {

        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *secondSmallest && arr[i] != smallest) {
            *secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] != largest) {
            *secondLargest = arr[i];
        }
    }

    if (*secondSmallest == INT_MAX) {
        *secondSmallest = -1; 
    }
    if (*secondLargest == INT_MIN) {
        *secondLargest = -1; 
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    int secondSmallest, secondLargest;
    findSecondSmallestAndLargest(arr, n, &secondSmallest, &secondLargest);

    if (secondSmallest != -1) {
        printf("Second Smallest: %d\n", secondSmallest);
    } else {
        printf("Second Smallest not found\n");
    }

    if (secondLargest != -1) {
        printf("Second Largest: %d\n", secondLargest);
    } else {
        printf("Second Largest not found\n");
    }

    free(arr);
    return 0;
}