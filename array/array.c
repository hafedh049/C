typedef struct Array {
    int* data;
    int size;
    int capacity;
}Array;

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
    if (index < 0 || index > arr->size) {
        // Handle out-of-bounds index
        return;
    }
    if (arr->size >= arr->capacity) {
        // Double the capacity if needed
        arr->capacity *= 2;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    for (int i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = element;
    arr->size++;
}

// Create a new array by slicing the current array
Array* slice(Array* arr, int start, int end) {
    if (start < 0) {
        start = 0;
    }
    if (end >= arr->size) {
        end = arr->size - 1;
    }
    if (start > end) {
        // Handle invalid slice range
        return NULL;
    }
    Array* slicedArr = createArray(end - start + 1);
    for (int i = start; i <= end; i++) {
        push(slicedArr, arr->data[i]);
    }
    return slicedArr;
}

// Concatenate two arrays
void concat(Array* arr1, Array* arr2) {
    for (int i = 0; i < arr2->size; i++) {
        push(arr1, arr2->data[i]);
    }
}

// Sort the array in ascending order (insertion sort)
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

// Reverse the elements of the array in-place
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