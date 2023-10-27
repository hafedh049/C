# STACK

<span style="color:blue">
_I. A stack is a last-in-first-out (LIFO) data structure. Elements can only be added to and removed from the top of the stack. Stacks are often used to implement undo/redo functionality, function calls, and expression evaluation._
</span>

<font color="blue"> **_1. Create stack:_** </font>

```c
Stack createStack()
{
	Stack stack;
	stack.head = NULL;
	return stack;
}
```

_This createStack function creates and initializes an empty stack using a Stack structure and returns that empty stack. It is useful for initializing a stack before adding elements to it. After calling this function, you would have a stack ready for use._

<font color="blue">**_2. Push item:_** </font>

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

<font color="blue"> **_3. Verify if the list is empty or not:_** </font>

```c
int isEmpty(Stack stack)
{
	return stack.head == NULL;
}
```

_The isEmpty function takes a Stack as an argument and checks if the head pointer of the stack is NULL. If it's NULL, the function returns 1 to indicate that the stack is empty; otherwise, it returns 0 to indicate that the stack is not empty._

<font color="blue"> **_4. Delete an item:_** </font>

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

<font color="blue"> **_5. Size of a stack:_** </font>

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

<font color="blue"> **_6. Show all items of a stack:_** </font>

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

<font color="blue"> **_7. Clear a stack:_** </font>

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

<font color="blue"> **_8. Peek a stack:_** </font>

```c
int peek(Stack stack)
{
	assert(!isEmpty(stack));
	return stack.head->data;
}
```

_The peek function is used to retrieve the data of the top element of a stack without removing it. It includes a safety check to ensure that the stack is not empty before attempting to peek, preventing potential errors caused by peeking at an empty stack._

<font color="blue"> **_9. Search an item in a stack:_** </font>

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

<font color="blue"> **_10. Sort a stack:_** </font>

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

<font color="blue"> **_11. Add many items in a stack:_** </font>

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

<font color="blue"> **_12. Reverse a stack:_** </font>

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

<font color="blue"> **_13. Copy a stack:_** </font>

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

<font color="blue"> **_14. Merge two stacks into a single stack:_** </font>

```c
Stack merge(Stack firstStack, Stack secondStack)
{
	Stack mergingStack = createStack();
	while (firstStack.head)
		push(&mergingStack, pop(&firstStack)->data);
	while (secondStack.head)
		push(&mergingStack, pop(&secondStack)->data);
	return mergingStack;
}
```

_The merge function combines two input stacks into a single stack (mergingStack) by popping elements from both input stacks and pushing them onto the merged stack. The result is a new stack containing all the elements from both input stacks in the order they were originally in their respective stacks._

# QUEUE

_A queue is a first-in-first-out (FIFO) data structure. Elements are added to the end of the queue and removed from the front. Queues are often used to implement tasks that must be processed in order, such as printing jobs or tasks in a production line._

<font color="blue"> **_1. Create queue:_** </font>

```c
Queue createQueue()
{
    Queue queue;
    queue.head = NULL;
    queue.tail = NULL;
    return queue;
}
```

_The function```c Queue createQueue()``` creates and initializes a new queue data structure. It allocates memory for a new Queue struct and initializes its head and tail pointers to```c NULL```. This indicates that the queue is empty. The function then returns the new queue struct._