#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Array {
    int* data;
    int size;
    int capacity;
}Array;