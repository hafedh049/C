#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *previous;
} Node;

typedef struct DoublyLinkedList
{
    Node *head;
} DoublyLinkedList;

typedef bool (*CriteriaFunction)(int);

DoublyLinkedList *createDoublyLinkedList();
void showAllItems(DoublyLinkedList);
void insertBefore(DoublyLinkedList *, Node *, int);
void insertAfter(DoublyLinkedList *, Node *, int);
void shift(DoublyLinkedList *, int);
void append(DoublyLinkedList *, int);
int isEmpty(DoublyLinkedList);
int search(DoublyLinkedList, int);
void insertAllBefore(DoublyLinkedList *, Node *, int, int, ...);
void insertAllAfter(DoublyLinkedList *, Node *, int, int, ...);
void appendAll(DoublyLinkedList *, int, ...);
void shiftAll(DoublyLinkedList *, int, ...);
int popFirst(DoublyLinkedList *);
int popLast(DoublyLinkedList *);
int pop(DoublyLinkedList *, int);
int getSize(DoublyLinkedList, Node *);
int getFirst(DoublyLinkedList);
int getLast(DoublyLinkedList);
int getItemByIndex(DoublyLinkedList, int);
void sort(DoublyLinkedList *, int);
Node *getNode(DoublyLinkedList, int);
void reverse(DoublyLinkedList *);
void update(DoublyLinkedList *, int, int);
void concatenate(DoublyLinkedList *, DoublyLinkedList);
void splitByPosition(DoublyLinkedList, int, DoublyLinkedList *, DoublyLinkedList *);
DoublyLinkedList *mergeSorted(DoublyLinkedList, DoublyLinkedList, int);
bool FloydTurtoisHareCycle(DoublyLinkedList);
Node *findIntersectionNode(DoublyLinkedList, DoublyLinkedList);
void removeDuplicates(DoublyLinkedList *);
bool isSortedAsc(DoublyLinkedList);
bool isSortedDesc(DoublyLinkedList);
Node *searchWithCriteria(DoublyLinkedList, CriteriaFunction);