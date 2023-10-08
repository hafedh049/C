typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *head;
} Stack;

Stack *createStack();
int isEmpty(Stack);
void push(Stack *, int);
Node *pop(Stack *);
int size(Stack);
void showAllItems(Stack);
void clear(Stack *);
int peek(Stack);
int search(Stack, int);
void sort(Stack *, int);
void pushMany(Stack *, int, ...);
void reverse(Stack *);
Stack *copy(Stack);
Stack *merge(Stack, Stack);