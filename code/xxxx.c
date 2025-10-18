#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

void inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

struct Node* search(struct Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (node->data < data) {
        return search(node->right, data);
    }
    return search(node->left, data);
}

int main() {
    struct Node* root = NULL;
    int n, data, choice;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    do {
        printf("\n1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Preorder Traversal: ");
                preorder(root);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                break;
            case 4:
                printf("Enter the element to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    printf("Element found\n");
                } else {
                    printf("Element not found\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}