#include <stdio.h>

void segregateEvenOdd(int arr[], int size) {
    int left = 0, right = size - 1;
     
    while (left < right) {
        while (arr[left] % 2 == 0 && left < right)
            left++;
        
        while (arr[right] % 2 != 0 && left < right)
            right--;
        
        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {12, 34, 45, 9, 8, 90, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    segregateEvenOdd(arr, size);
    
    printf("Array after segregation: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
