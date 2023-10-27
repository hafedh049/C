#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int* data;
    int size;
    int capacity;
}Array;