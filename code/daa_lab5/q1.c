#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int item_id;
    int item_profit;
    int item_weight;
    float profit_weight_ratio;
} ITEM;

// Function prototypes
void heapify(ITEM arr[], int n, int i);
void heapSort(ITEM arr[], int n);
float fractionalKnapsack(ITEM items[], int n, int capacity);

int main() {
    int n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];
    
    for (i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = (float)items[i].item_profit / items[i].item_weight;
    }

    int capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items by profit/weight ratio using heap sort
    heapSort(items, n);

    // Calculate the maximum profit using fractional knapsack
    float maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum profit not exceeding the given knapsack capacity is: %.2f\n", maxProfit);

    return 0;
}

// Function to maintain the heap property
void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;
    
    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;
    
    if (largest != i) {
        ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        heapify(arr, n, largest);
    }
}

// Function to sort items using heap sort
void heapSort(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        heapify(arr, i, 0);
    }
}

// Function to calculate maximum profit for fractional knapsack
float fractionalKnapsack(ITEM items[], int n, int capacity) {
    float totalProfit = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].item_weight <= remainingCapacity) {
            remainingCapacity -= items[i].item_weight;
            totalProfit += items[i].item_profit;
        } else {
            totalProfit += items[i].profit_weight_ratio * remainingCapacity;
            break;
        }
    }
    
    return totalProfit;
}
