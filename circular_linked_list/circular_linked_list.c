#include "circular_linked_list.h";

void insertAtHead(CircularLinkedList *list, int data)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL)
  {
    list->head = newNode;
    newNode->next = newNode;
  }
  else
  {
    newNode->next = list->head;
    list->head = newNode;
  }
}

void insertAtTail(CircularLinkedList *list, int data)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (list->head == NULL)
  {
    list->head = newNode;
    newNode->next = newNode;
  }
  else
  {
    Node *current = list->head;
    while (current->next != list->head)
    {
      current = current->next;
    }

    current->next = newNode;
    newNode->next = list->head;
  }
}

int deleteAtHead(CircularLinkedList *list)
{
  if (list->head == NULL)
  {
    return -1;
  }

  int data = list->head->data;
  Node *temp = list->head;
  list->head = list->head->next;

  if (list->head == list->head->next)
  {
    list->head = NULL;
  }

  free(temp);
  return data;
}

int deleteAtTail(CircularLinkedList *list)
{
  if (list->head == NULL)
  {
    return -1;
  }

  int data = list->head->data;
  Node *current = list->head;
  Node *prev = NULL;
  while (current->next != list->head)
  {
    prev = current;
    current = current->next;
  }

  prev->next = list->head;
  free(current);
  return data;
}

void printCircularLinkedList(CircularLinkedList *list)
{
  if (list->head == NULL)
  {
    printf("The list is empty.\n");
    return;
  }

  Node *current = list->head;
  do
  {
    printf("%d ", current->data);
    current = current->next;
  } while (current != list->head);

  printf("\n");
}

int search(CircularLinkedList *list, int element)
{
  Node *current = list->head;
  while (current != list->head)
  {
    if (current->data == element)
      return current->data;
    current = current->next;
  }
  return -1;
}

int getLength(CircularLinkedList *list) {
  int length = 0;
  const Node *current = list->head;

  while (current != list->head) {
    length++;
    current = current->next;
  }

  return length;
}

void reverse(CircularLinkedList *list) {
  Node *current = list->head;
  Node *prev = NULL;
  Node *next = NULL;

  while (current != list->head) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  list->head = prev;
}

void rotate(CircularLinkedList *list, int k) {
  Node *current = list->head;
  int i = 0;

  while (i < k && current != list->head) {
    current = current->next;
    i++;
  }

  if (current == list->head)
    return;

  list->head = current->next;
  current->next = list->head->next;
  list->head->next = current;
}