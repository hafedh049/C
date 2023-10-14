#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Tuple{
    Node* head;
}Tuple;


const Tuple *createTuple(int, ...);

int getFromTuple(const Tuple, int);

void showTuple(const Tuple);

int size(const Tuple);

bool tuplesEquality(const Tuple, const Tuple);

Tuple *copy(const Tuple);

int *tupleToArray(const Tuple);

char *tupleToString(const Tuple);

int count(const Tuple, int);