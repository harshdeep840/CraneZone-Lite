#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct HuffmanNode {
    SYMBOL symbol;
    struct HuffmanNode *left, *right;
} HuffmanNode;

typedef struct {
    HuffmanNode *node;
    int priority;
} PriorityQueueNode;

void swap(PriorityQueueNode *a, PriorityQueueNode *b) {
    PriorityQueueNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(PriorityQueueNode pq[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && pq[left].priority < pq[smallest].priority)
        smallest = left;
    
    if (right < n && pq[right].priority < pq[smallest].priority)
        smallest = right;
    
    if (smallest != i) {
        swap(&pq[i], &pq[smallest]);
        heapify(pq, n, smallest);
    }
}

void buildMinHeap(PriorityQueueNode pq[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(pq, n, i);
}

HuffmanNode* extractMin(PriorityQueueNode pq[], int *size) {
    if (*size <= 0) return NULL;
    
    HuffmanNode *minNode = pq[0].node;
    pq[0] = pq[--(*size)];
    heapify(pq, *size, 0);
    
    return minNode;
}

void insertPriorityQueue(PriorityQueueNode pq[], int *size, HuffmanNode *node, int priority) {
    int i = (*size)++;
    pq[i].node = node;
    pq[i].priority = priority;
    
    while (i && pq[i].priority < pq[(i - 1) / 2].priority) {
        swap(&pq[i], &pq[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HuffmanNode* createNode(SYMBOL symbol, HuffmanNode *left, HuffmanNode *right) {
    HuffmanNode *node = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    node->symbol = symbol;
    node->left = left;
    node->right = right;
    return node;
}

void buildHuffmanTree(SYMBOL symbols[], int n) {
    PriorityQueueNode pq[n];
    int size = 0;
    
    for (int i = 0; i < n; i++) {
        HuffmanNode *node = createNode(symbols[i], NULL, NULL);
        insertPriorityQueue(pq, &size, node, symbols[i].frequency);
    }
    
    buildMinHeap(pq, size);
    
    while (size > 1) {
        HuffmanNode *left = extractMin(pq, &size);
        HuffmanNode *right = extractMin(pq, &size);
        SYMBOL combinedSymbol = {'\0', left->symbol.frequency + right->symbol.frequency};
        HuffmanNode *parent = createNode(combinedSymbol, left, right);
        insertPriorityQueue(pq, &size, parent, combinedSymbol.frequency);
    }
    
    HuffmanNode *root = extractMin(pq, &size);
    
    printf("In-order traversal of the tree (Huffman): ");
    inOrderTraversal(root);
    printf("\n");
}

void inOrderTraversal(HuffmanNode *root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    if (root->symbol.alphabet != '\0') {
        printf("%c ", root->symbol.alphabet);
    }
    inOrderTraversal(root->right);
}

int main() {
    int n;
    
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);
    
    SYMBOL symbols[n];
    
    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }
    
    printf("Enter its frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }
    
    buildHuffmanTree(symbols, n);
    
    return 0;
}
