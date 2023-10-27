

#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap {
    int* arr;
    int capacity;
    int size;
} MaxHeap;

MaxHeap *createMaxHeap(int);

void heapifyUp(MaxHeap *, int);

void insert(MaxHeap *, int);

void heapifyDown(MaxHeap *, int);

int extractMax(MaxHeap *);

void buildHeap(MaxHeap *, int *, int);

int delete(MaxHeap *, int);

void decreaseKey(MaxHeap *, int, int);

void heapSort(MaxHeap *);