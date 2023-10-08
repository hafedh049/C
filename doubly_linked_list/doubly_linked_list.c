#include "doubly_linked_list.h"

DoublyLinkedList *createDoublyLinkedList()
{
    DoublyLinkedList *linkedList = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    return linkedList;
}

int isEmpty(DoublyLinkedList list)
{
    return list.head == NULL && list.tail == NULL;
}

void append(DoublyLinkedList *list, int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    if (isEmpty(*list))
    {
        list->head = node;
        list->tail = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
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
        list->head = node;
        list->tail = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void insertAfter(DoublyLinkedList *list, Node *node, int item)
{
    if (isEmpty(*list) || node == list->tail)
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

void insertBefore(DoublyLinkedList *list, Node *node, int item)
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

void showAllItems(DoublyLinkedList DoublyLinkedList)
{
    printf("\033[1;33m\n\n---------------------------\n\n");

    if (isEmpty(DoublyLinkedList))
    {
        printf("This list is empty x(");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
        return;
    }
    Node *head = DoublyLinkedList.head;
    while (head)
    {
        if (head->next)
            printf("\033[1;32m| %d | -> ", head->data);
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
    Node *tail = l.tail;
    if(tail->data == head->data)
        return 1;
    while (head != tail)
    {
        if (head->data == item)
            return 1;
        if (tail->data == item)
            return 1;
        head = head->next;
        tail = tail->next;
    }
    return 0;
}

int popFirst(DoublyLinkedList *sll)
{
    assert(!isEmpty(*sll));

    Node *head = sll->head;
    int result = head->data;
    sll->head = sll->head->next;
    free(head);
    return result;
}

int popLast(DoublyLinkedList *sll)
{
    assert(!isEmpty(*sll));

    Node *head = sll->head;
    int result;
    if (!head->next)
    {
        result = head->data;
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

int pop(DoublyLinkedList *sll, int item)
{
    assert(!isEmpty(*sll));
    if (!sll->head->next && sll->head->data == item)
        return popFirst(sll);
    Node *head = sll->head;
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
    {
        return 2147483647;
    }
}

int getFirst(DoublyLinkedList sll)
{
    assert(!isEmpty(sll));
    return sll.head->data;
}

int getLast(DoublyLinkedList sll)
{
    assert(!isEmpty(sll));
    Node *node = sll.head;
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
    Node *prev = NULL;
    Node *current = list->head;
    Node *next;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

Node *getNode(DoublyLinkedList sll, int item)
{
    assert(!isEmpty(sll));
    Node *head = sll.head;
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
    if (!list1->head)
        list1->head->next = list2.head;
}

void splitByPosition(DoublyLinkedList list, int posiiton, DoublyLinkedList *firstHalf, DoublyLinkedList *secondHalf)
{
    Node *element = getNode(list, getItemByIndex(list, posiiton));
    if (element)
    {
        Node *listHelper = list.head;
        Node *firstHalfHelper = (firstHalf->head = listHelper);
        while (listHelper && listHelper->next->data != element->data) /*should not reach the element or the link will be destroyed after referencing the second half*/
        {
            listHelper = listHelper->next;
            firstHalfHelper->next = listHelper;
            firstHalfHelper = firstHalfHelper->next;
        }
        firstHalfHelper->next = NULL;
        secondHalf->head = element;
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
        {
            if (runner->next->data == current->data)
            {
                Node *duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            }
            else
                runner = runner->next;
        }
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