#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initializeStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push element, stack is full.\n");
        return;
    }
    s->arr[++(s->top)] = data;
    printf("Element %d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1;
    }
    int poppedElement = s->arr[s->top--];
    printf("Element %d popped from the stack.\n", poppedElement);
    return poppedElement;
}

// Function to display the elements in the stack
void displayStack(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initializeStack(&stack);
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("a. Push an element onto the stack\n");
        printf("b. Pop an element from the stack\n");
        printf("c. Check if the stack is empty\n");
        printf("d. Check if the stack is full\n");
        printf("e. Display elements in the stack\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter data to push onto the stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;
            case 'b':
                pop(&stack);
                break;
            case 'c':
                if (isEmpty(&stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 'd':
                if (isFull(&stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 'e':
                displayStack(&stack);
                break;
            case 'f':
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}
