#include "stack.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

Stack* createStack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    return stack;
}

void push(Stack *stack, int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = (*stack).head;
    (*stack).head = newNode;
}

int isEmpty(Stack stack)
{
    return stack.head == NULL;
}

Node *pop(Stack *stack)
{
    assert(!isEmpty(*stack));
    Node *headReference = (*stack).head;
    (*stack).head = (*stack).head->next;
    Node *popedNode = (Node *)malloc(sizeof(Node));
    popedNode->data = headReference->data;
    popedNode->next = NULL;
    free(headReference);
    return popedNode;
}
int size(Stack stack)
{
    int size = 0;
    Node *head = stack.head;
    while (head)
    {
        ++size;
        head = head->next;
    }
    return size;
}

void showAllItems(Stack stack)
{
    /*
        Black: 30
        Red: 31
        Green: 32
        Yellow: 33
        Blue: 34
        Magenta: 35
        Cyan: 36
        White: 37
        Reset: 0
        \033[1;<color code>m
    */
    printf("\033[1;33m\n\n---------------------------\n\n");

    if (isEmpty(stack))
    {
        printf("This stack is empty x(\n");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;37m");
        return;
    }
    const Node *head = stack.head;
    while (head)
    {
        printf("\033[1;32m| %d |\n__\n", head->data);
        head = head->next;
    }
    printf("\033[1;33m\n\n---------------------------\n\n");
    printf("\033[1;37m");
}

void clear(Stack *stack)
{
    Node *head;
    while ((*stack).head)
    {
        head = (*stack).head;
        (*stack).head = (*stack).head->next;
        free(head);
    }
}

int peek(Stack stack)
{
    assert(!isEmpty(stack));
    return stack.head->data;
}

int search(Stack stack, int key)
{
    assert(!isEmpty(stack));
    int index = -1;
    int counter = 0;
    while (stack.head)
    {
        counter++;
        if (stack.head->data == key)
            index = counter;
            break;
        stack.head = stack.head->next;
    }
    return index;
}

void sort(Stack *stack, int key)
{
    /*
        1 : ASC
        -1 : DESC
    */
    assert(!isEmpty(*stack));

    Stack* auxilaryStack = createStack();
    while ((*stack).head)
    {
        int stackItem = pop(stack)->data;
        while (!isEmpty(*auxilaryStack) && (key == 1 ? peek(*auxilaryStack) > stackItem : peek(*auxilaryStack) < stackItem))
            push(stack, pop(&auxilaryStack)->data);

        push(&auxilaryStack, stackItem);
    }
    stack = auxilaryStack;
}

// variadics macros
void pushMany(Stack *stack, int numberOfItems, ...)
{
    va_list args;
    va_start(args, numberOfItems);
    for (int index = 0; index < numberOfItems; index++)
        push(stack, va_arg(args, int));
}

void reverse(Stack *stack)
{
    assert(!isEmpty(*stack));
    Stack* auxilaryStack = createStack();
    while ((*stack).head)
        push(&auxilaryStack, pop(stack)->data);
    stack = auxilaryStack;
}

Stack* copy(Stack stack)
{
    assert(!isEmpty(stack));
    Stack* auxilaryStack = createStack();
    Stack* copyStack = createStack();
    while (stack.head)
        push(&auxilaryStack, pop(&stack)->data);
    while (auxilaryStack->head)
        push(&copyStack, pop(&auxilaryStack)->data);
    return copyStack;
}

Stack* merge(Stack firstStack, Stack secondStack)
{
    Stack* mergingStack = createStack();
    while (firstStack.head)
        push(&mergingStack, pop(&firstStack)->data);
    while (secondStack.head)
        push(&mergingStack, pop(&secondStack)->data);
    return mergingStack;
}