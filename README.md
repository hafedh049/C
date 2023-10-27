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

# ARRAY

_An array is a data structure that stores a collection of elements of the same type. The elements are stored in contiguous memory locations, and each element is identified by a unique index. Arrays are one of the most fundamental and widely used data structures in computer programming._

**_1. Create an Array:_**

```c

Array *createArray()
{
    Array *arr = (Array *)malloc(sizeof(Array));
    arr->data = (int *)malloc(sizeof(int) * 0);
    arr->size = 0;
    arr->capacity = 0;
    return arr;
}

```

_The `createArray` function initializes an empty array. It allocates memory for the array structure and sets its size, capacity, and data array. This function is essential for creating a new array for data storage._


**_2. Push Element:_**

```c

void push(Array *arr, int element)
{
    if (arr->size >= arr->capacity)
    {
        arr->capacity += 1;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    arr->data[arr->size] = element;
    arr->size++;
}

```

_The `push` function adds an element to the end of the array. If the array is full and needs to grow, it dynamically reallocates memory to accommodate the new element. This is a fundamental operation for appending data to the array._


**_3. Pop Element:_**

```c

int pop(Array *arr)
{
    if (arr->size == 0)
        return -1;

    int element = arr->data[arr->size - 1];
    arr->size--;

    free(&arr->data[arr->size]);

    if (arr->size < arr->capacity - 1)
    {
        arr->capacity--;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    return element;
}

```

_The `pop` function removes and returns the last element from the array. It verifies that the array is not empty and deallocates memory for the removed element if necessary. Popping an element is crucial for reducing the array's size._


**_4. Get Element by Index:_**

```c

int get(Array *arr, int index)
{
    if (index < 0 || index >= arr->size)
        return -1;

    return arr->data[index];
}

```

_The `get` function retrieves the element at a specified index in the array. It checks that the index is within the valid range and returns the element's value if found. This function is essential for accessing individual elements by their position._


**_5. Set Element by Index:_**

```c

void set(Array *arr, int index, int element)
{
    if (index < 0 || index >= arr->size)
        return;

    arr->data[index] = element;
}

```

_The `set` function updates an element at a specified index in the array with a new value. It validates that the index is within the valid range before performing the update. This operation is crucial for modifying individual elements._


**_6. Find Index of Element:_**

```c

int indexOf(Array *arr, int element)
{
    for (int i = 0; i < arr->size; i++)
        if (arr->data[i] == element)
            return i;

    return -1;
}

```

_The `indexOf` function searches for an element in the array and returns its index if found. It iterates through the array, comparing elements to the target value and returning the index when a match is detected. This function helps locate elements within the array._


**_7. Remove Element by Index:_**

```c

void removeAt(Array *arr, int index)
{
    if (index < 0 || index >= arr->size)
        return;

    free(&arr->data[index]);

    for (int i = index; i < arr->size - 1; i++)
        arr->data[i] = arr->data[i + 1];

    arr->size--;

    if (arr->size < arr->capacity - 1)
    {
        arr->capacity--;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}

```

_The `removeAt` function removes an element from the array by a specified index. It ensures that the index is valid and deallocates memory for the removed element. The function then shifts the remaining elements to fill the gap and updates the array's size and capacity._


**_8. Free Array:_**

```c

void freeArray(Array *arr)
{
    free(arr->data);
    free(arr);
}

```

_The `freeArray` function releases all memory associated with an array, including its data array and the array structure itself. It is used to clean up and release resources when the array is no longer needed._


**_9. Insert Element at Index:_**

```c

void insert(Array *arr, int index, int element)
{
    if (index < 0 || index > arr->size)
        return;

    if (arr->size >= arr->capacity)
    {
        arr->capacity++;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }

    for (int i = arr->size; i > index; i--)
        arr->data[i] = arr->data[i - 1];

    arr->data[index] = element;
    arr->size++;
}

```

_The `insert` function adds an element at a specified index in the array, pushing the existing elements further down. It validates the index's validity and ensures there is enough capacity to accommodate the new element. This operation allows for precise element placement within the array._


**_10. Slice Array:_**

```c

Array *slice(Array *arr, int start, int end)
{
    if (start < 0)
        start = 0;

    if (end >= arr->size)
        end = arr->size - 1;

    if (start > end)
        return NULL;

    // Its size = end - start + 1
    Array *slicedArr = createArray();
    for (int i = start; i <= end; i++)
        push(slicedArr, arr->data[i]);

    return slicedArr;
}

```

_The `slice` function extracts a portion of the array, specified by the 'start' and 'end' indices, creating a new array with the selected elements. It handles boundary conditions and allows for isolating specific elements or subarrays within the original array._


**_11. Concatenate Arrays:_**

```c

void concat(Array *arr1, Array *arr2)
{
    for (int i = 0; i < arr2->size; i++)
        push(arr1, arr2->data[i]);
}

```

_The `concat` function combines the elements of 'arr2' into 'arr1,' effectively extending 'arr1' with the contents of 'arr2.' This operation is useful for merging the data of two arrays into one._


**_12. Sort Array (Insertion Sort):_**

```c

void sort(Array *arr)
{
    for (int i = 1; i < arr->size; i++)
    {
        int key = arr->data[i];
        int j = i - 1;
        while (j >= 0 && arr->data[j] > key)
        {
            arr->data[j + 1] = arr->data[j];
            j--;
        }
        arr->data[j + 1] = key;
    }
}

```

_The `sort` function arranges the elements in the array in ascending order using the insertion sort algorithm. It iterates through the array, repeatedly selecting an element and inserting it into the correct position among the sorted elements. This operation is essential for sorting the array's elements._


**_13. Reverse Array (In-Place):_**

```c

void reverse(Array *arr)
{
    int left = 0;
    int right = arr->size - 1;
    while (left < right)
    {
        int temp = arr->data[left];
        arr->data[left] = arr->data[right];
        arr->data[right] = temp;
        left++;
        right--;
    }
}

```

_The `reverse` function inverts the order of elements in the array in-place, without allocating extra memory. It swaps the positions of elements from the beginning and end of the array until it reaches the middle, effectively reversing the sequence of elements._


**_14. Clear Array:_**

```c

void clear(Array *arr)
{
    for (int i = 0; i < arr->size; i++)
        free(&arr->data[i]);
    arr->size = 0;
    arr->capacity = 0;
}

```

_The `clear` function removes all elements from the array and resets its size and capacity to zero. Additionally, it deallocates memory for each element. This operation is vital for emptying and reusing the array._


**_15. Last Index of Element:_**

```c

int lastIndexOf(Array *arr, int element)
{
    for (int i = arr->size - 1; i >= 0; i--)
        if (arr->data[i] == element)
            return i;
    return -1;
}

```

_The `lastIndexOf` function searches for an element in the array from the end to the beginning, returning the index of the last occurrence. It is useful for locating the most recent occurrence of an element within the array._


**_16. Check If Array Contains Element:_**

```c

int contains(Array *arr, int element)
{
    return indexOf(arr, element) != -1;
}

```

_The `contains` function checks if a specific element is present in the array. It leverages the `indexOf` function to determine whether the element exists in the array and returns a boolean result. This operation is used to test the presence of an element._


**_17. Copy Array:_**

```c
Array *copy(Array *arr)
{
    Array *copyArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
        push(copyArr, arr->data[i]);
    return copyArr;
}
```

_The `copy` function creates a new array and copies the elements from the source array into the new array, effectively creating a clone of the original array._


**_18. Is Empty:_**

```c
int isEmpty(Array *arr)
{
    return arr->size == 0;
}
```

_The `isEmpty` function checks if the given array is empty, returning `1` if it is empty and `0` if it contains elements._


**_19. Size:_**

```c
int size(Array *arr)
{
    return arr->size;
}
```

_The `size` function returns the number of elements in the array, which represents its current size._


**_20. Capacity:_**

```c
int capacity(Array *arr)
{
    return arr->capacity;
}
```

_The `capacity` function returns the capacity of the array, which represents the maximum number of elements it can hold without resizing._


**_21. Trim to Size:_**

```c
void trimToSize(Array *arr)
{
    if (arr->size < arr->capacity)
    {
        arr->capacity = arr->size;
        arr->data = (int *)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}
```

_The `trimToSize` function adjusts the capacity of the array to match its current size, potentially reducing memory consumption._


**_22. Reversed Array:_**

```c
Array *reversedArray(Array *arr)
{
    Array *reversedArr = createArray(arr->size);
    for (int i = arr->size - 1; i >= 0; i--)
        push(reversedArr, arr->data[i]);
    return reversedArr;
}
```

_The `reversedArray` function creates a new array with elements in the reverse order of the source array._


**_23. Concatenate Arrays:_**

```c
Array *concatenate(Array *arr1, Array *arr2)
{
    Array *concatenatedArr = createArray(arr1->size + arr2->size);
    for (int i = 0; i < arr1->size; i++)
        push(concatenatedArr, arr1->data[i]);
    for (int i = 0; i < arr2->size; i++)
        push(concatenatedArr, arr2->data[i]);
    return concatenatedArr;
}
```

_The `concatenate` function combines two arrays into a single array, preserving the order of elements from both arrays._


**_24. Bubble Sort:_**

```c
void bubbleSort(Array *arr)
{
    for (int i = 0; i < arr->size - 1; i++)
        for (int j = 0; j < arr->size - i - 1; j++)
            if (arr->data[j] > arr->data[j + 1])
            {
                int temp = arr->data[j];
                arr->data[j] = arr->data[j + 1];
                arr->data[j + 1] = temp;
            }
}
```

_The `bubbleSort` function sorts the elements of the array in ascending order using the bubble sort algorithm._


**_25. Binary Search:_**

```c
int binarySearch(Array *arr, int target)
{
    int left = 0;
    int right = arr->size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr->data[mid] == target)
            return mid;
        if (arr->data[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```

_The `binarySearch` function searches for a target element in a sorted array using the binary search algorithm and returns the index of the target element if found, or -1 if not found._


**_26. Unique Elements:_**

```c
Array *unique(Array *arr)
{
    Array *uniqueArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (!contains(uniqueArr, element))
            push(uniqueArr, element);
    }
    return uniqueArr;
}
```

_The `unique` function creates a new array containing only the unique elements from the source array, removing any duplicates._


**_27. Map Function:_**

```c
Array *map(Array *arr, int (*function)(int))
{
    Array *mappedArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int result = function(arr->data[i]);
        push(mappedArr, result);
    }
    return mappedArr;
}
```

_The `map` function applies a given function to each element of the array, creating a new array with the results of the function for each element._


**_28. Filter Function:_**

```c
Array *filter(Array *arr, int (*condition)(int))
{
    Array *filteredArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (condition(element))
            push(filteredArr, element);
    }
    return filteredArr;
}
```

_The `filter` function creates a new array containing only the elements that satisfy a specified condition, as determined by a provided function._


**_29. Reduce Function:_**

```c
int reduce(Array *arr, int (*function)(int, int), int initial)
{
    int result = initial;
    for (int i = 0; i < arr->size; i++)
        result = function(result, arr->data[i]);
    return result;
}
```

_The `reduce` function combines all elements of the array into a single value using a specified function and an initial value. It returns the final accumulated result._


**_30. For Each:_**

```c
void forEach(Array *arr, void (*function)(int))
{
    for (int i = 0; i < arr->size; i++)
        function(arr->data[i]);
}
```

_The `forEach` function applies a provided function to each element of the array, allowing you to perform an operation on each element without changing the array itself._


**_31. Find Element:_**

```c
int find(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
    {
        int element = arr->data[i];
        if (condition(element))
            return element;
    }
    return -1;
}
```

_The `find` function searches for an element in the array that satisfies a specified condition, returning the element if found or -1 if not found._


**_32. Some Elements:_**

```c
int some(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
        if (condition(arr->data[i]))
            return 1;
    return 0;
}
```

_The `some` function checks if at least one element in the array satisfies a specified condition, returning 1 if any element matches, and 0 if none do._


**_33. Every Element:_**

```c
int every(Array *arr, int (*condition)(int))
{
    for (int i = 0; i < arr->size; i++)
        if (!condition(arr->data[i]))
            return 0;
    return 1;
}
```

_The `every` function checks if every element in the array satisfies a specified condition, returning 1 if all elements match the condition, and 0 if any do not._


**_34. Maximum Element:_**

```c
int maximum(Array *arr)
{
    int maximum = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        if (arr->data[i] > maximum)
            maximum = arr->data[i];
    return maximum;
}
```

_The `maximum` function finds and returns the maximum element in the array._


**_35. Minimum Element:_**

```c
int minimum(Array *arr)
{
    int minimum = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        if (arr->data[i] < minimum)
            minimum = arr->data[i];
    return minimum;
}
```

_The `minimum` function finds and returns the minimum element in the array._


**_36. Rotate Left:_**

```c
void rotateLeft(Array *arr, int positions)
{
    if (positions < 0)
        positions = positions + arr->size;
    positions = positions % arr->size;
    Array *tempArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int newPosition = (i + positions) % arr->size;
        tempArr->data[newPosition] = arr->data[i];
    }
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = tempArr->data[i];
    freeArray(tempArr);
}
```

_The `rotateLeft` function rotates the elements of the array to the left by a specified number of positions._


**_37. Rotate Right:_**

```c
void rotateRight(Array *arr, int positions)
{
    if (positions < 0)
        positions = positions + arr->size;
    positions = positions % arr->size;
    Array *tempArr = createArray(arr->size);
    for (int i = 0; i < arr->size; i++)
    {
        int newPosition = (i - positions + arr->size) % arr->size;
        tempArr->data[newPosition] = arr->data[i];
    }
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = tempArr->data[i];
    freeArray(tempArr);
}
```

_The `rotateRight` function rotates the elements of the array to the right by a specified number of positions._


**_38. Shuffle Array:_**

```c
void shuffle(Array* arr) {
    srand(time(NULL));
    for (int i = arr->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr->data[i];
        arr->data[i] = arr->data[j];
        arr->data[j] = temp;
    }
}
```

_The `shuffle` function shuffles the elements of the array randomly, creating a new arrangement of elements._


**_39. Swap Elements:_**

```c
void swap(Array* arr, int index1, int index2) {
    if (index1 >= 0 && index1 < arr->size && index2 >= 0 && index2 < arr->size) {
        int temp = arr->data[index1];
        arr->data[index1] = arr->data[index2];
        arr->data[index2] = temp;
    }
}
```

_The `swap` function exchanges the positions of two elements in the array based on their indices._


**_40. Fill Array:_**

```c
void fill(Array* arr, int value) {
    for (int i = 0; i < arr->size; i++)
        arr->data[i] = value;
}
```

_The `fill` function sets all elements in the array to a specified value._


**_41. Quick Sort (Ascending):_**

```c
void qqsort(Array* arr) {
    qsort(arr->data, arr->size, sizeof(int), compareAscending);
}
```

_The `qqsort` function sorts the elements of the array in ascending order using the Quick Sort algorithm._


**_42. Join Array:_**

```c
char* join(Array* arr, const char* delimiter) {
    int resultLength = 1;
    for (int i = 0; i < arr->size; i++) {
        int element = arr->data[i];
        int digits = element == 0 ? 1 : (int)(log10(abs(element)) + 1);
        resultLength += digits + (i < arr->size - 1 ? strlen(delimiter) : 0);
    }
    char* result = (char*)malloc(resultLength);
    result[0] = '\0';
    for (int i = 0; i < arr->size; i++) {
        const int MAX_STRING_LENGTH = (int)(log10(abs(arr->data[i])) + 1);
        char *elementAsString = (char*)malloc(sizeof(char) * MAX_STRING_LENGTH);
        snprintf(elementAsString, MAX_STRING_LENGTH, "%d", arr->data[i]);
        strcat(result, elementAsString);
        if (i < arr->size - 1)
            strcat(result, delimiter);
        free(elementAsString);
        resultLength = strlen(result) + 1;
        result = (char*)realloc(result, resultLength + 1);
    }
    return result;
}
```

_The `join` function combines the elements of the array into a string, separating them with a specified delimiter._


**_43. Shift Element:_**

```c
int shift(Array* arr) {
    if (arr->size == 0)
        return -1;
    int element = arr->data[0];
    for (int i = 1; i < arr->size; i++)
        arr->data[i - 1] = arr->data[i];
    arr->size--;
    if (arr->size < arr->capacity - 1) {
        arr->capacity -= 1;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    return element;
}
```

_The `shift` function removes and returns the first element of the array, reducing the array size by one._


**_44. Unshift Element:_**

```c
void unshift(Array* arr, int element) {
    if (arr->size >= arr->capacity) {
        arr->capacity++;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
    for (int i = arr->size; i > 0; i--)
        arr->data[i] = arr->data[i - 1];
    arr->data[0] = element;
    arr->size++;
    if (arr->size == arr->capacity) {
        arr->capacity++;
        arr->data = (int*)realloc(arr->data, sizeof(int) * arr->capacity);
    }
}
```

_The `unshift` function adds an element to the beginning of the array, expanding the array if needed._


**_45. Average:_**

```c
double average(Array* arr) {
    if (arr->size == 0)
        return 0.0;
    return (double)sum(arr) / arr->size;
}
```

_The `average` function calculates the average value of the elements in the array._


**_46. Sum:_**

```c
int sum(Array* arr) {
    int result = 0;
    for (int i = 0; i < arr->size; i++)
        result += arr->data[i];
    return result;
}
```

_The `sum` function calculates the sum of all elements in the array._


**_47. Search with Criteria:_**

```c
int searchWithCriteria(Array* arr, int (*criteria)(int)) {
    for (int i = 0; i < arr->size; i++) {
        if (criteria(arr->data[i]))
            return arr->data[i];
    }
    return -1;
}
```

_The `searchWithCriteria` function searches for an element in the array that satisfies a specified criteria function, returning the element if found or -1 if not found._


**_48. Array to String:_**

```c
void toString(Array* arr) {
    printf("[");
    for (int i = 0; i < arr->size; i++) {
        printf("%d", arr->data[i]);
        if (i != arr->size - 1) 
            printf(", ");
    }
    printf("]\n");
}
```

_The `toString` function prints the elements of the array as a string in the format '[element1, element2, ...]'._


**_49. Push Multiple Elements:_**

```c
void pushMany(Array* arr, int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int item = va_arg(args, int);
        push(arr, item);
    }
    va_end(args);
}
```

_The `pushMany` function appends multiple elements to the end of the array._


**_50. Remove All Occurrences of Element:_**

```c
void removeAll(Array* arr, int element) {
    int newSize = 0;
    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] != element) {
            arr->data[newSize] = arr->data[i];
            newSize++;
        }
    }
    arr->size = newSize;
}
```

_The `removeAll` function removes all occurrences of a specific element from the array, compacting the array in the process._


**_51. Remove All Occurrences of Multiple Elements:_**

```c
void removeAllMany(Array* arr, int numIndices, ...) {
    va_list args;
    va_start(args, numIndices);
    for (int i = 0; i < numIndices; i++) {
        int index = va_arg(args, int);
        if (index >= 0 && index < arr->size)
            removeAll(arr, arr->data[index]);
    }
    va_end(args);
}
```

_The `removeAllMany` function removes all occurrences of multiple elements based on their indices from the array, compacting the array in the process._

# BINARY TREE

_A binary tree is a tree data structure in which each node has at most two children, referred to as the left child and the right child. That is, it is a k-ary tree with k = 2. A recursive definition using set theory is that a binary tree is a tuple (L, S, R), where L and R are binary trees or the empty set and S is a singleton set containing the root._

**_1. Inorder Traversal:_**

```c
void inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
    inorderTraversal(root->right);
}
```

_The `inorderTraversal` function performs an inorder traversal of a binary tree and prints the elements in ascending order._


**_2. Preorder Traversal:_**

```c
void preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
```

_The `preorderTraversal` function performs a preorder traversal of a binary tree and prints the elements as it encounters them._


**_3. Postorder Traversal:_**

```c
void postorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("\e[1;32m%d \e[1;33m-> \e[0m", root->data);
}
```

_The `postorderTraversal` function performs a postorder traversal of a binary tree and prints the elements after visiting all child nodes._


**_4. Create Node:_**

```c
TreeNode *createNode(int value)
{
    struct TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
```

_The `createNode` function creates a new tree node with the specified value._


**_5. Insert Node:_**

```c
void insert(TreeNode **root, int value)
{
    if (!(*root))
    {
        TreeNode *tmp = NULL;
        tmp = (TreeNode *)malloc(sizeof(TreeNode));
        tmp->left = tmp->right = NULL;
        tmp->data = value;
        *root = tmp;
        return;
    }
    if (value < (*root)->data)
        insert(&((*root)->left), value);
    else if (value > (*root)->data)
        insert(&((*root)->right), value);
}
```

_The `insert` function inserts a new node with the specified value into the binary tree._


**_6. Search Node:_**

```c
TreeNode *search(TreeNode *root, int value)
{
    if (!(root))
        return NULL;
    if (value == root->data)
        return root;
    else if (value < root->data)
        search(root->left, value);
    else if (value > root->data)
        search(root->right, value);
}
```

_The `search` function searches for a node with the specified value in the binary tree and returns the node if found._


**_7. Delete Tree:_**

```c
void delete_tree(TreeNode **root)
{
    if (*root)
    {
        delete_tree(&(*root)->left);
        delete_tree(&(*root)->right);
        free((*root));
    }
}
```

_The `delete_tree` function recursively deletes all nodes in the binary tree, freeing memory._


**_8. Find Minimum Value Node:_**

```c
TreeNode *findMinValueNode(TreeNode *node)
{
    if (node == NULL)
        return NULL;
    while (node->left != NULL)
        node = node->left;
    return node;
}
```

_The `findMinValueNode` function finds the node with the minimum value in the binary tree._


**_9. Delete Node:_**

```c
void deleteNode(TreeNode **root, int key)
{
    if (*root == NULL)
        return;
    if (key < (*root)->data)
        deleteNode(&((*root)->left), key);
    else if (key > (*root)->data)
        deleteNode(&((*root)->right), key);
    else
    {
        if ((*root)->left == NULL)
        {
            TreeNode *temp = (*root)->right;
            free(*root);
            *root = temp;
        }
        else if ((*root)->right == NULL)
        {
            TreeNode *temp = (*root)->left;
            free(*root);
            *root = temp;
        }
        else
        {
            TreeNode *temp = findMinValueNode((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&((*root)->right), temp->data);
        }
    }
}
```

_The `deleteNode` function deletes a node with the specified key from the binary tree._


**_10. Print Tree:_**

```c
void printTree(TreeNode* root, int space)
{
    if (root == NULL) return;
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++)
        printf(" ");
    printf("\e[1;32m%d\e[0m", root->data);
    printTree(root->left, space);
}
```

_The `printTree` function prints the binary tree with proper indentation._


**_11. Count Elements:_**

```c
int countElements(TreeNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + countElements(root->left) + countElements(root->right);
}
```

_The `countElements` function counts the total number of elements in the binary tree._


**_12. Count Left Subtree Elements:_**

```c
int countLeftSubtreeElements(TreeNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + countLeftSubtreeElements(root->left);
}
```

_The `countLeftSubtreeElements` function counts the number of elements in the left subtree of the binary tree._


**_13. Count Right Subtree Elements:_**

```c
int countRightSubtreeElements(TreeNode* root)
{
    if (root == NULL)
        return 0;
    return 1 + countRightSubtreeElements(root->right);
}
```

_The `countRightSubtreeElements` function counts the number of elements in the right subtree of the binary tree._

# CIRCULAR LINKED LIST

_A circular linked list is a type of linked list in which the last node points to the first node, forming a loop. This makes it different from traditional linked lists, which have a beginning and an end._

**_1. Create Circular Linked List:_**

```c
CircularLinkedList *createCircularLinkedList()
{
  CircularLinkedList *list = malloc(sizeof(CircularLinkedList));
  list->head = NULL;
  return list;
}
```

_The `createCircularLinkedList` function initializes and returns an empty Circular Linked List._


**_2. Insert Node at Head:_**

```c
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
    Node *temp = list->head;
    while (temp->next != list->head)
      temp = temp->next;
    temp->next = newNode;
    list->head = newNode;
  }
}
```

_The `insertAtHead` function inserts a new node with the specified data at the beginning of the Circular Linked List._


**_3. Insert Node at Tail:_**

```c
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
      current = current->next;

    current->next = newNode;
    newNode->next = list->head;
  }
}
```

_The `insertAtTail` function inserts a new node with the specified data at the end of the Circular Linked List._


**_4. Show All Items:_**

```c
void showAllItems(CircularLinkedList list)
{
  printf("\033[1;33m\n");

  if (isEmpty(&list))
  {
    printf("This list is empty x(");
    printf("\033[1;0m");
    return;
  }
  Node *head = list.head;
  do
  {
    if (head->next != list.head)
      printf("\033[1;32m| %d | -> ", head->data);
    else
      printf("\033[1;32m| %d |", head->data);
    head = head->next;
  } while (head != list.head);
  printf("\n\033[1;0m");
}
```

_The `showAllItems` function displays all items in the Circular Linked List._


**_5. Is Empty:_**

```c
int isEmpty(CircularLinkedList *cl)
{
  return cl->head == NULL;
}
```

_The `isEmpty` function checks if the Circular Linked List is empty and returns 1 if it is, 0 otherwise._


**_6. Delete Node at Head:_**

```c
int deleteAtHead(CircularLinkedList *list)
{
  if (list->head == NULL)
    return -1;

  int data = list->head->data;
  Node *temp = list->head;

  if (list->head == list->head->next)
    list->head = NULL;
  else
  {
    list->head = list->head->next;
    Node *last = list->head;
    while (last->next != temp)
      last = last->next;
    last->next = list->head;
  }

  free(temp);
  return data;
}
```

_The `deleteAtHead` function removes and returns the node at the head of the Circular Linked List._


**_7. Delete Node at Tail:_**

```c
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
```

_The `deleteAtTail` function removes and returns the node at the tail of the Circular Linked List._


**_8. Search:_**

```c
int search(CircularLinkedList *list, int element)
{
  Node *current = list->head;
  if (current == NULL)
    return -1;

  do
  {
    if (current->data == element)
      return element;
    current = current->next;
  } while (current != list->head);

  return -1;
}
```

_The `search` function searches for a specified element in the Circular Linked List and returns it if found._


**_9. Get Length:_**

```c
int getLength(CircularLinkedList *list)
{
  int length = 0;
  const Node *current = list->head;

  if (current == NULL)
    return 0;

  do
  {
    length++;
    current = current->next;
  } while (current != list->head);

  return length - 1;
}
```

_The `getLength` function returns the length (number of nodes) of the Circular Linked List._


**_10. Reverse:_**

```c
void reverse(CircularLinkedList *list)
{
  Node *current = list->head;
  Node *prev = NULL;
  Node *next = NULL;

  if (current == NULL)
    return;

  do
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  } while (current != list->head);

  list->head = prev;
}
```

_The `reverse` function reverses the order of nodes in the Circular Linked List._


**_11. Rotate:_**

```c
void rotate(CircularLinkedList *list, int k)
{
  if (list->head == NULL || k <= 0)
    return;

  Node *current = list->head;
  int i = 0;

  while (i < k - 1 && current->next != list->head)
  {
    current = current->next;
    i++;
  }

  if (current->next == list->head)
    return;

  list->head = current->next;
}
```

_The `rotate` function rotates the Circular Linked List by k positions._


**_12. Find Middle Element:_**

```c
Node *findMiddleElement(CircularLinkedList *list)
{
  if (list->head == NULL)
    return NULL;

  Node *tortoise = list->head;
  Node *hare = list->head;

  while (hare->next != list->head && hare->next != list->head)
  {
    tortoise = tortoise->next;
    hare = hare->next->next;
  }

  return tortoise;
}
```

_The `findMiddleElement` function returns the middle node of the Circular Linked List._


**_13. Find Kth Element:_**

```c
Node *findKthElement(CircularLinkedList *list, int k)
{
  int i = 0;
  Node *current = list->head;

  while (i < k && current->next != list->head)
  {
    current = current->next;
    i++;
  }

  if (current == list->head)
    return NULL;

  return current;
}
```

_The `findKthElement` function returns the kth node of the Circular Linked List._


**_14. Merge Circular Linked Lists:_**

```c
CircularLinkedList *mergeCircularLinkedLists(CircularLinkedList *list1, CircularLinkedList *list2)
{
  CircularLinkedList *mergedList = createCircularLinkedList();

  if (list1->head == NULL)
    mergedList->head = list2->head;
  else if (list2->head == NULL)
    mergedList->head = list1->head;
  else
  {
    Node *endList1 = list1->head;
    while (endList1->next != list1->head)
      endList1 = endList1->next;

    endList1->next = list2->head;

    Node *endList2 = list2->head;
    while (endList2->next != list2->head)
      endList2 = endList2->next;

    endList2->next = list1->head;

    mergedList->head = list1->head;
  }

  return mergedList;
}
```

_The `mergeCircularLinkedLists` function merges two Circular Linked Lists into a new one._


**_15. Is Palindrome:_**

```c
int isPalindrome(CircularLinkedList *list)
{
  if (list->head == NULL)
  {
    return 1; // An empty list is considered a palindrome
  }

  CircularLinkedList reversedList;
  reversedList.head = NULL;
  Node *current = list->head;

  do
  {
    insertAtHead(&reversedList, current->data);
    current = current->next;
  } while (current != list->head);

  current = list->head;
  Node *reversedCurrent = reversedList.head;

  do
  {
    if (current->data != reversedCurrent->data)
    {
      return 0;
    }
    current = current->next;
    reversedCurrent = reversedCurrent->next;
  } while (current != list->head);

  return 1;
}
```

_The `isPalindrome` function checks if the Circular Linked List is a palindrome and returns 1 if it is, 0 otherwise._


**_16. Delete Node at Position:_**

```c
void deleteNodeAtPosition(CircularLinkedList *list, int position)
{
  if (list->head == NULL || position < 0 || position >= getLength(list))
    return;

  Node *current = list->head;
  Node *previous = NULL;
  int currentPosition = 0;

  while (currentPosition != position)
  {
    previous = current;
    current = current->next;
    currentPosition++;

    if (current == list->head)
      break;
  }

  if (position == 0)
  {
    Node *tail = list->head;
    while (tail->next != list->head)
      tail = tail->next;
    list->head = current->next;
    tail->next = list->head;
  }
  else
    previous->next = current->next;

  free(current);
}
```

_The `deleteNodeAtPosition` function removes the node at the specified position in the Circular Linked List._


**_17. Insert Node After Node:_**

```c
void insertNodeAfterNode(CircularLinkedList *list, Node *node, int data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = node->next;

  node->next = newNode;
}
```

_The `insertNodeAfterNode` function inserts a new node with the specified data after a given node._


**_18. Find First Occurrence:_**

```c
int findFirstOccurrence(CircularLinkedList *list, int element)
{
  int position = 0;
  Node *current = list->head;

  do
  {
    if (current->data == element)
      return position;

    position++;
    current = current->next;
  } while (current != list->head);

  return -1;
}
```

_The `findFirstOccurrence` function finds the position of the first occurrence of a specified element in the Circular Linked List._


**_19. Find Last Occurrence:_**

```c
int findLastOccurrence(CircularLinkedList *list, int element)
{
  int position = 0;
  int length = getLength(list);
  Node *current = list->head;

  int lastPosition = -1;

  while (current != list->head)
  {
    if (current->data == element)
      lastPosition = position;

    position++;
    current = current->next;
  }

  if (lastPosition != -1)
    lastPosition = length - 1 - lastPosition;

  return lastPosition;
}
```

_The `findLastOccurrence` function finds the position of the last occurrence of a specified element in the Circular Linked List._


**_20. Has Cycle:_**

```c
int hasCycle(CircularLinkedList *list)
{
  Node *fast = list->head;
  Node *slow = list->head;

  while (fast != NULL && fast->next != NULL)
  {
    fast = fast->next->next;
    slow = slow->next;

    if (fast == slow)
      return 1;
  }

  return 0;
}
```

_The `hasCycle` function checks if the Circular Linked List contains a cycle and returns 1 if it does, 0 otherwise._


**_21. Split Circular Linked List:_**

```c
CircularLinkedList **splitCircularLinkedList(CircularLinkedList *list)
{
  CircularLinkedList *firstHalf = createCircularLinkedList();
  CircularLinkedList *secondHalf = createCircularLinkedList();

  Node *middleNode = findMiddleElement(list);

  if (middleNode == NULL || middleNode->next == list->head)
  {
    CircularLinkedList **halves = malloc(sizeof(CircularLinkedList *) * 2);
    halves[0] = firstHalf;
    halves[1] = secondHalf;
    return halves;
  }

  firstHalf->head = list->head;
  secondHalf->head = middleNode->next;
  middleNode->next = list->head;

  CircularLinkedList **halves = malloc(sizeof(CircularLinkedList *) * 2);
  halves[0] = firstHalf;
  halves[1] = secondHalf;

  return halves;
}
```

_The `splitCircularLinkedList` function splits a Circular Linked List into two halves and returns an array of the two halves._


**_22. Find Maximum Element:_**

```c
int findMaximumElement(CircularLinkedList *list)
{
  if (list->head == NULL)
    return -1;

  int maximumElement = list->head->data;
  Node *current = list->head->next;

  if (list->head != current)
    while (current != list->head)
    {
      if (current->data > maximumElement)
        maximumElement = current->data;

      current = current->next;
    }

  return maximumElement;
}
```

_The `findMaximumElement` function finds and returns the maximum element in the Circular Linked List._


**_23. Find Minimum Element:_**

```c
int findMinimumElement(CircularLinkedList *list)
{
  if (list->head == NULL)
    return -1;

  int minimumElement = list->head->data;
  Node *current = list->head->next;

  if (list->head != current)
    while (current != list->head)
    {
      if (current->data < minimumElement)
        minimumElement = current->data;

      current = current->next;
    }

  return minimumElement;
}
```

_The `findMinimumElement` function finds and returns the minimum element in the Circular Linked List._

# DOUBLY LINKED LIST

_A doubly linked list is a type of linked list in which each node contains a pointer to the previous node in the list, in addition to the pointer to the next node. This makes it possible to traverse the list in both the forward and backward directions._

**_1. Create Doubly Linked List:_**

```c
DoublyLinkedList* createDoublyLinkedList()
{
    DoublyLinkedList* linkedList = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    linkedList->head = NULL;
    return linkedList;
}
```

_This function creates an empty doubly linked list and returns a pointer to the newly created list. A doubly linked list is a data structure where each element, known as a node, contains a 'data' field and two pointers: 'next' and 'previous'. The 'head' of the list initially points to NULL, indicating an empty list. This function allocates memory for the list, initializes the 'head' to NULL, and returns the list for further use._


**_2. Check If List Is Empty:_**

```c
int isEmpty(DoublyLinkedList list)
{
    return list.head == NULL;
}
```

_This function checks whether the given doubly linked list is empty or not. An empty list has its 'head' pointer set to NULL. It returns 1 if the list is empty and 0 if it contains one or more nodes. The function helps in determining if any elements are present in the linked list, which is a crucial operation for list management._


**_3. Append Item:_**

```c
void append(DoublyLinkedList* list, int item)
{
    Node* node = (Node *)malloc(sizeof(Node));
    node->data = item;
    node->next = NULL;
    if (isEmpty(*list))
    {
        node->previous = NULL;
        list->head = node;
    }
    else
    {
        Node* last = list->head;
        while (last->next)
            last = last->next;
        node->previous = last;
        last->next = node;
    }
}
```

_The 'append' function adds a new item to the end of a given doubly linked list. It allocates memory for a new node, assigns the provided 'item' as the data for that node, and adjusts the pointers to connect it as the last node in the list. If the list is empty, the newly added node becomes the first node, and its 'previous' pointer is set to NULL. If the list is not empty, the 'previous' pointer of the new node is set to the previous last node, and the 'next' pointer of the previous last node is updated to point to the new node._


**_4. Append Multiple Items:_**

```c
void appendAll(DoublyLinkedList* list, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        append(list, va_arg(args, int));
}
```

_The 'appendAll' function allows you to append multiple items to the end of a doubly linked list. It takes the list and the number of items to be appended as input. You can pass a variable number of arguments representing the items to be added. It uses a variable argument list (va_list) to process the items. The function appends each item to the end of the list one by one, effectively extending the list with the new elements._


**_5. Insert Item at Beginning:_**

```c
void shift(DoublyLinkedList* list, int item)
{
    Node* node = (Node *)malloc(sizeof(Node));
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
```

_The 'shift' function inserts an item at the beginning of the given doubly linked list. It allocates memory for a new node, assigns the provided 'item' as the data for that node, and adjusts the pointers to connect it as the new first node in the list. If the list is empty, the newly added node becomes the first node, and its 'previous' and 'next' pointers are set to NULL. If the list is not empty, the 'next' pointer of the new node is set to the previous first node, and the 'previous' pointer of the previous first node is updated to point to the new node. The 'head' pointer of the list is updated to point to the new first node._


**_6. Insert After Node:_**

```c

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

```

_This function allows you to insert a new node with a specified item after an existing node in a doubly linked list. If the list is empty, it appends the item as the first node. An error message is displayed if the specified node is not found in the list._


**_7. Insert Multiple After:_**

```c

void insertAllAfter(DoublyLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertAfter(list, node, va_arg(args, int));
}

```

_This function enables the insertion of multiple new nodes with specified items after a particular node in a doubly linked list. It calls the 'insertAfter' function for each item to be inserted after the specified node._


**_8. Insert Before Node:_**

```c

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

```

_This function allows you to insert a new node with a specified item before an existing node in a doubly linked list. If the list is empty, it appends the item as the first node. An error message is displayed if the specified node is not found in the list._


**_9. Insert Multiple Before:_**

```c

void insertAllBefore(DoublyLinkedList *list, Node *node, int item, int itemCount, ...)
{
    va_list args;
    va_start(args, itemCount);
    for (int index = 0; index < itemCount; index++)
        insertBefore(list, node, va_arg(args, int));
}

```

_This function facilitates the insertion of multiple new nodes with specified items before a particular node in a doubly linked list. It calls the 'insertBefore' function for each item to be inserted before the specified node._


**_10. Display All Items:_**

```c

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

```

_This function displays all the items in the doubly linked list, along with their relationships with adjacent nodes (next and previous). If the list is empty, it prints a message to indicate that the list is empty._


**_11. Search Item:_**

```c

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

```

_This function is used to search for a specific item within the doubly linked list. It returns 1 if the item is found and 0 if it is not found. It assumes that the list is not empty._


**_12. Pop First Node:_**

```c

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

```

_This function removes and returns the data of the first node in the doubly linked list. It assumes that the list is not empty._


**_13. Pop Last Node:_**

```c

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

```

_This function removes and returns the data of the last node in the doubly linked list. It assumes that the list is not empty._


**_14. Pop Node with Data:_**

```c

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

```

_This function removes the first node with the specified data from the doubly linked list. If the node with the given data is found, it returns the data of the removed node; otherwise, it returns -1. It assumes that the list is not empty._


**_15. Get First Node Data:_**

```c

int getFirst(DoublyLinkedList list)
{
    assert(!isEmpty(list));
    return list.head->data;
}

```

_This function returns the data of the first node in the doubly linked list. It assumes that the list is not empty._


**_16. Get Last Node Data:_**

```c

int getLast(DoublyLinkedList list)
{
    assert(!isEmpty(list));
    Node *node = list.head;
    while (node->next)
        node = node->next;
    return node->data;
}

```

_This function returns the data of the last node in the doubly linked list. It assumes that the list is not empty._


**_17. Get Size of List:_**

```c

int getSize(DoublyLinkedList list, Node *head)
{
    if (isEmpty(list))
        return 0;
    if (head)
        return 1 + getSize(list, head->next);
}

```

_This function returns the size of the doubly linked list. It assumes that the list is not empty._


**_18. Get Item by Index:_**

```c

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

```

_This function returns the data of the node at the specified index in the doubly linked list. It assumes that the list is not empty._


**_19. Sort List:_**

```c

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

```

_This function sorts the doubly linked list based on the specified key. If the key is 1, the list is sorted in ascending order, and if the key is -1, the list is sorted in descending order. The function uses a bubble sort algorithm for sorting._


**_20. Reverse List:_**

```c

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

```

_This function reverses the order of nodes in the doubly linked list, effectively reversing the list. It uses an iterative approach to perform the reversal._


**_21. Get Node by Data:_**

```c

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

```

_This function retrieves the node with the specified data from the doubly linked list. If the node with the given data is found, it returns a pointer to that node; otherwise, it returns NULL. The function assumes that the list is not empty._


**_22. Update Node Data:_**

```c

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

```

_This function updates the data of a node in the doubly linked list. It searches for a node with the specified old value and updates it with the new value. If the old value is not found in the list, the function displays a message to indicate that the item does not exist._


**_23. Concatenate Lists:_**

```c

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

```

_This function concatenates the second linked list to the end of the first linked list. If the first list is empty, it simply points to the second list. The function preserves the double-linked relationships between nodes._


**_24. Split List by Position:_**

```c

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

```

_This function splits the linked list into two parts at the specified position. The 'firstHalf' and 'secondHalf' linked lists are used to store the resulting parts. The function preserves the double-linked relationships between nodes. It also displays a message if the specified position does not exist._


**_25. Merge Sorted Lists:_**

```c

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

```

_This function merges two sorted linked lists into a new sorted list based on the specified key. If the key is 1, the list is merged in ascending order, and if the key is -1, the list is merged in descending order. The function returns a new sorted linked list._


**_26. Detect Cycle (Floyd's Algorithm):_**

```c

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

```

_This function detects the presence of a cycle in the linked list using Floyd's Tortoise and Hare Algorithm. It returns true if a cycle is detected, and false otherwise._


**_27. Find Intersection Node:_**

```c

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

```

_This function finds the intersection node between two linked lists 'list1' and 'list2'. It returns the node where the lists intersect or NULL if there's no intersection._


**_28. Remove Duplicates:_**

```c

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

```

_This function removes duplicates from a linked list 'list' while preserving the original order. It modifies the list in place._


**_29. Check Ascending Sorted:_**

```c

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

```

_This function checks if a linked list 'list' is sorted in ascending order. It returns true if the list is sorted and false otherwise._


**_30. Check Descending Sorted:_**

```c

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

```

_This function checks if a linked list 'list' is sorted in descending order. It returns true if the list is sorted and false otherwise._


**_31. Search with Criteria:_**

```c

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

```

_This function searches for a node in the linked list 'list' based on a custom criteria function 'criteria.' It returns the first node that meets the criteria or NULL if no nodes match the criteria._

# GRAPH

_A graph is a non-linear data structure that consists of a set of vertices (also called nodes) and a set of edges. The edges connect the vertices in pairs, and can be either directed or undirected. A directed edge has a direction, meaning that it can only be traversed in one direction. An undirected edge does not have a direction, meaning that it can be traversed in either direction._

**_1. Create Node:_**

```c

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


```

_This function creates a new node with the given data and initializes the 'next' pointer to NULL. It returns the newly created node._


**_2. Create Graph:_**

```c

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->type = DIRECTED;
    graph->adjLists = (Node **)malloc(vertices * sizeof(Node *));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

```

_This function creates a new graph with the specified number of vertices. It initializes the adjacency lists and graph type. It returns the newly created graph._


**_3. Add Edge:_**

```c

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (graph->type == UNDIRECTED)
    {
        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = src;
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

```

_This function adds a directed edge from the source vertex 'src' to the destination vertex 'dest' in the graph. For undirected graphs, it adds an edge in both directions if the graph type is set to 'UNDIRECTED'._


**_4. Depth-First Search (DFS):_**

```c

void DFS(Graph *graph, int vertex, bool *visited)
{
    visited[vertex] = true;
    printf("%d ", vertex);

    Node *adjList = graph->adjLists[vertex];
    while (adjList)
    {
        int neighbor = adjList->data;
        if (!visited[neighbor])
            DFS(graph, neighbor, visited);
        adjList = adjList->next;
    }
}

```

_This function performs Depth-First Search (DFS) on the graph starting from a given vertex. It marks visited vertices and prints the traversal path._


**_5. Breadth-First Search (BFS):_**

```c

void BFS(Graph *graph, int startVertex)
{
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
    {
        visited[i] = false;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    visited[startVertex] = true;
    queue[rear++] = startVertex;

    printf("Breadth-First Traversal: ");

    while (front < rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];
        while (temp)
        {
            int adjVertex = temp->data;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

```

_This function performs Breadth-First Search (BFS) on the graph starting from a given vertex. It marks visited vertices and prints the traversal path._


**_6. Show Graph:_**

```c

void showGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->adjLists[i];
        printf("\e[1;36mVertex \e[4;32m%d\e[0m: ", i);
        while (current)
        {
            printf("(\e[1;31m%d\e[0m)\e[1;36m -> ", current->data);
            current = current->next;
        }
        printf("\e[1;31mNULL\e[0m\n");
    }
}

```

_This function displays the adjacency lists representation of the graph, showing the relationships between vertices._


**_7. Graph from Matrix:_**

```c

Graph *graphFromMatrix(int graph[V][V], int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->numVertices = V;
    newGraph->adjLists = (Node **)malloc(V * sizeof(Node *));

    for (int i = 0; i < V; i++)
    {
        newGraph->adjLists[i] = NULL;
        for (int j = 0; j < V; j++)
        {
            if (graph[i][j] == 1)
            {
                Node *newNode = createNode(j);
                newNode->next = newGraph->adjLists[i];
                newGraph->adjLists[i] = newNode;
            }
        }
    }

    return newGraph;
}

```

_This function creates a graph from an adjacency matrix. It converts the matrix into an adjacency lists representation and returns the newly created graph._


**_8. Graph from List:_**

```c

Graph *graphFromList(Node *adjacencyList[], int V)
{
    Graph *newGraph = (Graph *)malloc(sizeof(Graph));
    newGraph->numVertices = V;
    newGraph->adjLists = (Node **)malloc(V * sizeof(Node *));

    for (int i = 0; i < V; i++)
    {
        newGraph->adjLists[i] = NULL;
        Node *currentNode = adjacencyList[i];
        while (currentNode)
        {
            Node *newNode = createNode(currentNode->data);
            newNode->next = newGraph->adjLists[i];
            newGraph->adjLists[i] = newNode;
            currentNode = currentNode->next;
        }
    }

    return newGraph;
}

```

_This function creates a graph from an array of linked lists (adjacency lists). It converts the lists into an adjacency lists representation and returns the newly created graph._


**_9. Topological Sort:_**

```c

void topologicalSort(Graph *graph)
{
    bool visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++)
        visited[i] = false;

    Node *stack = NULL;

    for (int i = 0; i < graph->numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, &stack);

    printf("Topological Sort: ");
    while (stack)
    {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

```

_This function performs a topological sort on a directed acyclic graph (DAG). It prints the topological ordering of vertices._


**_10. Graph to Matrix:_**

```c

int **graphToMatrix(Graph *graph)
{
    int numVertices = graph->numVertices;
    int **adjacencyMatrix = (int **)malloc(numVertices * sizeof(int *));

    for (int i = 0; i < numVertices; i++)
    {
        adjacencyMatrix[i] = (int *)malloc(numVertices * sizeof(int));
        for (int j = 0; j < numVertices; j++)
            adjacencyMatrix[i][j] = 0;
    }

    for (int i = 0; i < numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp)
        {
            adjacencyMatrix[i][temp->data] = 1;
            temp = temp->next;
        }
    }

    return adjacencyMatrix;
}

```

_This function converts a graph into an adjacency matrix representation and returns the adjacency matrix._


**_11. Print Matrix:_**

```c

void printMatrix(int **matrix, int numVertices)
{
    printf("\e[4;31m{\n\e[0m");
    for (int i = 0; i < numVertices; i++)
    {
        printf("\e[1;34m{ \e[0m");
        for (int j = 0; j < numVertices; j++)
        {
            printf(matrix[i][j] ? "\e[1;35m%d" : "\e[1;32m%d", matrix[i][j]);
            if (j < numVertices - 1)
                printf("\e[1;33m, ");
        }
        printf("\e[1;34m },\n\e[0m");
    }
    printf("\e[4;31m }\n\e[0m");
}

```

_This function prints an adjacency matrix, displaying the connectivity between vertices._

# HASH MAP

_A hash map, also known as a hash table, is a data structure that maps keys to values. It uses a hash function to convert each key into a unique index into an array. This allows the hash map to efficiently retrieve the value associated with a given key._

**_1. Initialize Hash Table:_**

```c

void initializeHashTable(HashTable *hashtable)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
        hashtable->buckets[i] = NULL;
}

```

_This function initializes the hash table by setting all buckets to NULL. It prepares the hash table for use._


**_2. Hash Function:_**

```c

int hash(const char *key)
{
    int hash = 0;
    for (int i = 0; key[i]; i++)
        hash += key[i];

    return hash % NUM_BUCKETS;
}
```

_This function generates a hash value for the given key. It returns the hash value modulo the number of buckets to determine the index in the hash table._


**_3. Insert into Hash Table:_**

```c

void insert(HashTable *hashtable, const char *key, int value)
{
    int index = hash(key);

    KV *pair = (KV *)malloc(sizeof(KV));
    pair->key = strdup(key);
    pair->value = value;
    pair->next = NULL;

    if (hashtable->buckets[index] == NULL)
        hashtable->buckets[index] = pair;
    else
    {
        KV *current = hashtable->buckets[index];
        while (current->next != NULL)
            current = current->next;
        current->next = pair;
    }
}

```

_This function inserts a key-value pair into the hash table. It handles collisions by chaining elements in linked lists within the same bucket._


**_4. Get Value from Hash Table:_**

```c

int get(HashTable *hashtable, const char *key)
{
    int index = hash(key);

    KV *current = hashtable->buckets[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
            return current->value;

        current = current->next;
    }

    return -1;
}

```

_This function retrieves the value associated with a key from the hash table. It returns the value or -1 if the key is not found in the hash table._


**_5. Clear Hash Table:_**

```c

void clear(HashTable *hashtable)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
    {
        KV *current = hashtable->buckets[i];
        while (current != NULL)
        {
            KV *temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
}

```

_This function clears the hash table and deallocates memory. It frees all key-value pairs and linked list nodes, making the hash table ready for cleanup._

# HEAPS (MIN-MAX)

_A heap is a data structure that organizes elements in a tree-based structure such that the elements at any given level are greater than or equal to (or less than or equal to, depending on the type of heap) their child elements. This property is called the heap property. Heaps are often used to implement priority queues, which are abstract data types that provide efficient methods for inserting and removing the element with the highest (or lowest) priority._

**_1. Create Max Heap:_**

```c

MaxHeap* createMaxHeap(int initialCapacity)
{
    MaxHeap *heap = (MaxHeap *)malloc(sizeof(MaxHeap));
    heap->capacity = initialCapacity;
    heap->size = 0;
    heap->arr = (int *)malloc(sizeof(int) * initialCapacity);
    return heap;
}

```

_This function creates a new Max Heap with the specified initial capacity. It initializes the heap size and allocates memory for the heap array. It returns a pointer to the created Max Heap._


**_2. Swap:_**

```c

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

```

_This function swaps the values of two integers by reference, using pointers to the integers._


**_3. Heapify Up:_**

```c

void heapifyUp(MaxHeap* heap, int index)
{
    int parent = (index - 1) / 2;
    while (index > 0 && heap->arr[index] > heap->arr[parent])
    {
        swap(&heap->arr[index], &heap->arr[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

```

_This function restores the Max Heap property by moving the element up the heap as needed, to maintain the heap structure._


**_4. Insert into Max Heap:_**

```c

void insert(MaxHeap* heap, int value)
{
    if (heap->size >= heap->capacity)
    {
        heap->capacity *= 2;
        heap->arr = (int *)realloc(heap->arr, sizeof(int) * heap->capacity);
    }
    heap->arr[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

```

_This function inserts a value into the Max Heap while maintaining the Max Heap property. It dynamically resizes the heap if it exceeds its capacity._


**_5. Heapify Down:_**

```c

void heapifyDown(MaxHeap* heap, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < heap->size && heap->arr[left] > heap->arr[largest])
        largest = left;
    if (right < heap->size && heap->arr[right] > heap->arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(&heap->arr[index], &heap->arr[largest]);
        heapifyDown(heap, largest);
    }
}

```

_This function restores the Max Heap property by moving the element down the heap as needed, to maintain the heap structure._


**_6. Extract Max:_**

```c

int extractMax(MaxHeap* heap)
{
    if (heap->size <= 0)
    {
        printf("Heap is empty.\n");
        return -1;
    }
    int max = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, 0);
    return max;
}

```

_This function removes and returns the maximum element from the Max Heap. It restores the Max Heap property after extraction. If the heap is empty, it prints an error message and returns -1._


**_7. Build Max Heap:_**

```c

void buildMaxHeap(MaxHeap* heap, int* arr, int n)
{
    for (int i = 0; i < n; i++)
        insert(heap, arr[i]);
}

```

_This function builds a Max Heap from an array of elements. It inserts the elements into the heap to create a valid Max Heap structure._


**_8. Delete:_**

```c

int delete(MaxHeap* heap, int value)
{
    int index = -1;
    for (int i = 0; i < heap->size; i++)
        if (heap->arr[i] == value)
        {
            index = i;
            break;
        }

    if (index == -1)
    {
        printf("Element not found in the heap.\n");
        return -1;
    }
    int deletedValue = heap->arr[index];
    heap->arr[index] = heap->arr[heap->size - 1];
    heap->size--;
    heapifyDown(heap, index);
    return deletedValue;
}

```

_This function deletes an element with the specified value from the Max Heap. It restores the Max Heap property after deletion. If the element is not found, it prints an error message and returns -1._


**_9. Decrease Key:_**

```c

void decreaseKey(MaxHeap* heap, int index, int newValue)
{
    if (index < 0 || index >= heap->size)
    {
        printf("Invalid index.\n");
        return;
    }
    if (newValue < heap->arr[index])
    {
        printf("New value is smaller than the current value.\n");
        return;
    }
    heap->arr[index] = newValue;
    heapifyUp(heap, index);
}

```

_This function decreases the value of an element at the specified index in the Max Heap. It checks for valid indices and ensures that the new value is smaller than the current value._


**_10. Heap Sort:_**

```c

void heapSort(MaxHeap* heap)
{
    int n = heap->size;
    for (int i = n - 1; i >= 0; i--)
        heap->arr[i] = extractMax(heap);
}

```

_This function sorts the Max Heap in ascending order using the heap sort algorithm._


**_11. Convert to String:_**

```c

void toString(MaxHeap* heap)
{
    printf("[");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d", heap->arr[i]);
        if (i != heap->size - 1)
            printf(", ");
    }
    printf("]\n");
}

```

_This function converts the Max Heap into a string format for display, including its elements and structure._

# SET

_A set is an abstract data type that can store unique values, without any particular order. It is a computer implementation of the mathematical concept of a finite set. Unlike most other collection types, rather than retrieving a specific element from a set, one typically tests a value for membership in a set_

**_1. Create Set:_**

```c

Set *createSet()
{
    Set *set = (Set *)malloc(sizeof(Set));
    set->head = NULL;
    return set;
}

```

_This function creates an empty Set. It initializes the head of the Set as NULL and returns a pointer to the created Set._


**_2. Contains:_**

```c

bool contains(Set set, int element)
{
    Node *current = set.head;
    while (current)
    {
        if (current->data == element)
            return true;
        current = current->next;
    }
    return false;
}

```

_This function checks if the Set contains a specified element. It returns true if the element is found; otherwise, it returns false._


**_3. Add to Set:_**

```c

void add(Set *set, int element)
{
    if (!contains(*set, element))
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = element;
        newNode->next = set->head;
        set->head = newNode;
    }
}

```

_This function adds an element to the Set if it is not already present. It ensures that there are no duplicate elements in the Set._


**_4. Remove Item:_**

```c

void removeItem(Set *set, int element)
{
    Node *current = set->head;
    Node *prev = NULL;

    while (current)
    {
        if (current->data == element)
        {
            if (prev)
                prev->next = current->next;
            else
                set->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

```

_This function removes an element from the Set if it exists. It maintains the integrity of the Set and deallocates memory for the removed element._


**_5. Show All:_**

```c

void showAll(Set *set)
{
    printf("Set: { ");
    Node *current = set->head;
    while (current)
    {
        printf(current->next ? "%d, " : "%d ", current->data);
        current = current->next;
    }
    printf("}\n");
}

```

_This function displays all elements in the Set for visualization. It presents the elements as a list enclosed in curly braces._


**_6. Clear Set:_**

```c

void clearSet(Set *set)
{
    Node *current = set->head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
    set->head = NULL;
}
