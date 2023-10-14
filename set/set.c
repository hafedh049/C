#include "set.h"

Set *createSet()
{
    Set *set = (Set *)malloc(sizeof(Set));
    set->head = NULL;
    return set;
}

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

Set *unions(Set firstSet, Set secondSet)
{
    Set *result = createSet();

    Node *current1 = firstSet.head;
    while (current1 != NULL)
    {
        add(result, current1->data);
        current1 = current1->next;
    }

    current1 = secondSet.head;
    while (current1 != NULL)
    {
        add(result, current1->data);
        current1 = current1->next;
    }

    return result;
}

Set *intersects(Set firstSet, Set secondSet)
{
    Set *result = createSet();

    Node *current = firstSet.head;
    while (current != NULL)
    {
        if (contains(secondSet, current->data))
            add(result, current->data);
        current = current->next;
    }

    return result;
}

Set *differences(Set firstSet, Set secondSet)
{
    Set *result = createSet();

    Node *current = firstSet.head;
    while (current != NULL)
    {
        if (!contains(secondSet, current->data))
            add(result, current->data);
        current = current->next;
    }

    return result;
}

bool isSubset(Set firstSet, Set secondSet)
{
    Node *current = firstSet.head;
    while (current != NULL)
    {
        if (!contains(secondSet, current->data))
            return false;
        current = current->next;
    }
    return true;
}

int cardinal(Set set)
{
    int count = 0;
    Node *current = set.head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

bool isEmpty(Set set)
{
    return set.head == NULL;
}

int getElementAtIndex(const Set set, int index)
{
    if (isEmpty(set))
        return -1;

    int count = 0;
    Node *current = set.head;

    while (current != NULL)
    {
        if (count == index)
            return current->data;

        current = current->next;
        count++;
    }

    return -1;
}

void powerSet(Set set, int setSize)
{
    int totalSubsets = (int)pow(2, setSize);
    printf("{\n");
    for (int i = 0; i < totalSubsets; i++)
    {
        printf(" {");
        for (int j = 0; j < setSize; j++)
            if (i & (1 << j))
                printf("%d,", getElementAtIndex(set, j));
        printf(i == totalSubsets - 1 ? "}\n" : "},\n");
    }
    printf("}\n");
}

bool areSetsEqual(Set firstSet, Set secondSet)
{
    if (cardinal(firstSet) != cardinal(secondSet))
        return false;

    for (int j = 0; j < cardinal(firstSet); j++)
        if (getElementAtIndex(firstSet, j) != getElementAtIndex(secondSet, j))
            return false;
    return true;
}

bool areDisjoints(Set firstSet, Set secondSet)
{
    return intersects(firstSet, secondSet)->head ? false : true;
}

Set *symmetricDifferences(Set firstSet, Set secondSet)
{
    Set *result = createSet();
    Set *intersection = intersects(firstSet, secondSet);
    Node *current = firstSet.head;
    while (current != NULL)
    {
        if (!contains(*intersection, current->data))
            add(result, current->data);
        current = current->next;
    }
    current = secondSet.head;
    while (current != NULL)
    {
        if (!contains(*intersection, current->data))
            add(result, current->data);
        current = current->next;
    }

    return result;
}

bool cartisianProduct(Set firstSet, Set secondSet)
{
    printf("Cartesian Product of the Sets: { ");
    for (int i = 0; i < cardinal(firstSet); i++)
    {
        for (int j = 0; j < cardinal(secondSet); j++)
        {
            printf("(%d, %d),\n", getElementAtIndex(firstSet, i), getElementAtIndex(secondSet, j));
        }
    }
    printf("}\n");
}

bool isSuperset(Set firstSet, Set secondSet)
{
    return isSubset(secondSet, firstSet);
}

Set *complementSet(Set setB, Set setA)
{
    Set *result = createSet();
    printf("Complement Set: { ");
    for (int i = 0; i < cardinal(setB); i++)
    {
        bool found = false;

        for (int j = 0; j < cardinal(setA); j++)
            if (contains(setA, getElementAtIndex(setB, i)))
            {
                found = true;
                break;
            }

        if (!found)
            get(result, getElementAtIndex(setB, i));
    }

    return result;
}

bool isSymmetric(Set universalSet, Set set)
{
    return areSetsEqual(set, *complementSet(universalSet, set));
}

Set *inversionSet(Set universalSet, Set setA)
{
    return complementSet(universalSet, setA);
}

void addAll(Set *set, int numArgs, ...)
{
    va_list args;
    va_start(args, numArgs);

    for (int i = 0; i < numArgs; i++)
        add(set, va_arg(args, int));

    va_end(args);
}