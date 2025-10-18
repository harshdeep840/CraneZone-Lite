#include <stdio.h>

int findMajorityElement(int arr[], int size) {
    int candidate = arr[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = arr[i];
                count = 1;
            }
        }
    }

    // Verifying if the candidate is the majority element
    count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }

    if (count > size / 2) {
        return candidate;
    } else {
        return -1; 
    }
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    int majority = findMajorityElement(arr, size);

    if (majority != -1) {
        printf("The majority element is: %d\n", majority);
    } else {
        printf("No majority element \n");
    }

    return 0;
}
