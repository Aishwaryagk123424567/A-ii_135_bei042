#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to generate random numbers and store them in a file
void generateRandomNumbersToFile(const char* filename, int count, int maxNum) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num = rand() % maxNum;
        fprintf(file, "%d ", num);
    }

    fclose(file);
}

// Function to read numbers from a file and build a binary search tree
struct Node* buildBSTFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file.\n");
        return NULL;
    }

    struct Node* root = NULL;
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        root = insertNode(root, num);
    }

    fclose(file);
    return root;
}

// Main function
int main() {
    const char* filename = "r.txt";
    int count = 10;  // Number of random numbers to generate
    int maxNum = 100;  // Maximum value for random numbers

    // Generate random numbers and store them in a file
    generateRandomNumbersToFile(filename, count, maxNum);

    // Build binary search tree from the numbers in the file
    struct Node* root = buildBSTFromFile(filename);

    // Perform in-order traversal of the binary search tree
    printf("In-order traversal of the binary search tree:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

