#include <assert.h>
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

    // Allocate
    dictionary = hashtable_create();

    // Write
    for (size_t idx = 0; idx < array_len; idx++) {
        hashtable_write(dictionary, groceries_array[idx].key,
                                    groceries_array[idx].value);
    }
    // Print everything
    hashtable_print(dictionary);

    // Test 1 - Existing Pair
    pair_t expected_1 = {"Eggs", 11.50};
    pair_t *result_1 = hashtable_read(dictionary, "Eggs");
    assert(result_1 != NULL);
    assert(strcmp(result_1->key, expected_1.key) == 0);
    assert(result_1->value == expected_1.value);

    // Test 2 - Existing Key, But different Value
    pair_t expected_2 = {"Potatoes", 1.70};
    pair_t *result_2 = hashtable_read(dictionary, "Potatoes");
    assert(result_2 != NULL);
    assert(strcmp(result_2->key, expected_2.key) == 0);
    assert(result_2->value != expected_2.value);

    // Test 3 - Non Existing Pair
    pair_t *result_3 = hashtable_read(dictionary, "Cheese");
    assert(result_3 == NULL);

    // De-allocate
    hashtable_delete(dictionary);
    return (0);
}
