#include <stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
} CircularLinkedList;

CircularLinkedList *createCircularLinkedList();

void insertAtHead(CircularLinkedList *, int);

void insertAtTail(CircularLinkedList *, int);

int deleteAtHead(CircularLinkedList *);

int deleteAtTail(CircularLinkedList *);

int search(CircularLinkedList *, int);

int getLength(CircularLinkedList *);

void reverse(CircularLinkedList *);

void rotate(CircularLinkedList *, int);

Node *findMiddleElement(CircularLinkedList *);

Node *findKthElement(CircularLinkedList *, int);

CircularLinkedList *mergeCircularLinkedLists(CircularLinkedList *, CircularLinkedList *);

int isPalindrome(CircularLinkedList *);

void deleteNodeAtPosition(CircularLinkedList *, int);

void insertNodeAfterNode(CircularLinkedList *, Node *, int);

int findFirstOccurrence(CircularLinkedList *, int);

int findLastOccurrence(CircularLinkedList *, int);

int hasCycle(CircularLinkedList *);

CircularLinkedList **splitCircularLinkedList(CircularLinkedList *);

int findMaximumElement(CircularLinkedList *);

int findMinimumElement(CircularLinkedList *);

void printCircularLinkedList(CircularLinkedList *);