#include "array.h"

Array* createArray() {
    Array* arr = (Array*)malloc(sizeof(Array));
    arr->data = (int*)malloc(sizeof(int) * 0);
    arr->size = 0;
    arr->capacity = 0;
    return arr;
}

void push(Array* arr, int element) {
    if (arr->size >= arr->capacity) {
        arr->capacity += 1;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

int pop(Array* arr) {
    if (arr->size == 0)
        return -1;

    int element = arr->data[arr->size - 1];
    arr->size--;

    free(arr->data[arr->size]);

    if (arr->size < arr->capacity - 1) {
        arr->capacity--;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    return element;
}

int get(Array* arr, int index) {
    if (index < 0 || index >= arr->size)
        return -1;
    
    return arr->data[index];
}

void set(Array* arr, int index, int element) {
    if (index < 0 || index >= arr->size)
        return;
    
    arr->data[index] = element;
}

int indexOf(Array* arr, int element) {
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] == element) 
            return i;
        
    return -1;
}

void removeAt(Array* arr, int index) {
    if (index < 0 || index >= arr->size)
        return;

    free(arr->data[index]);

    for (int i = index; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];

    arr->size--;

    if (arr->size < arr->capacity - 1) {
        arr->capacity--;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

void freeArray(Array* arr) {
    free(arr->data);
    free(arr);
}

void insert(Array* arr, int index, int element) {
    if (index < 0 || index > arr->size)
        return;

    if (arr->size >= arr->capacity) {
        arr->capacity++;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    for (int i = arr->size; i > index; i--)
        arr->data[i] = arr->data[i - 1];

    arr->data[index] = element;
    arr->size++;
}

Array* slice(Array* arr, int start, int end) {
    if (start < 0) 
        start = 0;
    
    if (end >= arr->size)
        end = arr->size - 1;
    
    if (start > end)
        return NULL;

    // Its sizé = end - start + 1
    Array* slicedArr = createArray();
    for (int i = start; i <= end; i++)
        push(slicedArr, arr->data[i]);

    return slicedArr;
}

void concat(Array* arr1, Array* arr2) {
    for (int i = 0; i < arr2->size; i++)
        push(arr1, arr2->data[i]);
}

//(insertion sort)
void sort(Array* arr) {
    for (int i = 1; i < arr->size; i++) {
        int key = arr->data[i];
        int j = i - 1;
        while (j >= 0 && arr->data[j] > key) {
            arr->data[j + 1] = arr->data[j];
            j--;
        }
        arr->data[j + 1] = key;
    }
}

//in-place
void reverse(Array* arr) {
    int left = 0;
    int right = arr->size - 1;
    while (left < right) {
        int temp = arr->data[left];
        arr->data[left] = arr->data[right];
        arr->data[right] = temp;
        left++;
        right--;
    }
}

void clear(Array* arr) {
    for (int i = 0; i < arr->size; i++)
        free(arr->data[i]);
    arr->size = 0;
    arr->capacity = 0;
}

int lastIndexOf(Array* arr, int element) {
    for (int i = arr->size - 1; i >= 0; i--) 
        if (arr->data[i] == element)
            return i;
        
    return -1;
}

int contains(Array* arr, int element) {
    return indexOf(arr, element) != -1;
}

Array* copy(Array* arr) {
    Array* copyArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++) {
        push(copyArr, arr->data[i]);
    }
    return copyArr;
}

int isEmpty(Array* arr) {
    return arr->size == 0;
}

int size(Array* arr) {
    return arr->size;
}

int capacity(Array* arr) {
    return arr->capacity;
}

void trimToSize(Array* arr) {
    if (arr->size < arr->capacity) {
        arr->capacity = arr->size;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

Array* reversedArray(Array* arr) {
    Array* reversedArr = createArray(arr->size);
    for (int i = arr->size - 1; i >= 0; i--) {
        push(reversedArr, arr->data[i]);
    }
    return reversedArr;
}

Array* concatenate(Array* arr1, Array* arr2) {
    Array* concatenatedArr = createArray(arr1->size + arr2->size);
    for (int i = 0; i < arr1->size; i++) {
        push(concatenatedArr, arr1->data[i]);
    }
    for (int i = 0; i < arr2->size; i++) {
        push(concatenatedArr, arr2->data[i]);
    }
    return concatenatedArr;
}

void bubbleSort(Array* arr) {
    for (int i = 0; i < arr->size - 1; i++) {
        for (int j = 0; j < arr->size - i - 1; j++) {
            if (arr->data[j] > arr->data[j + 1]) {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Array* arr, int target) {
    int left = 0;
    int right = arr->size - 1;
    while (left <= right) {
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

Array* unique(Array* arr) {
    Array* uniqueArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++) {
        int element = arr->data[i];
        if (!contains(uniqueArr, element))
            push(uniqueArr, element);
    }
    return uniqueArr;
}

Array* map(Array* arr, int (*function)(int)) {
    Array* mappedArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++) {
        int result = function(arr->data[i]);
        push(mappedArr, result);
    }
    return mappedArr;
}

Array* filter(Array* arr, int (*condition)(int)) {
    Array* filteredArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++) {
        int element = arr->data[i];
        if (condition(element)) {
            push(filteredArr, element);
        }
    }
    return filteredArr;
}

int reduce(Array* arr, int (*function)(int, int), int initial) {
    int result = initial;
    for (int i = 0; i < arr->size; i++) {
        result = function(result, arr->data[i]);
    }
    return result;
}

