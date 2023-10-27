#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>

typedef struct Array
{
    int *data;
    int size;
    int capacity;
} Array;

void push(Array *, int);
int pop(Array *);
int get(Array *, int);
void set(Array *, int, int);
int indexOf(Array *, int);
void removeAt(Array *, int);
void freeArray(Array *);
void insert(Array *, int, int);
void concat(Array *, Array *);
void sort(Array *);
void reverse(Array *);
void clear(Array *);
int lastIndexOf(Array *, int);
int contains(Array *, int);
int isEmpty(Array *);
int size(Array *);
int capacity(Array *);
void trimToSize(Array *);
void bubbleSort(Array *);
int binarySearch(Array *, int);
int reduce(Array *, int (*)(int, int), int);
void forEach(Array *, void (*)(int));
int find(Array *, int (*)(int));
int some(Array *, int (*)(int));
int every(Array *, int (*)(int));
int maximum(Array *);
int minimum(Array *);
void rotateLeft(Array *, int);
void rotateRight(Array *, int);
void shuffle(Array *);
void swap(Array *, int, int);
void fill(Array *, int);
int compareAscending(const void *, const void *);
void qqsort(Array *);
int shift(Array *);
void unshift(Array *, int);
double average(Array *);
int sum(Array *);
int searchWithCriteria(Array *, int (*)(int));
void toString(Array *);
void pushMany(Array *, int, ...);
void removeAll(Array *, int);
void removeAllMany(Array *, int, ...);