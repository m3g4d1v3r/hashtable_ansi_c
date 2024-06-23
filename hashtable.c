#include "hashtable.h"

size_t hash(char *key) {
    size_t result_idx = 0;

    while (*key != '\0') {
        result_idx += *key * 37;
        key++;
    }
    return (result_idx % ARRAYMAX);
}

hashtable_t *hashtable_create() {
    hashtable_t *map = malloc(sizeof(hashtable_t));

    for (size_t idx = 0; idx < ARRAYMAX; idx++) {
        map->array[idx] = NULL;
    }
    return (map);
}

void hashtable_write(hashtable_t *map, char *key, double value) {
    size_t new_idx;
    entry_t *ptr, **ptr_ptr;

    if (map == NULL || key == NULL) return;
    new_idx = hash(key);
    ptr_ptr = &map->array[new_idx];
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

entry_t *hashtable_read(hashtable_t *map, char *key) {
    if (map == NULL) return NULL;
    return (map->array[hash(key)]);
}

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

void hashtable_delete(hashtable_t *map) {
    for (size_t i = 0; i < ARRAYMAX; i++) {
        entry_t *curr_entry = map->array[i];
        while (curr_entry != NULL) {
            entry_t *temp = curr_entry;
            curr_entry = curr_entry->next;
            free(temp);
        }
    }
    free(map);
}
