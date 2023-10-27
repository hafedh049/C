# STACK

_I. A stack is a last-in-first-out (LIFO) data structure. Elements can only be added to and removed from the top of the stack. Stacks are often used to implement undo/redo functionality, function calls, and expression evaluation._

**_1. Create stack:_**

```c
Stack createStack()
{
	Stack stack;
	stack.head = NULL;
	return stack;
}
```

_This createStack function creates and initializes an empty stack using a Stack structure and returns that empty stack. It is useful for initializing a stack before adding elements to it. After calling this function, you would have a stack ready for use._

**_2. Push item:_**

```c
void push(Stack *stack, int item)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = item;
	newNode->next = (*stack).head;
	(*stack).head = newNode;
}
```

_The push function takes a pointer to a Stack and an integer item. It dynamically allocates memory for a new Node, assigns the data value (item) to the new node, and updates the pointers to maintain the order of elements in the stack. After calling this function, the item will be added to the top of the stack represented by the Stack pointer provided as an argument._

**_3. Verify if the list is empty or not:_**

```c
int isEmpty(Stack stack)
{
	return stack.head == NULL;
}
```

_The isEmpty function takes a Stack as an argument and checks if the head pointer of the stack is NULL. If it's NULL, the function returns 1 to indicate that the stack is empty; otherwise, it returns 0 to indicate that the stack is not empty._

**_4. Delete an item:_**

```c
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
```

_The pop function removes the top element from the stack, returns its data, and deallocates the memory occupied by the removed element. It also includes a safety check to ensure that the stack is not empty before attempting to pop an element._

**_5. Size of a stack:_**

```c
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
```

_The size function calculates the size of a stack by iterating through the linked list of nodes (where each node represents an element in the stack) starting from the top (head) and counting each element until it reaches the end of the stack. The final count is returned as the size of the stack._

**_6. Show all items of a stack:_**

```c
void showAllItems(Stack stack)
{
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
```

_The showAllItems function displays the elements of a stack one by one, with each element's data enclosed in green bars and underscores for visual distinction. It uses ANSI escape codes to set text colors for various parts of the output and includes separators to visually separate sections of the output. If the stack is empty, it displays a message indicating that the stack is empty._

**_7. Clear a stack:_**

```c
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
```

_The clear function is used to clear a stack by iteratively removing all elements from the top of the stack and freeing the memory associated with each element. This ensures that the stack is empty and that there are no memory leaks caused by the removed elements._

**_8. Peek a stack:_**

```c
int peek(Stack stack)
{
	assert(!isEmpty(stack));
	return stack.head->data;
}
```

_The peek function is used to retrieve the data of the top element of a stack without removing it. It includes a safety check to ensure that the stack is not empty before attempting to peek, preventing potential errors caused by peeking at an empty stack._

**_9. Search an item in a stack:_**

```c
int search(Stack stack, int key)
{
	assert(!isEmpty(stack));
	int index = -1;
	int counter = 0;
	while (stack.head)
	{
		counter++;
		if (stack.head->data == key)
		{
			index = counter;
			break;
		}
		stack.head = stack.head->next;
	}
	return index;
}
```

_The search function searches for a specific element in a stack, keeps track of the position of the elements as it iterates through the stack, and returns the index of the first occurrence of the element or `-1` if the element is not found. It includes a safety check to ensure that the stack is not empty before performing the search._

**_10. Sort a stack:_**

```c
void sort(Stack *stack, int key)
{
	/* 1 : ASC ; -1 : DESC */
	assert(!isEmpty(*stack));
	Stack auxilaryStack = createStack();
	while ((*stack).head)
	{
		int stackItem = pop(stack)->data;
		while (!isEmpty(auxilaryStack) && (key == 1 ? peek(auxilaryStack) > stackItem : peek(auxilaryStack) < stackItem))
			push(stack, pop(&auxilaryStack)->data);
		push(&auxilaryStack, stackItem);
	}
	*stack = auxilaryStack;
}
```

_The sort function sorts the elements of a stack in either ascending or descending order based on the key parameter using an auxiliary stack. It maintains the desired order while transferring elements between the input stack and the auxiliary stack. After sorting is complete, the input stack is updated to contain the sorted elements._

**_11. Add many items in a stack:_**

```c
void pushMany(Stack *stack, int numberOfItems, ...)
{
	va_list args;
	va_start(args, numberOfItems);
	for (int index = 0; index < numberOfItems; index++)
		push(stack, va_arg(args, int));
}
```

_The pushMany function is a convenient way to push multiple integer values onto a stack in one function call. It uses variadic functions to accept a variable number of integer arguments and pushes each of them onto the specified stack. This can be useful when you need to add several values to the stack in a concise manner._

**_12. Reverse a stack:_**

```c
void reverse(Stack *stack)
{
	assert(!isEmpty(*stack));
	Stack auxilaryStack = createStack();
	while ((*stack).head)
		push(&auxilaryStack, pop(stack)->data);
	*stack = auxilaryStack;
}
```

_The reverse function reverses the order of elements in a stack by using an auxiliary stack to temporarily store the elements in reverse order. After the reversal, the original stack is updated to contain the reversed elements. This can be useful when you need to change the order of elements in a stack for various purposes._

**_13. Copy a stack:_**

```c
tack copy(Stack stack)
{
	assert(!isEmpty(stack));
	Stack auxilaryStack = createStack();
	Stack copyStack = createStack();
	while (stack.head)
		push(&auxilaryStack, pop(&stack)->data);
	while (auxilaryStack.head)
		push(&copyStack, pop(&auxilaryStack)->data);
	return copyStack;
}
```

_The copy function creates a copy of a given stack by first reversing the original stack into an auxiliary stack and then reversing it back into a new stack, ensuring that the copied stack retains the same order as the original. This can be useful when you need to work with a copy of the stack without modifying the original stack._

**_14. Merge two stacks into a single stack:_**

```c
Stack merge(Stack firstStack, Stack secondStack)
{
	Stack* mergingStack = createStack();

	for (const Node* node = secondStack.head; node; node = node->next)
	push(&mergingStack, node->data);

	while (firstStack.head)
	push(&mergingStack, pop(&firstStack)->data);

	return mergingStack;
}
```

_The merge function combines two input stacks into a single stack (mergingStack) by popping elements from both input stacks and pushing them onto the merged stack. The result is a new stack containing all the elements from both input stacks in the order they were originally in their respective stacks._

# QUEUE

_A queue is a first-in-first-out (FIFO) data structure. Elements are added to the end of the queue and removed from the front. Queues are often used to implement tasks that must be processed in order, such as printing jobs or tasks in a production line._

**_1. Create queue:_**

```c
Queue createQueue()
{
   Queue queue;
   queue.head = NULL;
   queue.tail = NULL;
   return queue;
}
```

_The function `Queue createQueue()` creates and initializes a new queue data structure. It allocates memory for a new Queue struct and initializes its head and tail pointers to `NULL`. This indicates that the queue is empty. The function then returns the new queue struct._

**_2. Push item:_**

```c
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
```

_The `push` function inserts an element into a queue data structure. It dynamically allocates memory for a new node, assigns the given item to it, and places it at the end of the queue while keeping track of both the front and rear of the queue._

**_3. Check if Queue is Empty:_**

```c

int isEmpty(Queue queue)
{
    return queue.head == NULL && queue.tail == NULL;
}

```

_The `isEmpty` function checks if the queue is empty. It examines both the head and tail of the queue to determine if it contains any elements. A return value of 1 indicates an empty queue, while 0 indicates a non-empty queue. This function is used to verify the status of the queue._

**_4. Remove and Return Front Item:_**

```c

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

```

_The `pop` function removes and returns the front item from the queue. It ensures that the queue is not empty before attempting to remove an element. If the queue contains only one item, it deallocates the memory for that item. This function is essential for dequeuing items from the queue._

**_5. Get Queue Size:_**

```c

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

```

_The `size` function calculates and returns the number of elements in the queue. It iterates through the queue from the front to the end, counting the elements as it progresses. This function is used to determine the size or length of the queue._

**_6. Display All Queue Items:_**

```c

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

```

_The `showAllItems` function is responsible for displaying all items in the queue. While the code is truncated here, the function likely formats and prints the queue's contents for easy visualization. It is often used for debugging and understanding the queue's current state._

**_7. Clear Queue:_**

```c

void clear(Queue *queue)
{
    while (!isEmpty(*queue))
        pop(queue);
}

```

_The `clear` function removes all items from the queue, effectively emptying it. It continuously dequeues items from the front until the queue is empty. This function is useful when you want to reset or clean up the queue._

**_8. Peek at Front Item:_**

```c

int peek(Queue queue)
{
    assert(!isEmpty(queue));
    return queue.head->data;
}

```

_The `peek` function retrieves the value of the front item in the queue without removing it. It is important to check that the queue is not empty before using this function. This is commonly used to inspect the next item that will be dequeued._

**_9. Search for Key in Queue:_**

```c
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
```

_The `search` function looks for a specific key within the queue and returns its index if found. It starts from the front of the queue and moves towards the end, counting the items. If the key is located, its index is returned. This function helps identify the position of a particular item in the queue._

**_10. Sort Queue:_**

```c

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
```

_The `sort` function arranges the elements in the queue in either ascending or descending order. The 'key' parameter determines the sorting direction, with 1 for ascending and -1 for descending. The function rearranges the queue to meet the specified order. Sorting is a common operation when managing data in a queue._

**_11. Push Multiple Items to Queue:_**

```c
void pushMany(Queue *queue, int numberOfItems, ...)
{
    // variadics macros
    va_list args;
    va_start(args, numberOfItems);
    for (int index = 0; index < numberOfItems; index++)
        push(queue, va_arg(args, int));
}
```

_The `pushMany` function allows multiple items to be pushed into the queue using variadic macros. It takes the 'numberOfItems' parameter to determine how many items to add. This function simplifies the process of adding multiple items to the queue simultaneously._

**_12. Reverse Queue:_**

```c

void reverse(Queue *queue)
{
    if (isEmpty(*queue))
        return;
    Node *head = pop(queue);
    reverse(queue);
    push(queue, head->data);
}

```

_The `reverse` function is responsible for reversing the order of items in the queue. It ensures that the queue is not empty before initiating the reversal process. This can be useful when the order of items in the queue needs to be inverted._

**_13. Copy Queue:_**

```c

Queue copy(Queue queue)
{
    assert(!isEmpty(queue));
    Queue copyQueue = createQueue();
    while (queue.head)
        push(&copyQueue, pop(&queue)->data);
    return copyQueue;
}

```

_The `copy` function creates a duplicate of the queue. It ensures that the original queue is not empty before copying its contents. The copied queue, 'copyQueue,' is returned as a new instance, allowing for independent manipulation of the copied data._

**_14. Merge Queues:_**

```c

Queue merge(Queue firstQueue, Queue secondQueue)
{
    Queue mergingQueue = createQueue();
    while (firstQueue.head)
        push(&mergingQueue, pop(&firstQueue)->data);
    while (secondQueue.head)
        push(&mergingQueue, pop(&secondQueue)->data);
    return mergingQueue;
}

```

_The `merge` function combines two queues, 'firstQueue' and 'secondQueue,' into a single new queue, 'mergingQueue.' It does so by dequeuing items from both input queues and adding them to the merging queue. The result is a unified queue containing all elements from both sources._

# QUEUE

_A queue is a first-in-first-out (FIFO) data structure. Elements are added to the end of the queue and removed from the front. Queues are often used to implement tasks that must be processed in order, such as printing jobs or tasks in a production line._
