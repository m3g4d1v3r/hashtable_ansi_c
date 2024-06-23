#ifndef HASHTABLE_H
#define HASHTABLE_H

#define ARRAYMAX 50
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// The choice of implementation of the hashtable is a simple stack allocated array
// that supports entries for heap allocated linked lists. However other choices
// could be made here as well...

typedef struct pair {
    char *key;
    double value;
} pair_t;

typedef struct entry {
    struct pair content;
    struct entry *next;
} entry_t;

typedef struct hashtable {
    entry_t *array[ARRAYMAX];
} hashtable_t;

// This function provides a core functionality in truly shuffling the entry keys:
// the keys will be evenly distributed in the array according to this function's
// algorithm
size_t hash(char *key);

// Here follows the allocation function relative to the hashtable
hashtable_t *hashtable_create();

// Here are the hashtabl's write and read functions
void hashtable_write(hashtable_t *map, char *key, double value);
entry_t *hashtable_read(hashtable_t *map, char *key);

// Here is the print to the console's output
void hashtable_print(hashtable_t *map);

// Here follows the de-allocation function relative to the hashtable
void hashtable_delete(hashtable_t *map);

#endif
