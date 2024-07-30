#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Building HashMap
#define MAX_NAME 256
#define TABLE_SIZE 10
typedef struct HashMap{
    char name[MAX_NAME];
    int age;
    bool is_occupied;
} HashMap;

HashMap hash_table[TABLE_SIZE];

void init_hash_table(){
    for(int i = 0 ; i < TABLE_SIZE ; i++){
        hash_table[i].is_occupied = false;
    }
}

unsigned int hash(char *name){
    unsigned int hash_value = 0;
    int length = strlen(name);
    for(int i = 0 ; i < length ; i++){
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }
    return hash_value;
}

bool hash_table_insert(HashMap *h){
    if(strlen(h->name) == 0) return false;

    unsigned int idx = hash(h->name);
    unsigned int original_idx = idx;
    while(hash_table[idx].is_occupied){
        idx = (idx + 1) % TABLE_SIZE;
        if(idx == original_idx) return false;
    }
    hash_table[idx] = *h;
    hash_table[idx].is_occupied = true;
    return true;
}

HashMap* hash_table_lookup(char *name){
    unsigned int idx = hash(name);
    unsigned int original_idx = idx;
    while(hash_table[idx].is_occupied){
        if(strcmp(hash_table[idx].name, name) == 0){
            return &hash_table[idx];
        }
        idx = (idx + 1) % TABLE_SIZE;
        if(idx == original_idx) break;
    }
    return NULL;
}

bool hash_table_delete(char *name){
    unsigned int idx = hash(name);
    unsigned int original_idx = idx;
    while(hash_table[idx].is_occupied){
        if(strcmp(hash_table[idx].name, name) == 0){
            hash_table[idx].is_occupied = false;
            return true;
        }
        idx = (idx + 1) % TABLE_SIZE;
        if(idx == original_idx) break;
    }
    return false;
}

void print_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!hash_table[i].is_occupied) {
            printf("\t%i\t-----\n", i);
        } else {
            printf("\t%i\t%s - %d\n", i, hash_table[i].name, hash_table[i].age);
        }
    }
}

int main(){
    init_hash_table();
    print_table();

    HashMap Ashok = {.name = "Ashok", .age = 29, .is_occupied = true};
    HashMap Pavan = {.name = "Pavan", .age = 26, .is_occupied = true};
    HashMap Ram = {.name = "Ram", .age = 1000, .is_occupied = true};

    hash_table_insert(&Ashok);
    hash_table_insert(&Pavan);
    hash_table_insert(&Ram);
    print_table();

    HashMap *temp = hash_table_lookup("Ashok");
    if (temp == NULL) {
        printf("Person not found.\n");
    } else {
        printf("Found %s, age %d.\n", temp->name, temp->age);
    }

    if (hash_table_delete("Ashok")) {
        printf("Deleted Ashok.\n");
    } else {
        printf("Person not found for deletion.\n");
    }

    print_table();
    return 0;
}
