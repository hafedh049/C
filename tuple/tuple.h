#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int data;
    Node* next;
}Node;

typedef struct Tuple{
    Node* head;
}Tuple;


const Tuple* createTuple(int,...);
int getFromTuple(const Tuple, int);