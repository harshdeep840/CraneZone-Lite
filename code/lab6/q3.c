#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        return NULL;
    }
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if (!stack->array) {
        return NULL;
    }
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // Return a placeholder character
}

// Function to return the top element of the stack without popping it
char peek(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top];
    }
    return '$'; // Return a placeholder character
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of an operator
int precedence(char ch) {
    if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    }
    return -1;
}

// Function to reverse a string
void reverseString(char* str) {
    int i = 0, j = strlen(str) - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to convert infix expression to prefix expression
void infixToPrefix(char* infixExpression) {
    reverseString(infixExpression);

    struct Stack* stack = createStack(strlen(infixExpression));
    if (!stack) {
        return;
    }

    int i, k;
    for (i = 0, k = -1; infixExpression[i]; ++i) {
        if (isalnum(infixExpression[i])) {
            infixExpression[++k] = infixExpression[i];
        } else if (infixExpression[i] == ')') {
            push(stack, infixExpression[i]);
        } else if (infixExpression[i] == '(') {
            while (!isEmpty(stack) && peek(stack) != ')') {
                infixExpression[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != ')') {
                printf("Invalid expression.\n");
                return;
            } else {
                pop(stack);
            }
        } else {
            while (!isEmpty(stack) && precedence(infixExpression[i]) <= precedence(peek(stack))) {
                infixExpression[++k] = pop(stack);
            }
            push(stack, infixExpression[i]);
        }
    }

    while (!isEmpty(stack)) {
        infixExpression[++k] = pop(stack);
    }
    infixExpression[++k] = '\0';
    reverseString(infixExpression);
    printf("Prefix expression: %s\n", infixExpression);
    free(stack->array);
    free(stack);
}

int main() {
    char infixExpression[100];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);
    infixToPrefix(infixExpression);
    return 0;
}
