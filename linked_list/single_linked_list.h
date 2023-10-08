#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct SingleLinkedList
{
    Node *head;
} SingleLinkedList;

SingleLinkedList* createSingleLinkedList();
void showAllItems(SingleLinkedList);
void insertBefore(SingleLinkedList *, Node *, int);
void insertAfter(SingleLinkedList *, Node *, int);
void shift(SingleLinkedList *, int);
void append(SingleLinkedList *, int);
int isEmpty(SingleLinkedList);
int search(SingleLinkedList, int);
void insertAllBefore(SingleLinkedList *, Node *, int, int, ...);
void insertAllAfter(SingleLinkedList *, Node *, int, int, ...);
void appendAll(SingleLinkedList *, int, ...);
void shiftAll(SingleLinkedList *, int, ...);
int popFirst(SingleLinkedList *);
int popLast(SingleLinkedList *);
int pop(SingleLinkedList *, int);
int getSize(SingleLinkedList, Node *);
int getFirst(SingleLinkedList);
int getLast(SingleLinkedList);
int getItemByIndex(SingleLinkedList, int);
void sort(SingleLinkedList *, int);
Node *getNode(SingleLinkedList, int);
void reverse(SingleLinkedList *);
void update(SingleLinkedList *, int, int);
void concatenate(SingleLinkedList *, SingleLinkedList);
void splitByPosition(SingleLinkedList, int, SingleLinkedList *, SingleLinkedList *);
SingleLinkedList *mergeSorted(SingleLinkedList, SingleLinkedList, int);
bool FloydTurtoisHareCycle(SingleLinkedList);
Node* findIntersectionNode(SingleLinkedList, SingleLinkedList);