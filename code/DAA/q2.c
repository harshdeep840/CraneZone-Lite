#include <stdio.h>
#include <stdlib.h>

void calculatePrefixSum(int arr[], int prefixSum[], int n) {
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i]; 
    }
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    int *prefixSum = (int *)malloc(n * sizeof(int));

    if (arr == NULL || prefixSum == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    calculatePrefixSum(arr, prefixSum, n);

    printf("Prefix Sum Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");
    
    free(arr);
    free(prefixSum);

    return 0;
}