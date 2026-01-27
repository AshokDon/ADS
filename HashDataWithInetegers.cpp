#include <stdio.h>
#include <stdbool.h>

#define TABLE_SIZE 10

typedef struct HashMap {
    int key;
    bool is_occupied;
} HashMap;

HashMap hash_table[TABLE_SIZE];

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i].is_occupied = false;
    }
}

unsigned int hash(int key) {
    return key % TABLE_SIZE;
}

bool hash_table_insert(int key) {
    unsigned int idx = hash(key);
    unsigned int original_idx = idx;

    while (hash_table[idx].is_occupied) {
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == original_idx) return false;
    }

    hash_table[idx].key = key;
    hash_table[idx].is_occupied = true;
    return true;
}

HashMap* hash_table_lookup(int key) {
    unsigned int idx = hash(key);
    unsigned int original_idx = idx;

    while (hash_table[idx].is_occupied) {
        if (hash_table[idx].key == key) {
            return &hash_table[idx];
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == original_idx) break;
    }
    return NULL;
}

bool hash_table_delete(int key) {
    unsigned int idx = hash(key);
    unsigned int original_idx = idx;

    while (hash_table[idx].is_occupied) {
        if (hash_table[idx].key == key) {
            hash_table[idx].is_occupied = false;
            return true;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if (idx == original_idx) break;
    }
    return false;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hash_table[i].is_occupied) {
            printf("%d : -----\n", i);
        } else {
            printf("%d : %d\n", i, hash_table[i].key);
        }
    }
}

int main() {
    init_hash_table();
    print_table();

    hash_table_insert(10);
    hash_table_insert(20);
    hash_table_insert(30);
    hash_table_insert(21);

    print_table();

    HashMap *temp = hash_table_lookup(20);
    if (temp) {
        printf("Found %d\n", temp->key);
    } else {
        printf("Not found\n");
    }

    hash_table_delete(20);
    print_table();

    return 0;
}
