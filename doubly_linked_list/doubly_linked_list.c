#include "doubly_linked_list.h"

DoublyLinkedList *createDoublyLinkedList()
{
    DoublyLinkedList *linkedList = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    linkedList->head = NULL;
    return linkedList;
}

int isEmpty(DoublyLinkedList list)
{
    return list.head == NULL;
}

void append(DoublyLinkedList *list, int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    if (isEmpty(*list))
    {
        node->previous = NULL;
        list->head = node;
    }
    else
    {
        Node *last = list->head;
        while (last->next)
            last = last->next;
        node->previous = last;
        last->next = node;
    }
}

void appendAll(DoublyLinkedList *list, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        append(list, va_arg(args, int));
}

void shiftAll(DoublyLinkedList *list, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        shift(list, va_arg(args, int));
}

void shift(DoublyLinkedList *list, int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;

    if (isEmpty(*list))
    {
        node->next = NULL;
        node->previous = NULL;
        list->head = node;
    }
    else
    {
        node->next = list->head;
        list->head->previous = node;
        list->head = node;
    }
}

void insertAfter(DoublyLinkedList *list, Node *node, int item)
{
    if (isEmpty(*list))
    {
        append(list, item);
        return;
    }

    Node *headNode = list->head;
    while (headNode && headNode != node)
        headNode = headNode->next;
    if (headNode)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = item;
        node->next = headNode->next;
        headNode->next = node;
    }
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("You entered an inexisting element from the linked list");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

void insertAllAfter(DoublyLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertAfter(list, node, va_arg(args, int));
}

void insertBefore(DoublyLinkedList *list, Node *searchnode, int item)
{
    if (isEmpty(*list))
    {
        append(list, item);
        return;
    }

    Node *headNode = list->head;
    while (headNode && headNode != searchnode)
        headNode = headNode->next;
    if (headNode)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = item;
        node->next = headNode->next;
        node->previous = headNode;
        headNode->next = node;
        node->data = headNode->data;
        headNode->data = item;
    }
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("You entered an inexisting element from the linked list");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

void insertAllBefore(DoublyLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertBefore(list, node, va_arg(args, int));
}

void showAllItems(DoublyLinkedList list)
{
    printf("\033[1;33m\n\n---------------------------\n\n");

    if (isEmpty(list))
    {
        printf("This list is empty x(");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
        return;
    }
    Node *head = list.head;
    while (head)
    {
        if (head->next)
            printf("\033[1;32m| %d | <-> ", head->data);
        else
            printf("\033[1;32m| %d |", head->data);
        head = head->next;
    }
    printf("\033[1;33m\n\n---------------------------\n\n");
    printf("\033[1;0m");
}

int search(DoublyLinkedList l, int item)
{
    assert(!isEmpty(l));
    Node *head = l.head;
    while (head)
    {
        if (head->data == item)
            return 1;
        head = head->next;
    }
    return 0;
}

int popFirst(DoublyLinkedList *list)
{
    assert(!isEmpty(*list));

    Node *head = list->head;
    int result = head->data;
    list->head = list->head->next;
    if (list->head)
        list->head->previous = NULL;
    free(head);
    return result;
}

int popLast(DoublyLinkedList *list)
{
    assert(!isEmpty(*list));

    Node *head = list->head;
    int result;
    if (!head->next)
    {
        result = head->data;
        list->head = NULL;
        free(head);
        return result;
    }
    while (head->next->next)
        head = head->next;
    result = head->next->data;
    free(head->next);
    head->next = NULL;
    return result;
}

int pop(DoublyLinkedList *list, int item)
{
    assert(!isEmpty(*list));
    if (list->head->data == item)
        return popFirst(list);
    Node *head = list->head;
    while (head->next && head->next->data != item)
        head = head->next;
    if (head->next)
    {
        Node *aux = head->next;
        int value = aux->data;
        head->next = aux->next;
        free(aux);
        return value;
    }
    else
        return -1;
}

int getFirst(DoublyLinkedList list)
{
    assert(!isEmpty(list));
    return list.head->data;
}

int getLast(DoublyLinkedList list)
{
    assert(!isEmpty(list));
    Node *node = list.head;
    while (node->next)
        node = node->next;
    return node->data;
}

int getSize(DoublyLinkedList list, Node *head)
{
    if (isEmpty(list))
        return 0;
    if (head)
        return 1 + getSize(list, head->next);
}

int getItemByIndex(DoublyLinkedList list, int index)
{
    assert(!isEmpty(list));
    int counter = -1;
    Node *head = list.head;
    while (head)
    {
        counter++;
        if (counter == index)
            break;
        head = head->next;
    }
    assert(counter == index);
    return head->data;
}

void sort(DoublyLinkedList *list, int key)
{
    Node *primaryPointer, *secondaryPointer;
    for (primaryPointer = list->head; primaryPointer->next; primaryPointer = primaryPointer->next)
        for (secondaryPointer = primaryPointer->next; secondaryPointer; secondaryPointer = secondaryPointer->next)
            if (key == 1 && primaryPointer->data > secondaryPointer->data)
                primaryPointer->data = primaryPointer->data + secondaryPointer->data - (secondaryPointer->data = primaryPointer->data);
            else if (key == -1 && primaryPointer->data < secondaryPointer->data)
                primaryPointer->data = primaryPointer->data + secondaryPointer->data - (secondaryPointer->data = primaryPointer->data);
}

void reverse(DoublyLinkedList *list)
{
    Node *temp = NULL;
    Node *current = list->head;

    while (current != NULL)
    {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous;
    }

    if (temp != NULL)
        list->head = temp->previous;
}

Node *getNode(DoublyLinkedList list, int item)
{
    assert(!isEmpty(list));
    Node *head = list.head;
    while (head)
    {
        if (head->data == item)
            return head;
        head = head->next;
    }
    return NULL;
}

void update(DoublyLinkedList *list, int oldValue, int newValue)
{
    Node *element = getNode(*list, oldValue);
    if (element)
        element->data = newValue;
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("Item does not exist");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

void concatenate(DoublyLinkedList *list1, DoublyLinkedList list2)
{
    if (list1->head == NULL)
        list1->head = list2.head;
    else
    {
        Node *current = list1->head;
        while (current->next != NULL)
            current = current->next;

        current->next = list2.head;
        if (list2.head != NULL)
            list2.head->previous = current;
    }
}

void splitByPosition(DoublyLinkedList list, int position, DoublyLinkedList *firstHalf, DoublyLinkedList *secondHalf)
{
    firstHalf->head = NULL;
    secondHalf->head = NULL;

    Node *current = list.head;
    int currentPosition = 0;
    while (current != NULL && currentPosition < position)
    {
        current = current->next;
        currentPosition++;
    }
    if (current != NULL)
    {
        firstHalf->head = list.head;
        secondHalf->head = current->next;

        if (secondHalf->head != NULL)
            secondHalf->head->previous = NULL;

        current->next = NULL;
    }
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("Item does not exist");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

DoublyLinkedList *mergeSorted(DoublyLinkedList firstSortedList, DoublyLinkedList secondSortedList, int key)
{
    DoublyLinkedList *thirdSortedList = createDoublyLinkedList();
    Node *secondListPointer = secondSortedList.head;
    Node *firstListPointer = firstSortedList.head;
    while (firstListPointer && secondListPointer)
        if ((key == 1 && firstListPointer->data < secondListPointer->data) ||
            (key != 1 && firstListPointer->data > secondListPointer->data))
        {
            append(thirdSortedList, firstListPointer->data);
            firstListPointer = firstListPointer->next;
        }
        else
        {
            if (firstListPointer->data == secondListPointer->data)
                firstListPointer = firstListPointer->next;
            append(thirdSortedList, secondListPointer->data);
            secondListPointer = secondListPointer->next;
        }
    while (firstListPointer)
    {
        append(thirdSortedList, firstListPointer->data);
        firstListPointer = firstListPointer->next;
    }

    while (secondListPointer)
    {
        append(thirdSortedList, secondListPointer->data);
        secondListPointer = secondListPointer->next;
    }

    return thirdSortedList;
}

bool FloydTurtoisHareCycle(DoublyLinkedList list)
{
    if (!list.head || !list.head->next)
        return false;

    Node *tortoise = list.head;
    Node *hare = list.head;

    while (hare != NULL && hare->next != NULL)
    {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            return true;
    }

    return false;
}

Node *findIntersectionNode(DoublyLinkedList list1, DoublyLinkedList list2)
{
    if (list1.head == NULL || list2.head == NULL)
        return NULL;

    Node *ptr1 = list1.head;
    Node *ptr2 = list2.head;

    bool switchPtr1 = false;
    bool switchPtr2 = false;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;

        if (ptr1 == NULL && !switchPtr1)
        {
            ptr1 = list2.head;
            switchPtr1 = true;
        }

        if (ptr2 == NULL && !switchPtr2)
        {
            ptr2 = list1.head;
            switchPtr2 = true;
        }

        if (switchPtr1 && switchPtr2 && ptr1 != ptr2)
        {
            return NULL;
        }
    }

    return ptr1;
}

void removeDuplicates(DoublyLinkedList *list)
{
    if (list->head == NULL || list->head->next == NULL)
        return;

    Node *current = list->head;

    while (current != NULL)
    {
        Node *runner = current;

        while (runner->next != NULL)
            if (runner->next->data == current->data)
            {
                Node *duplicate = runner->next;
                runner->next = runner->next->next;

                if (runner->next != NULL)
                    runner->next->previous = runner;

                free(duplicate);
            }
            else
                runner = runner->next;
        current = current->next;
    }
}

bool isSortedAsc(DoublyLinkedList list)
{
    if (list.head == NULL || list.head->next == NULL)
        return true;

    Node *current = list.head;

    while (current->next != NULL)
    {
        if (current->data > current->next->data)
            return false;
        current = current->next;
    }

    return true;
}

bool isSortedDesc(DoublyLinkedList list)
{
    if (list.head == NULL || list.head->next == NULL)
        return true;

    Node *current = list.head;

    while (current->next != NULL)
    {
        if (current->data < current->next->data)
            return false;
        current = current->next;
    }

    return true;
}

Node *searchWithCriteria(DoublyLinkedList list, CriteriaFunction criteria)
{
    Node *current = list.head;

    while (current != NULL)
    {
        if (criteria(current->data))
            return current;
        current = current->next;
    }

    return NULL;
}