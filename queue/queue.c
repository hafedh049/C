#include "queue.h"

Queue createQueue()
{
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    return queue;
}

void push(Queue *queue, int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = item;
    newNode->next = NULL;
    if (isEmpty(*queue))
    {    
        (*queue).tail = newNode;
        (*queue).head = newNode;
    }
    else
    {
        (*queue).tail->next = newNode;
        (*queue).tail = newNode;
    }
}

int isEmpty(Queue queue)
{
    return queue.head == NULL && queue.tail == NULL;
}

Node *pop(Queue *queue)
{
    assert(!isEmpty(*queue));

    if ((*queue).head == (*queue).tail)
    {
        Node *popedNode = (Node *)malloc(sizeof(Node));
        popedNode->data = (*queue).head->data;
        popedNode->next = NULL;
        free((*queue).head);
        (*queue).head = NULL;
        (*queue).tail = NULL;
        return popedNode;
    }
    else
    {
        Node *headReference = (*queue).head;
        (*queue).head = (*queue).head->next;
        Node *popedNode = (Node *)malloc(sizeof(Node));
        popedNode->data = headReference->data;
        popedNode->next = NULL;
        free(headReference);
        return popedNode;
    }
}
int size(Queue queue)
{
    int size = 0;
    Node *head = queue.head;
    while (head)
    {
        ++size;
        head = head->next;
    }
    return size;
}

void showAllItems(Queue queue)
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

    if (isEmpty(queue))
    {
        printf("This queue is empty x(");
        printf("\033[1;33m\n\n---------------------------\n\n");
        printf("\033[1;0m");
        return;
    }
    const Node *head = queue.head;
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

void clear(Queue *queue)
{
    while (!isEmpty(*queue))
        pop(queue);
}

int peek(Queue queue)
{
    assert(!isEmpty(queue));
    return queue.head->data;
}

int search(Queue queue, int key)
{
    assert(!isEmpty(queue));
    int index = -1;
    int counter = 0;
    while (queue.head)
    {
        counter++;
        if (queue.head->data == key)
            index = counter;
            break;
        queue.head = queue.head->next;
    }
    return index;
}

void sort(Queue *queue, int key)
{
    /*
        1 : ASC
        -1 : DESC
    */
    assert(!isEmpty(*queue));

    Queue auxilaryQueue = createQueue();
    while ((*queue).head)
    {
        int queueItem = pop(queue)->data;
        while (!isEmpty(auxilaryQueue) && (key == 1 ? peek(auxilaryQueue) > queueItem : peek(auxilaryQueue) < queueItem))
            push(queue, pop(&auxilaryQueue)->data);

        push(&auxilaryQueue, queueItem);
    }
    free(queue);
    *queue = auxilaryQueue;
}

// variadics macro
void pushMany(Queue *queue, int numberOfItems, ...)
{
    va_list args;
    va_start(args, numberOfItems);
    for (int index = 0; index < numberOfItems; index++)
        push(queue, va_arg(args, int));
}

void reverse(Queue *queue)
{
    if (isEmpty(*queue))
        return;
    Node *head = pop(queue);
    reverse(queue);
    push(queue, head->data);
}

Queue copy(Queue queue)
{
    assert(!isEmpty(queue));
    Queue copyQueue = createQueue();
    while (queue.head)
        push(&copyQueue, pop(&queue)->data);
    return copyQueue;
}

Queue merge(Queue firstQueue, Queue secondQueue)
{
    Queue mergingQueue = createQueue();
    while (firstQueue.head)
        push(&mergingQueue, pop(&firstQueue)->data);
    while (secondQueue.head)
        push(&mergingQueue, pop(&secondQueue)->data);
    return mergingQueue;
}