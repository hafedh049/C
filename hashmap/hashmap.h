#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KeyValuePair{
    char *key;
    int value;
    KeyValuePair *next;
}KeyValuePair;

typedef struct HashMap
{
    KeyValuePair* head;
}Hashmap;

HashMap* createHashMap() {
    HashMap* hashMap = (HashMap*)malloc(sizeof(HashMap));
    hashMap->head = NULL;
    return hashMap;
}

void addItem(HashMap* map, const char* key,const int value) {
    unsigned int index = hash(key);
    KeyValuePair* newPair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = value;
    newPair->next = NULL;

    // Check if the bucket is empty
    if (map->buckets[index] == NULL) {
        map->buckets[index] = newPair;
    } else {
        // Handle collision by chaining
        KeyValue* current = map->buckets[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newPair;
    }
}