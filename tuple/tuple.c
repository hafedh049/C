#include "tuple.h"

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

const Tuple *createTuple(int numArgs, ...)
{
    Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
    newTuple->head = NULL;
    va_list args;
    va_start(args, numArgs);

    if (numArgs > 0)
    {

        newTuple->head = createNode(va_arg(args, int));
        Node *current = newTuple->head;
        for (int i = 0; i < numArgs; i++)
        {
            Node *newNode = createNode(va_arg(args, int));
            current->next = newNode;
            current = current->next;
        }
    }

    va_end(args);
    return newTuple;
}

int getFromTuple(const Tuple tuple, int index)
{
    if (tuple.head == NULL)
        return -1;
    Node *current = tuple.head;
    int currentIndex = 0;
    while (current != NULL)
    {
        if (currentIndex == index)
            return current->data;
        current = current->next;
        currentIndex++;
    }
    return -1;
}

void showTuple(const Tuple tuple)
{
    if (tuple.head == NULL)
    {
        printf("()\n");
        return;
    }
    printf("(");
    Node *current = tuple.head;
    while (current != NULL)
    {
        printf(current->next ? "%d, " : "%d", current->data);
        current = current->next;
    }
    printf(")\n");
}

int size(const Tuple tuple)
{
    if (tuple.head == NULL)
        return 0;
    Node *current = tuple.head;
    int currentSize = 0;
    while (current != NULL)
    {
        current = current->next;
        currentSize++;
    }
    return currentSize;
}

bool tuplesEquality(const Tuple firstTuple, const Tuple secondTuple)
{
    if (size(firstTuple) != size(secondTuple))
        return false;
    for (int index = 0; index < size(firstTuple); index++)
        if (getFromTuple(firstTuple, index) != getFromTuple(secondTuple, index))
            return false;
    return true;
}

Tuple *copy(const Tuple tuple)
{
    Tuple *newTuple = (Tuple *)malloc(sizeof(Tuple));
    newTuple->head = NULL;
    if (tuple.head == NULL)
        return newTuple;
    newTuple->head = createNode(getFromTuple(tuple, 0));
    Node *current = newTuple->head;
    for (int index = 1; index < size(tuple) ; index++)
    {
        Node *newNode = createNode(getFromTuple(tuple, index));
        current->next = newNode;
        current = current->next;
    }
}

int* tupleToArray(const Tuple tuple){
    int *array = (int*)malloc(size(tuple) * sizeof(int)); 
    int *ptr = array;
    for(int index = 0 ; index < size(tuple) ; index++)
        *(ptr + index) = getFromTuple(tuple, index);
    return array;
}

int countDigits(int number) {
    int count = 0;

    if (abs(number) < 10) {
        return 1;
    }

    while (number != 0) {
        number /= 10;
        count++;
    }

    return count;
}

int calcStringSize(const Tuple tuple){
    int counter = 1 + 1 + 1 + 2 * (size(tuple) - 1);
    for (int index = 0; index < size(tuple); index++)
        counter += countDigits(getFromTuple(tuple,index));
};

char* tupleToString(const Tuple tuple) {
    char* str = (char*)malloc(calcStringSize(tuple) * sizeof(char));
    char* temp = str;

    *temp = '(';
    temp++;

    for (int index = 0; index < size(tuple); index++) {
        int num = getFromTuple(tuple,index);
        int charsWritten = sprintf(temp, "%d", num);
        temp += charsWritten;

        if (index < size - 1) {
            *temp = ',';
            temp++;
            *temp = ' ';
            temp++;
        }
    }

    *temp = ')';
    temp++;
    *temp = '\0';

    return str;
}
