#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node for the circular linked list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertNodeEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// Function to display the circular linked list elements
void displayCircularList(struct Node* head) {
    struct Node* temp = head;

    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    } else {
        printf("Circular linked list is empty.\n");
    }
}

int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of nodes for the circular linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNodeEnd(&head, data);
    }

    printf("Circular Linked List elements: ");
    displayCircularList(head);

    return 0;
}