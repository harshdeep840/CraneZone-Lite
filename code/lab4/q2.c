#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
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

// Function to insert a node at the end of the list
void insertNodeEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to search for an element in the list
int searchElement(struct Node* head, int key) {
    int position = 1;
    while (head != NULL) {
        if (head->data == key) {
            return position;
        }
        position++;
        head = head->next;
    }
    return -1; // Element not found
}

// Function to swap data between two nodes
void swapData(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to sort the list in ascending order
void sortList(struct Node* head) {
    struct Node* temp1;
    struct Node* temp2 = NULL;

    if (head == NULL) {
        return;
    }

    while (temp2 != head->next) {
        temp1 = head;
        while (temp1->next != temp2) {
            if (temp1->data > temp1->next->data) {
                swapData(temp1, temp1->next);
            }
            temp1 = temp1->next;
        }
        temp2 = temp1;
    }
}

// Function to reverse the list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the list
void printList(struct Node* head) {
    printf("Linked List elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, key, position;

    printf("Enter the number of nodes for the linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertNodeEnd(&head, data);
    }

    printf("Original ");
    printList(head);

    printf("Enter an element to search in the list: ");
    scanf("%d", &key);
    position = searchElement(head, key);
    if (position != -1) {
        printf("Element %d found at position %d.\n", key, position);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    sortList(head);
    printf("Sorted ");
    printList(head);

    reverseList(&head);
    printf("Reversed ");
    printList(head);

    return 0;
}
