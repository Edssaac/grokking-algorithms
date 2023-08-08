#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char key[50];
    int value;
} Box;

typedef struct {
    Box* boxes[MAX_SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* table = (HashTable*) malloc(sizeof(HashTable));

    for (int i = 0; i < MAX_SIZE; i++) {
        table->boxes[i] = NULL;
    }

    return table;
}

int calculateIndex(char* key) {
    int sum = 0;

    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }

    return sum % MAX_SIZE;
}

void insertOnHashTable(HashTable* table, char* key, int value) {
    int index = calculateIndex(key);
    Box* elemento = (Box*) malloc(sizeof(Box));

    strcpy(elemento->key, key);
    elemento->value = value;
    table->boxes[index] = elemento;
}

int searchOnHashTable(HashTable* table, char* key) {
    int index = calculateIndex(key);
    Box* elemento = table->boxes[index];

    if (elemento != NULL && strcmp(elemento->key, key) == 0) {
        return elemento->value;
    }

    return -1; // Not found
}

void removeFromHashTable(HashTable* table, char* key) {
    int index = calculateIndex(key);
    Box* elemento = table->boxes[index];

    if (elemento != NULL && strcmp(elemento->key, key) == 0) {
        free(elemento);
        table->boxes[index] = NULL;
    }
}

void freeHashTable(HashTable* table) {
    for (int i = 0; i < MAX_SIZE; i++) {
        if (table->boxes[i] != NULL) {
            free(table->boxes[i]);
        }
    }

    free(table);
}

int main() {
    HashTable* table = createHashTable();

    insertOnHashTable(table, "key_1", 10);
    insertOnHashTable(table, "key_2", 20);
    insertOnHashTable(table, "key_3", 30);

    printf("%d\n", searchOnHashTable(table, "key_2"));

    removeFromHashTable(table, "key_1");

    printf("%d\n", searchOnHashTable(table, "key_1"));

    freeHashTable(table);

    return 0;
}
