#include "minHeap.h"

MinHeap* createMinHeap(int initialCapacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = initialCapacity;
    heap->size = 0;
    heap->arr = (int*)malloc(sizeof(int) * initialCapacity);
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap* heap, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] < heap->arr[parent]) {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(MinHeap* heap, int value) {
    if (heap->size >= heap->capacity) {
        heap->capacity *= 2;
        heap->arr = (int*)realloc(heap->arr, sizeof(int) * heap->capacity);
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void heapifyDown(MinHeap* heap, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < heap->size && heap->arr[left] < heap->arr[smallest])
        smallest = left;
    if (right < heap->size && heap->arr[right] < heap->arr[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap->arr[index], &heap->arr[smallest]);
        heapifyDown(heap, smallest);
    }
}

int extractMin(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty.\n");
        return -1;
    }
    int min = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return min;
}