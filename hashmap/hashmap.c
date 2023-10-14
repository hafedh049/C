#include "hashmap.h"

void initialise(HashTable *hashtable)
{
    for (int i = 0; i < NUM_BUCKETS; i++)
        hashtable->buckets[i] = NULL;
}

int hash(const char *key)
{
    int hash = 0;
    for (int i = 0; key[i]; i++)
    {
        hash += key[i];
    }
    return hash % NUM_BUCKETS;
}

void insert(HashTable *hashtable, const char *key, int value)
{
    int index = hash(key);

    KV *pair = (KV *)malloc(sizeof(KV));
    pair->key = strdup(key);
    pair->value = value;
    pair->next = NULL;

    if (hashtable->buckets[index] == NULL)
    {
        hashtable->buckets[index] = pair;
    }
    else
    {
        KV *current = hashtable->buckets[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = pair;
    }
}

int get(HashTable *hashtable, const char *key)
{
    int index = hash(key);

    KV *current = hashtable->buckets[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}

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