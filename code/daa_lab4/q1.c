#include <stdio.h>
int binarySearch(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1; 
    }

    int mid = low + (high - low) / 2; 

    if (arr[mid] == target) {
        return mid; 
    }

    else if (arr[mid] > target) {
        return binarySearch(arr, target, low, mid - 1);
    }
    else {
        return binarySearch(arr, target, mid + 1, high);
    }
}

int main() {
   int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int targetValue = 7;
    int arraySize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    
    int result = binarySearch(sortedArray, targetValue, 0, arraySize - 1);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}