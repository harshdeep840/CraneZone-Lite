#include <stdio.h>
#include <stdlib.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // Not prime
        }
    }
    return 1; // Prime
}

// Function to calculate sum of prime elements
void sumOfPrimes(int *arr, int size, int *sum) {
    *sum = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(arr[i])) {
            *sum += arr[i];
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }
    
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum;
    sumOfPrimes(arr, n, &sum);
    printf("Sum of prime elements: %d\n", sum);
    
    free(arr); // Deallocate memory
    
    return 0;
}
