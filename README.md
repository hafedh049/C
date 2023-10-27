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
