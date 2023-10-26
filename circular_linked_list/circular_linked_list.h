#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} CircularLinkedList;

CircularLinkedList *createCircularLinkedList();

void insertAtHead(CircularLinkedList *, int);

void insertAtTail(CircularLinkedList *, int);

int deleteAtHead(CircularLinkedList *);

int deleteAtTail(CircularLinkedList *);
