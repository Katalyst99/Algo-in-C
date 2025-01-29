#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char key[50];
    char value[50];
} HashEntry;

void createHash(char keys[][50], char values[][50], int key_size, int value_size, HashEntry hashTable[]) {
    int min_size = (key_size < value_size) ? key_size : value_size;

    for (int i = 0; i < min_size; i++) 
    {
        strcpy(hashTable[i].key, keys[i]);
        strcpy(hashTable[i].value, values[i]);
    }

    for (int i = min_size; i < key_size; i++) 
    {
        strcpy(hashTable[i].key, keys[i]);
        strcpy(hashTable[i].value, "NULL");
    }
}

void printHash(HashEntry hashTable[], int size) 
{
    printf("{\n");
    for (int i = 0; i < size; i++) {
        printf("    \"%s\": \"%s\",\n", hashTable[i].key, hashTable[i].value);
    }
    printf("}\n");
}

int main() 
{
    char keys[][50] = {"name", "age", "city"};
    char values[][50] = {"Alice", "25", "New York"};

    int key_size = sizeof(keys) / sizeof(keys[0]);
    int value_size = sizeof(values) / sizeof(values[0]);

    HashEntry hashTable[MAX_SIZE];

    createHash(keys, values, key_size, value_size, hashTable);
    printHash(hashTable, key_size);

    return 0;
}
