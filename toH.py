
function_info_list = [
    {
        "title": "Check if Queue is Empty",
        "func": """
int isEmpty(Queue queue)
{
    return queue.head == NULL && queue.tail == NULL;
}
""",
        "desc": "The `isEmpty` function checks if the queue is empty. It examines both the head and tail of the queue to determine if it contains any elements. A return value of 1 indicates an empty queue, while 0 indicates a non-empty queue. This function is used to verify the status of the queue."
    },
    {
        "title": "Remove and Return Front Item",
        "func": """
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
""",
        "desc": "The `pop` function removes and returns the front item from the queue. It ensures that the queue is not empty before attempting to remove an element. If the queue contains only one item, it deallocates the memory for that item. This function is essential for dequeuing items from the queue."
    },
    {
        "title": "Get Queue Size",
        "func": """
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
""",
        "desc": "The `size` function calculates and returns the number of elements in the queue. It iterates through the queue from the front to the end, counting the elements as it progresses. This function is used to determine the size or length of the queue."
    },
    {
        "title": "Display All Queue Items",
        "func": """
void showAllItems(Queue queue)
{
    /* ... (truncated for brevity) ... */
}
""",
        "desc": "The `showAllItems` function is responsible for displaying all items in the queue. While the code is truncated here, the function likely formats and prints the queue's contents for easy visualization. It is often used for debugging and understanding the queue's current state."
    },
    {
        "title": "Clear Queue",
        "func": """
void clear(Queue *queue)
{
    while (!isEmpty(*queue))
        pop(queue);
}
""",
        "desc": "The `clear` function removes all items from the queue, effectively emptying it. It continuously dequeues items from the front until the queue is empty. This function is useful when you want to reset or clean up the queue."
    },
    {
        "title": "Peek at Front Item",
        "func": """
int peek(Queue queue)
{
    assert(!isEmpty(queue));
    return queue.head->data;
}
""",
        "desc": "The `peek` function retrieves the value of the front item in the queue without removing it. It is important to check that the queue is not empty before using this function. This is commonly used to inspect the next item that will be dequeued."
    },
    {
        "title": "Search for Key in Queue",
        "func": """
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
""",
        "desc": "The `search` function looks for a specific key within the queue and returns its index if found. It starts from the front of the queue and moves towards the end, counting the items. If the key is located, its index is returned. This function helps identify the position of a particular item in the queue."
    },
    {
        "title": "Sort Queue",
        "func": """
void sort(Queue *queue, int key)
{
    /* ... (truncated for brevity) ... */
}
""",
        "desc": "The `sort` function arranges the elements in the queue in either ascending or descending order. The 'key' parameter determines the sorting direction, with 1 for ascending and -1 for descending. The function rearranges the queue to meet the specified order. Sorting is a common operation when managing data in a queue."
    },
    {
        "title": "Push Multiple Items to Queue",
        "func": """
void pushMany(Queue *queue, int numberOfItems, ...)
{
    // variadics macros
    va_list args;
    va_start(args, numberOfItems);
    for (int index = 0; index < numberOfItems; index++)
        push(queue, va_arg(args, int));
}
""",
        "desc": "The `pushMany` function allows multiple items to be pushed into the queue using variadic macros. It takes the 'numberOfItems' parameter to determine how many items to add. This function simplifies the process of adding multiple items to the queue simultaneously."
    },
    {
        "title": "Reverse Queue",
        "func": """
void reverse(Queue *queue)
{
    if (isEmpty(*queue))
        return;
    Node *head = pop(queue);
    reverse(queue);
    push(queue, head->data);
}
""",
        "desc": "The `reverse` function is responsible for reversing the order of items in the queue. It ensures that the queue is not empty before initiating the reversal process. This can be useful when the order of items in the queue needs to be inverted."
    },
    {
        "title": "Copy Queue",
        "func": """
Queue copy(Queue queue)
{
    assert(!isEmpty(queue));
    Queue copyQueue = createQueue();
    while (queue.head)
        push(&copyQueue, pop(&queue)->data);
    return copyQueue;
}
""",
        "desc": "The `copy` function creates a duplicate of the queue. It ensures that the original queue is not empty before copying its contents. The copied queue, 'copyQueue,' is returned as a new instance, allowing for independent manipulation of the copied data."
    },
    {
        "title": "Merge Queues",
        "func": """
Queue merge(Queue firstQueue, Queue secondQueue)
{
    Queue mergingQueue = createQueue();
    while (firstQueue.head)
        push(&mergingQueue, pop(&firstQueue)->data);
    while (secondQueue.head)
        push(&mergingQueue, pop(&secondQueue)->data);
    return mergingQueue;
}
""",
        "desc": "The `merge` function combines two queues, 'firstQueue' and 'secondQueue,' into a single new queue, 'mergingQueue.' It does so by dequeuing items from both input queues and adding them to the merging queue. The result is a unified queue containing all elements from both sources."
    }
]

with open('README.md','a') as fp:
    for idx, it in enumerate(function_info_list,3):
        fp.write(
            '''

**_{}. {}:_**

```c
{}
```

_{}_
'''.format(idx,it['title'],it['func'],it['desc'])
        )

