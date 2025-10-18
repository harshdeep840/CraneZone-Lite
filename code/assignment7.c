#include <stdio.h>
#include <stdlib.h>

// A binary tree node has data, pointer to left child, and a pointer to right child
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Given a binary tree, print its nodes in preorder
void printPreorder(struct Node* node) {
    if (node == NULL)
     return;
    // First print the data of node
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

// Given a binary tree, print its nodes in postorder
void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

// Given a binary tree, print its nodes in inorder
void printInorder(struct Node* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Search for an element in the binary search tree
struct Node* search(struct Node* root, int key) {
    if (root == NULL) 
    return NULL;
    if (root->data == key)
     return root;
    if (root->data > key) return search(root->left, key);
    else return search(root->right, key);
}

int main() {
    // Build the tree
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    // Menu-driven operations
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Preorder Traversal\n");
        printf("2. Postorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Search an Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Preorder traversal of binary tree is: ");
                printPreorder(root);
                printf("\n");
                break;
            case 2:
                printf("Postorder traversal of binary tree is: ");
                printPostorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal of binary tree is: ");
                printInorder(root);
                printf("\n");
                break;
            case 4:
                int key;
                printf("Enter the element to search: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result == NULL) printf("Element not found\n");
                else printf("Element found\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}