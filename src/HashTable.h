/* HashTable.h
 *
 *
 * */
#include <stdbool.h>
#include <stddef.h>

#define INITIAL_CAPACITY 16 /* must not be zero */
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

typedef struct {
    const char *key;
    void *value;
} HashTableEntry;

struct _hashtable {
    HashTableEntry *entries;  // hash slots
    size_t capacity;
    size_t length;
};

typedef struct _hashtable HashTable;

typedef struct {
    const char *key;
    void *value;
    HashTable *_table;
    size_t _index;
} HashTableIterator;

HashTable *makeEmptyHashTable(void);
void destroyHashTable(HashTable *table);
void *get(HashTable *table, const char *key);
const char *set(HashTable *table, const char *key, void *value);
size_t length(HashTable *table);
HashTableIterator hashtableIterator(HashTable *table);
bool hashtableNext(HashTableIterator *it);
