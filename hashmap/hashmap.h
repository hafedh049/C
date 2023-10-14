#include <stdlib.h>
#include <string.h>

const NUM_BUCKETS = 100;

typedef struct KV
{
    char *key;
    int value;
    struct KV *next;
} KV;

typedef struct HashTable
{
    KV *buckets[NUM_BUCKETS];
} HashTable;

void initialize(struct HashTable *hashtable);

void insert(struct HashTable *hashtable, const char *key, int value);

int get(struct HashTable *hashtable, const char *key);

void cleanup(struct HashTable *hashtable);