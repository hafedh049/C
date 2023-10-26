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

int getLength(CircularLinkedList *list)
{
  int length = 0;
  const Node *current = list->head;

  while (current != list->head)
  {
    length++;
    current = current->next;
  }

  return length;
}

void reverse(CircularLinkedList *list)
{
  Node *current = list->head;
  Node *prev = NULL;
  Node *next = NULL;

  while (current != list->head)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  list->head = prev;
}

void rotate(CircularLinkedList *list, int k)
{
  Node *current = list->head;
  int i = 0;

  while (i < k && current != list->head)
  {
    current = current->next;
    i++;
  }

  if (current == list->head)
    return;

  list->head = current->next;
  current->next = list->head->next;
  list->head->next = current;
}

Node *findMiddleElement(CircularLinkedList *list)
{
  Node *current = list->head;
  Node *previous = NULL;

  while (current->next != list->head)
  {
    previous = current;
    current = current->next;
  }

  return previous;
}

Node *findKthElement(CircularLinkedList *list, int k)
{
  int i = 0;
  Node *current = list->head;

  while (i < k && current != list->head)
  {
    current = current->next;
    i++;
  }

  if (current == list->head)
    return NULL;

  return current;
}

CircularLinkedList *mergeCircularLinkedLists(CircularLinkedList *list1, CircularLinkedList *list2)
{
  CircularLinkedList *mergedList = createCircularLinkedList();

  Node *current1 = list1->head;
  Node *current2 = list2->head;

  while (current1 != list1->head || current2 != list2->head)
  {
    if (current1 == list1->head)
    {
      insertAtHead(mergedList, current2->data);
      current2 = current2->next;
    }
    else if (current2 == list2->head)
    {
      insertAtHead(mergedList, current1->data);
      current1 = current1->next;
    }
    else
    {
      if (current1->data < current2->data)
      {
        insertAtHead(mergedList, current1->data);
        current1 = current1->next;
      }
      else
      {
        insertAtHead(mergedList, current2->data);
        current2 = current2->next;
      }
    }
  }

  return mergedList;
}

int isPalindrome(CircularLinkedList *list)
{
  Node *current = list->head;
  Node *opposite = findMiddleElement(list);

  while (current != opposite)
  {
    if (current->data != opposite->data)
      return 0;

    current = current->next;
    opposite = opposite->next->next;
  }

  return 1;
}

void deleteNodeAtPosition(CircularLinkedList *list, int position)
{
  if (position < 0 || position >= getLength(list))
    return;

  int currentPosition = 0;
  Node *current = list->head;
  Node *previous = NULL;

  while (current != list->head)
  {
    if (currentPosition == position)
    {
      if (previous == NULL)
        list->head = current->next;
      else
        previous->next = current->next;

      free(current);
      break;
    }

    currentPosition++;
    current = current->next;
  }
}

void insertNodeAfterNode(CircularLinkedList *list, Node *node, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = node->next;

  node->next = newNode;
}

int findFirstOccurrence(CircularLinkedList *list, int element)
{
  int position = 0;
  Node *current = list->head;

  while (current != list->head)
  {
    if (current->data == element)
      return position;

    position++;
    current = current->next;
  }

  return -1;
}

int findLastOccurrence(CircularLinkedList *list, int element)
{
  int position = -1;
  Node *current = list->head;

  while (current != list->head)
  {
    if (current->data == element)
      position = getLength(list) - 1 - position;

    position++;
    current = current->next;
  }

  return position;
}

int hasCycle(CircularLinkedList *list)
{
  Node *fast = list->head;
  Node *slow = list->head;

  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow)
    {
      return

          1;
    }
  }

  return 0;
}

CircularLinkedList **splitCircularLinkedList(CircularLinkedList *list)
{
  CircularLinkedList *firstHalf = createCircularLinkedList();
  CircularLinkedList *secondHalf = createCircularLinkedList();

  Node *middleNode = findMiddleElement(list);

  Node *current = list->head;
  while (current != middleNode)
  {
    insertAtTail(firstHalf, current->data);
    current = current->next;
  }

  secondHalf->head = middleNode->next;

  firstHalf->head->next = secondHalf->head;

  secondHalf->head->next = firstHalf->head;

  CircularLinkedList **halves = malloc(sizeof(CircularLinkedList *) * 2);
  halves[0] = firstHalf;
  halves[1] = secondHalf;

  return halves;
}

int findMaximumElement(CircularLinkedList *list)
{
  int maximumElement = list->head->data;
  Node *current = list->head->next;

  while (current != list->head)
  {
    if (current->data > maximumElement)
      maximumElement = current->data;

    current = current->next;
  }

  return maximumElement;
}

int findMinimumElement(CircularLinkedList *list)
{
  int minimumElement = list->head->data;
  Node *current = list->head->next;

  while (current != list->head)
  {
    if (current->data < minimumElement)
      minimumElement = current->data;

    current = current->next;
  }

  return minimumElement;
}
