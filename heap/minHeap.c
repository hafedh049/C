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

void buildHeap(MinHeap* heap, int* arr, int n) {
    for (int i = 0; i < n; i++)
        insert(heap, arr[i]);
}

int delete(MinHeap* heap, int value) {
    int index = -1;
    for (int i = 0; i < heap->size; i++)
        if (heap->arr[i] == value) {
            index = i;
            break;
        }
    
    if (index == -1) {
        printf("Element not found in the heap.\n");
        return -1;
    }
    int deletedValue = heap->arr[index];
    heap->arr[index] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, index);
    return deletedValue;
}

void decreaseKey(MinHeap* heap, int index, int newValue) {
    if (index < 0 || index >= heap->size) {
        printf("Invalid index.\n");
        return;
    }
    if (newValue > heap->arr[index]) {
        printf("New value is greater than the current value.\n");
        return;
    }
    heap->arr[index] = newValue;
    heapifyUp(heap, index);
}

void heapSort(MinHeap* heap) {
    int n = heap->size;
    for (int i = n - 1; i >= 0; i--)
        heap->arr[i] = extractMin(heap);
}

void toString(MinHeap* heap) {
    printf("[");
    for (int i = 0; i < heap->size; i++) {
        if (i != heap->size - 1) 
            printf(", ");
        
        printf("%d", heap->arr[i]);
    }
    printf("]\n");
}