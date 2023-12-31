#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap
{
    int *arr;
    int capacity;
    int size;
} MinHeap;

MinHeap *createMinHeap(int);

void heapifyUp(MinHeap *, int);

void insert(MinHeap *, int);

void heapifyDown(MinHeap *, int);

int extractMin(MinHeap *);

void buildHeap(MinHeap *, int *, int);

int delete(MinHeap *, int);

void decreaseKey(MinHeap *, int, int);

void heapSort(MinHeap *);