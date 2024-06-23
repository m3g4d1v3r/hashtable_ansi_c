#include "hashtable.h"

// Here's a simple implementation of the hash function:
// just multiply each character by a random number (such as 37)
// and accumulate all of the resulting sums. The resulting value
// is module'd by ARRAYMAX
size_t hash(char *key) {
    size_t result_idx = 0;

    while (*key != '\0') {
        result_idx += *key * 37;
        key++;
    }
    return (result_idx % ARRAYMAX);
}

// Allocate the hashtable and set all of the values to NULL, just
// in case.
hashtable_t *hashtable_create() {
    hashtable_t *map = malloc(sizeof(hashtable_t));

    for (size_t idx = 0; idx < ARRAYMAX; idx++) {
        map->array[idx] = NULL;
    }
    return (map);
}

// Write operation: this function writes a key-value pair to the
// hashtable structure
void hashtable_write(hashtable_t *map, char *key, double value) {
    size_t new_idx;
    entry_t *ptr, **ptr_ptr;

    if (map == NULL || key == NULL) return;
    new_idx = hash(key);
    ptr_ptr = &map->array[new_idx];

    // The following algorithm performs a linked-list traversal up
    // to the end of the current chosen list (chosen by result of the
    // hash function). In case there's a collision, then this traversal
    // would mitigate the hashtable collision.
    ptr = map->array[new_idx];
    while (ptr != NULL) {
        if (ptr->content.key == key) return;
        ptr_ptr = &ptr->next;
        ptr = ptr->next;
    }
    ptr = (entry_t *)malloc(sizeof(entry_t));
    ptr->content.key = key;
    ptr->content.value = value;
    ptr->next = NULL;
    *ptr_ptr = ptr;
}

// Read operation: this function reads a key-value pair from the
// hashtable structure
pair_t *hashtable_read(hashtable_t *map, char *key) {
    entry_t *ptr;

    if (map == NULL) return NULL;
    if (map->array[hash(key)] == NULL) return NULL;
    // Performs a linked-list traversal in order to search for the
    // provided key
    ptr = map->array[hash(key)];
    while (ptr != NULL) {
        if (strcmp(ptr->content.key, key) == 0)
            return (&ptr->content);
        ptr = ptr->next;
    }
    // If not found, return NULL
    return (NULL);
}

// This function prints all of the key-value pairs of the hashtable
// structure
void hashtable_print(hashtable_t *map) {
    for (size_t i = 0; i < ARRAYMAX; i++) {
        entry_t *curr_entry = map->array[i];
        while (curr_entry != NULL) {
            printf("idx[%zu]\tcurr_entry [%s]:\t%f\n",
                    i,
                    curr_entry->content.key,
                    curr_entry->content.value);
            curr_entry = curr_entry->next;
        }
    }
}

// De-allocate the hashtable for proper memory sanitizing
void hashtable_delete(hashtable_t *map) {
    for (size_t i = 0; i < ARRAYMAX; i++) {
        entry_t *curr_entry = map->array[i];
        while (curr_entry != NULL) {
            entry_t *temp = curr_entry;
            curr_entry = curr_entry->next;
            // Since the strings are allocated in the
            // stack, there's no need to free them here
            // free(temp->content.key) 
            free(temp);
        }
    }
    free(map);
}
