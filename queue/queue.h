typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
}Queue;

Queue createQueue();
int isEmpty(Queue);
void push(Queue *, int);
Node *pop(Queue *);
int size(Queue);
void showAllItems(Queue);
void clear(Queue*);
int peek(Queue);
int search(Queue, int);
void sort(Queue*, int);
void pushMany(Queue*, int , ...);
void reverse(Queue*);
Queue copy(Queue);
Queue merge(Queue,Queue);