#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct Tuple{
    Node* head;
}Tuple;