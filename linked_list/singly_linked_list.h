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

typedef struct SinglyLinkedList
{
    Node *head;
} SinglyLinkedList;

typedef bool (*CriteriaFunction)(int);

SinglyLinkedList *createSinglyLinkedList();
void showAllItems(SinglyLinkedList);
void insertBefore(SinglyLinkedList *, Node *, int);
void insertAfter(SinglyLinkedList *, Node *, int);
void shift(SinglyLinkedList *, int);
void append(SinglyLinkedList *, int);
int isEmpty(SinglyLinkedList);
int search(SinglyLinkedList, int);
void insertAllBefore(SinglyLinkedList *, Node *, int, int, ...);
void insertAllAfter(SinglyLinkedList *, Node *, int, int, ...);
void appendAll(SinglyLinkedList *, int, ...);
void shiftAll(SinglyLinkedList *, int, ...);
int popFirst(SinglyLinkedList *);
int popLast(SinglyLinkedList *);
int pop(SinglyLinkedList *, int);
int getSize(SinglyLinkedList, Node *);
int getFirst(SinglyLinkedList);
int getLast(SinglyLinkedList);
int getItemByIndex(SinglyLinkedList, int);
void sort(SinglyLinkedList *, int);
Node *getNode(SinglyLinkedList, int);
void reverse(SinglyLinkedList *);
void update(SinglyLinkedList *, int, int);
void concatenate(SinglyLinkedList *, SinglyLinkedList);
void splitByPosition(SinglyLinkedList, int, SinglyLinkedList *, SinglyLinkedList *);
SinglyLinkedList *mergeSorted(SinglyLinkedList, SinglyLinkedList, int);
bool FloydTurtoisHareCycle(SinglyLinkedList);
Node *findIntersectionNode(SinglyLinkedList, SinglyLinkedList);
void removeDuplicates(SinglyLinkedList *);
bool isSortedAsc(SinglyLinkedList);
bool isSortedDesc(SinglyLinkedList);
Node* searchWithCriteria(SinglyLinkedList, CriteriaFunction);