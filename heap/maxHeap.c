#include "maxHeap.h"

MaxHeap *createMaxHeap(int initialCapacity)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->capacity = initialCapacity;
    heap->size = 0;
    heap->arr = (int *)malloc(sizeof(int) * initialCapacity);
    return heap;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MaxHeap *heap, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] > heap->arr[parent])
    {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void insert(MaxHeap *heap, int value)
{
    if (heap->size >= heap->capacity)
    {
        heap->capacity *= 2;
        heap->arr = (int *)realloc(heap->arr, sizeof(int) * heap->capacity);
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

void heapifyDown(MaxHeap *heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

int extractMax(MaxHeap *heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty.\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

void buildMaxHeap(MaxHeap *heap, int *arr, int n)
{
    for (int i = 0; i < n; i++)
        insert(heap, arr[i]);
}

int delete(MaxHeap *heap, int value)
{
    int index = -1;
    for (int i = 0; i < heap->size; i++)
        if (heap->arr[i] == value)
        {
            index = i;
            break;
        }

    if (index == -1)
    {
        printf("Element not found in the heap.\n");
        return -1;
    }
    int deletedValue = heap->arr[index];
    heap->arr[index] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, index);
    return deletedValue;
}

void decreaseKey(MaxHeap *heap, int index, int newValue)
{
    if (index < 0 || index >= heap->size)
    {
        printf("Invalid index.\n");
        return;
    }
    if (newValue < heap->arr[index])
    {
        printf("New value is smaller than the current value.\n");
        return;
    }
    heap->arr[index] = newValue;
    heapifyUp(heap, index);
}

void heapSort(MaxHeap *heap)
{
    int n = heap->size;
    for (int i = n - 1; i >= 0; i--)
        heap->arr[i] = extractMax(heap);
}

void toString(MaxHeap *heap)
{
    printf("[");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d", heap->arr[i]);
        if (i != heap->size - 1)
            printf(", ");
    }
    printf("]\n");
}