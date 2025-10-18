#include <stdio.h>

// Function to display the array elements
void displayArray(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, int position, int element) {
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion!\n");
        return;
    }

    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    arr[position] = element;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion!\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

// Function to perform linear search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return index if element found
        }
    }
    return -1; // Return -1 if element not found
}

// Function to perform binary search (array must be sorted)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid; // Return index if element found
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if element not found
}

int main() {
    int n, choice, position, element, key, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    int size = 0;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search an element using linear search\n");
        printf("4. Search an element using binary search\n");
        printf("5. Display array elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                insertElement(arr, &size, position, element);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 3:
                printf("Enter element to search: ");
                scanf("%d", &key);
                index = linearSearch(arr, size, key);
                if (index != -1) {
                    printf("Element found at index: %d\n", index);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                index = binarySearch(arr, size, key);
                if (index != -1) {
                    printf("Element found at index: %d\n", index);
                } else {
                    printf("Element not found in the array.\n");
                }
                break;
            case 5:
                displayArray(arr, size);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
