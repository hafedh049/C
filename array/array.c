#include "array.h"

Array *createArray()
{
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->data = (int *)malloc(sizeof(int) * 0);
    arr->size = 0;
    arr->capacity = 0;
    return arr;
}

void push(Array *arr, int element)
{
    if (arr->size >= arr->capacity)
    {
        arr->capacity += 1;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

int pop(Array *arr)
{
    if (arr->size == 0)
        return -1;

    int element = arr->data[arr->size - 1];
    arr->size--;

    free(&arr->data[arr->size]);

    if (arr->size < arr->capacity - 1)
    {
        arr->capacity--;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    return element;
}

int get(Array *arr, int index)
{
    if (index < 0 || index >= arr->size)
        return -1;

    return arr->data[index];
}

void set(Array *arr, int index, int element)
{
    if (index < 0 || index >= arr->size)
        return;

    arr->data[index] = element;
}

int indexOf(Array *arr, int element)
{
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] == element)
            return i;

    return -1;
}

void removeAt(Array *arr, int index)
{
    if (index < 0 || index >= arr->size)
        return;

    free(&arr->data[index]);

    for (int i = index; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];

    arr->size--;

    if (arr->size < arr->capacity - 1)
    {
        arr->capacity--;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

void freeArray(Array *arr)
{
    free(arr->data);
    free(arr);
}

void insert(Array *arr, int index, int element)
{
    if (index < 0 || index > arr->size)
        return;

    if (arr->size >= arr->capacity)
    {
        arr->capacity++;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    for (int i = arr->size; i > index; i--)
        arr->data[i] = arr->data[i - 1];

    arr->data[index] = element;
    arr->size++;
}

Array *slice(Array *arr, int start, int end)
{
    if (start < 0)
        start = 0;

    if (end >= arr->size)
        end = arr->size - 1;

    if (start > end)
        return NULL;

    // Its sizé = end - start + 1
    Array *slicedArr = createArray();
    for (int i = start; i <= end; i++)
        push(slicedArr, arr->data[i]);

    return slicedArr;
}

void concat(Array *arr1, Array *arr2)
{
    for (int i = 0; i < arr2->size; i++)
        push(arr1, arr2->data[i]);
}

//(insertion sort)
void sort(Array *arr)
{
    for (int i = 1; i < arr->size; i++)
    {
        int key = arr->data[i];
        int j = i - 1;
        while (j >= 0 && arr->data[j] > key)
        {
            arr->data[j + 1] = arr->data[j];
            j--;
        }
        arr->data[j + 1] = key;
    }
}

// in-place
void reverse(Array *arr)
{
    int left = 0;
    int right = arr->size - 1;
    while (left < right)
    {
        int temp = arr->data[left];
        arr->data[left] = arr->data[right];
        arr->data[right] = temp;
        left++;
        right--;
    }
}

void clear(Array *arr)
{
    for (int i = 0; i < arr->size; i++)
        free(&arr->data[i]);
    arr->size = 0;
    arr->capacity = 0;
}

int lastIndexOf(Array *arr, int element)
{
    for (int i = arr->size - 1; i >= 0; i--)
        if (arr->data[i] == element)
            return i;

    return -1;
}

int contains(Array *arr, int element)
{
    return indexOf(arr, element) != -1;
}

Array *copy(Array *arr)
{
    Array *copyArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
        push(copyArr, arr->data[i]);
    
    return copyArr;
}

int isEmpty(Array *arr)
{
    return arr->size == 0;
}

int size(Array *arr)
{
    return arr->size;
}

int capacity(Array *arr)
{
    return arr->capacity;
}

void trimToSize(Array *arr)
{
    if (arr->size < arr->capacity)
    {
        arr->capacity = arr->size;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

Array *reversedArray(Array *arr)
{
    Array *reversedArr = createArray(arr->size);
    for (int i = arr->size - 1; i >= 0; i--)
        push(reversedArr, arr->data[i]);

    return reversedArr;
}

Array *concatenate(Array *arr1, Array *arr2)
{
    Array *concatenatedArr = createArray(arr1->size + arr2->size);
    for (int i = 0; i < arr1->size; i++)
        push(concatenatedArr, arr1->data[i]);
    for (int i = 0; i < arr2->size; i++)
        push(concatenatedArr, arr2->data[i]);

    return concatenatedArr;
}

void bubbleSort(Array *arr)
{
    for (int i = 0; i < arr->size - 1; i++)
        for (int j = 0; j < arr->size - i - 1; j++)
            if (arr->data[j] > arr->data[j + 1])
            {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
    
}

int binarySearch(Array *arr, int target)
{
    int left = 0;
    int right = arr->size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr->data[mid] == target)
            return mid;
        if (arr->data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

Array *unique(Array *arr)
{
    Array *uniqueArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (!contains(uniqueArr, element))
            push(uniqueArr, element);
    }
    return uniqueArr;
}

Array *map(Array *arr, int (*function)(int))
{
    Array *mappedArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int result = function(arr->data[i]);
        push(mappedArr, result);
    }
    return mappedArr;
}

Array *filter(Array *arr, int (*condition)(int))
{
    Array *filteredArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (condition(element))
            push(filteredArr, element);
    }
    return filteredArr;
}

int reduce(Array *arr, int (*function)(int, int), int initial)
{
    int result = initial;
    for (int i = 0; i < arr->size; i++)
        result = function(result, arr->data[i]);

    return result;
}

void forEach(Array *arr, void (*function)(int))
{
    for (int i = 0; i < arr->size; i++)
        function(arr->data[i]);
}

int find(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (condition(element))
            return element;
    }
    return -1;
}

int some(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
        if (condition(arr->data[i]))
            return 1;

    return 0;
}

int every(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
        if (!condition(arr->data[i]))
            return 0;

    return 1;
}

int maximum(Array *arr)
{
    int maximum = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        if (arr->data[i] > maximum)
            maximum = arr->data[i];

    return maximum;
}

int minimum(Array *arr)
{
    int minimum = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        if (arr->data[i] < minimum)
            minimum = arr->data[i];

    return minimum;
}

void rotateLeft(Array *arr, int positions)
{
    if (positions < 0)
        positions = positions + arr->size;

    positions = positions % arr->size;

    Array *tempArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int newPosition = (i + positions) % arr->size;
        tempArr->data[newPosition] = arr->data[i];
    }
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = tempArr->data[i];

    freeArray(tempArr);
}

void rotateRight(Array *arr, int positions)
{
    if (positions < 0)
        positions = positions + arr->size;

    positions = positions % arr->size;

    Array *tempArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int newPosition = (i - positions + arr->size) % arr->size;
        tempArr->data[newPosition] = arr->data[i];
    }
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = tempArr->data[i];

    freeArray(tempArr);
}

void shuffle(Array* arr) {
    srand(time(NULL));
    for (int i = arr->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
    }
}

void swap(Array* arr, int index1, int index2) {
    if (index1 >= 0 && index1 < arr->size && index2 >= 0 && index2 < arr->size) {
        int temp = arr->data[index1];
        arr->data[index1] = arr->data[index2];
        arr->data[index2] = temp;
    }
}

void fill(Array* arr, int value) {
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = value;
}

int compareAscending(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void qqsort(Array* arr) {
    qsort(arr->data, arr->size, sizeof(int), compareAscending);
}

char* join(Array* arr, const char* delimiter) {
    int resultLength = 1;
    for (int i = 0; i < arr->size; i++) {
        int element = arr->data[i];
        int digits = element == 0 ? 1 : (int)(log10(abs(element)) + 1);
        resultLength += digits + (i < arr->size - 1 ? strlen(delimiter) : 0);
    }

    char* result = (char*)malloc(resultLength);
    result[0] = '\0';

    for (int i = 0; i < arr->size; i++) {
        const int MAX_STRING_LENGTH = (int)(log10(abs(arr->data[i])) + 1);
        char *elementAsString = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
        snprintf(elementAsString, MAX_STRING_LENGTH, "%d", arr->data[i]);
        strcat(result, elementAsString);
        if (i < arr->size - 1)
            strcat(result, delimiter);
        free(elementAsString);
        resultLength = strlen(result) + 1;
        result = (char*)realloc(result, resultLength + 1);
    }

    return result;
}

int shift(Array* arr) {
    if (arr->size == 0)
        return -1;
    
    int element = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        arr->data[i - 1] = arr->data[i];

    arr->size--;

    if (arr->size < arr->capacity - 1) {
        arr->capacity -= 1;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    return element;
}

void unshift(Array* arr, int element) {
    if (arr->size >= arr->capacity) {
        arr->capacity++;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    for (int i = arr->size; i > 0; i--)
        arr->data[i] = arr->data[i - 1];
    
    arr->data[0] = element;
    arr->size++;

    if (arr->size == arr->capacity) {
        arr->capacity++;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

double average(Array* arr) {
    if (arr->size == 0)
        return 0.0;

    return (double)sum(arr) / arr->size;
}

int sum(Array* arr) {
    int result = 0;
    for (int i = 0; i < arr->size; i++)
        result += arr->data[i];
    
    return result;
}

int searchWithCriteria(Array* arr, int (*criteria)(int)) {
    for (int i = 0; i < arr->size; i++) {
        if (criteria(arr->data[i]))
            return arr->data[i];
    
    }
    return -1;
}

void toString(Array* arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i != arr->size - 1) 
            printf(", ");
    }
    printf("]\n");
}

void pushMany(Array* arr, int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int item = va_arg(args, int);
        push(arr, item);
    }

    va_end(args);
}

void removeAll(Array* arr, int element) {
    int newSize = 0;
    
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] != element) {
            arr->data[newSize] = arr->data[i];
            newSize++;
        }
    }
    
    arr->size = newSize;
}

void removeAllMany(Array* arr, int numIndices, ...) {
    va_list args;
    va_start(args, numIndices);

    for (int i = 0; i < numIndices; i++) {
        int index = va_arg(args, int);
        if (index >= 0 && index < arr->size)
            removeAll(arr, arr->data[index]);
    }

    va_end(args);
}