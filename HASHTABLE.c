#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person *next;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strlen(name);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
}

bool hash_table_insert(person *p) {
    if (p == NULL) return false;
    int idx = hash(p->name);
    p->next = hash_table[idx];
    hash_table[idx] = p;
    return true;
}

person *hash_table_lookup(char *name) {
    int idx = hash(name);
    person *temp = hash_table[idx];
    while (temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0) {
        temp = temp->next;
    }
    return temp;
}

person *hash_table_delete(char *name) {
    int idx = hash(name);
    person *temp = hash_table[idx];
    person *prev = NULL;
    while (temp != NULL && strncmp(temp->name, name, MAX_NAME) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return NULL;
    if (prev == NULL) {
        hash_table[idx] = temp->next;
    } else {
        prev->next = temp->next;
    }
    return temp;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hash_table[i] == NULL) {
            printf("\t%i\t-----\n", i);
        } else {
            person *temp = hash_table[i];
            printf("\t%i\t", i);
            while (temp != NULL) {
                printf("%s - %d -> ", temp->name, temp->age);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    init_hash_table();
    print_table();

    person Ashok = {.name = "Ashok", .age = 29};
    person Pavan = {.name = "Pavan", .age = 26};
    person Ram = {.name = "Ram", .age = 1000};

    hash_table_insert(&Ashok);
    hash_table_insert(&Pavan);
    hash_table_insert(&Ram);
    print_table();

    person *temp = hash_table_lookup("Ashok");
    if (temp == NULL) {
        printf("Person not found.\n");
    } else {
        printf("Found %s, age %d.\n", temp->name, temp->age);
    }

    temp = hash_table_delete("Ashok");
    if (temp != NULL) {
        printf("Deleted %s.\n", temp->name);
    } else {
        printf("Person not found for deletion.\n");
    }

    print_table();
    return 0;
}
