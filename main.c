#include "hashtable.h"

int main() {
    hashtable_t *dictionary;
    pair_t groceries_array[] = {
        {"Apples", 1.50},
        {"Bananas", 0.60},
        {"Bread", 2.50},
        {"Milk", 3.00},
        {"Eggs", 2.20},
        {"Chicken", 4.80},
        {"Beef", 5.50},
        {"Rice", 1.20},
        {"Pasta", 1.10},
        {"Orange", 3.40},
        {"Carrots", 1.00},
        {"Potatoes", 0.90}
    };
    size_t array_len = sizeof(groceries_array) / sizeof(pair_t);

    dictionary = hashtable_create();
    for (size_t idx = 0; idx < array_len; idx++) {
        hashtable_write(dictionary, groceries_array[idx].key,
                                    groceries_array[idx].value);
    }
    hashtable_print(dictionary);
    hashtable_delete(dictionary);
    return (0);
}
