#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Set
{
    Node *head;
} Set;

Set *createSet();

bool contains(Set, int);

void add(Set *, int);

void removeItem(Set *, int);

void showAll(Set *);

void clearSet(Set *);

Set *unions(Set, Set);

Set *intersects(Set, Set);

Set *differences(Set, Set);

bool isSub(Set, Set);

int cardinal(Set);

bool isEmpty(Set);

int getElementAtIndex(const Set, int);

void powerSet(Set, int);

bool areSetsEqual(Set, Set);

bool areDisjoints(Set, Set);

Set *symmetricDifferences(Set, Set);

bool cartisianProduct(Set, Set);

bool isSuper(Set, Set);

Set *complementSet(Set B, Set A);

Set *inversionSet(Set, Set A);

void addAll(Set *, int, ...);