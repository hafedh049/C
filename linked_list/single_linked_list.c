#include "single_linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>

SingleLinkedList createSingleLinkedList()
{
    SingleLinkedList linkedList;
    linkedList.head = NULL;
    return linkedList;
}

int isEmpty(SingleLinkedList list)
{
    return list.head == NULL;
}

void append(SingleLinkedList *list, int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    if (isEmpty(*list))
    {
        list->head = node;
    }
    else
    {
        Node *last = list->head;
        while (last->next)
            last = last->next;
        last->next = node;
    }
}

void appendAll(SingleLinkedList *list, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        append(list, va_arg(args, int));
}

void shiftAll(SingleLinkedList *list, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        shift(list, va_arg(args, int));
}

void shift(SingleLinkedList *list, int item)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = item;

    if (isEmpty(*list))
    {
        node->next = NULL;
        list->head = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
    }
}

void insertAfter(SingleLinkedList *list, Node *node, int item)
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
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("Element added Successfully");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("You entered an inexisting element from the linked list");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

void insertAllAfter(SingleLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertAfter(list, node, va_arg(args, int));
}

void insertBefore(SingleLinkedList *list, Node *node, int item)
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
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("Element added Successfully");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
    else
    {
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("You entered an inexisting element from the linked list");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
    }
}

void insertAllBefore(SingleLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertBefore(list, node, va_arg(args, int));
}

void showAllItems(SingleLinkedList singleLinkedList)
{
    printf("\033[1;33m\n\n---------------------------\n\n");

    if (isEmpty(singleLinkedList))
    {
        printf("This list is empty x(");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
        return;
    }
    Node *head = singleLinkedList.head;
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

int search(SingleLinkedList sll, int item)
{
    assert(!isEmpty(sll));
    Node* head = sll.head;
    while (head)
    {
        if (head->data == item)
            return 1;
        head = head->next;
    }
    return 0;
}

int popFirst(SingleLinkedList *sll)
{
    assert(!isEmpty(*sll));

    Node *head = sll->head;
    int result = head->data;
    sll->head = sll->head->next;
    free(head);
    return result;
}

int popLast(SingleLinkedList *sll)
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

int pop(SingleLinkedList *sll, int item)
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

int getFirst(SingleLinkedList sll){
    assert(!isEmpty(sll));
    return sll.head->data;
}

int getLast(SingleLinkedList sll){
    assert(!isEmpty(sll));
    Node* node = sll.head;
    while(node->next) node = node->next;
    return node->data;
}

int getSize(SingleLinkedList list,Node* head)
{
    if(isEmpty(list))
        return 0;
    if(head)
        return 1 + getSize(list,head->next);
}

int getItemByIndex(SingleLinkedList list,int index){  
    assert(!isEmpty(list));
    int counter = -1;
    Node* head = list.head;
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

void sort(SingleLinkedList *list,int left, int right){
    
}