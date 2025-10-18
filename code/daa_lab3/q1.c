#include <stdio.h>

#define SIZE 10 
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

       
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE];
    int n = SIZE;

    printf("Enter %d integers between 10,000 and 50,000:\n", SIZE);
    for (int i = 0; i < n; i++) {
        int input;
        scanf("%d", &input);
        
        if (input < 10000 || input > 50000) {
            printf("Invalid input! Please enter a number between 10,000 and 50,000.\n");
            i--; 
        } else {
            arr[i] = input;
        }
    }

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}