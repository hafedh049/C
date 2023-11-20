#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rope structure
struct RopeNode {
    char* data;
    int length;
    struct RopeNode* left;
    struct RopeNode* right;
};

typedef struct RopeNode Rope;

// Function to create a new rope node
Rope* createRope(char* str) {
    Rope* node = (Rope*)malloc(sizeof(Rope));
    node->data = str;
    node->length = strlen(str);
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to concatenate two ropes
Rope* concatRopes(Rope* left, Rope* right) {
    Rope* newNode = (Rope*)malloc(sizeof(Rope));
    newNode->length = left->length + right->length;
    newNode->data = (char*)malloc(newNode->length + 1);

    strcpy(newNode->data, left->data);
    strcat(newNode->data, right->data);

    newNode->left = left;
    newNode->right = right;

    return newNode;
}

// Function to print the contents of a rope
void printRope(Rope* rope) {
    if (rope) {
        printRope(rope->left);
        printf("%s", rope->data);
        printRope(rope->right);
    }
}

// Function to release memory used by the rope
void freeRope(Rope* rope) {
    if (rope) {
        freeRope(rope->left);
        freeRope(rope->right);
        free(rope->data);
        free(rope);
    }
}

int main() {
    Rope* rope1 = createRope("Hello, ");
    Rope* rope2 = createRope("world!");
    Rope* combinedRope = concatRopes(rope1, rope2);

    printRope(combinedRope);
    printf("\n");

    freeRope(combinedRope);

    return 0;
}
