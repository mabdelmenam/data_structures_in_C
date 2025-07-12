#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//HashNode: to store a key-value pair
//HashTable: to store the array of pointers to chains(linked lists)

#define TABLE_SIZE 100

typedef struct HashNode {
    //I will declare a variable named ' key ' that will point to a char
    char* key; 
    char* value;
    struct HashNode* next; //pointer to another HashNode struct
} HashNode; 

//used to store an array of pointers to chains(linked list)
typedef struct HashTable {
    HashNode* buckets[TABLE_SIZE]; //each item in the buckets array is not a HashNode but a pointer to a HashNode
} HashTable;

int main(){
    return 0;
}
//Hash function
unsigned int hash (const char* key){
    unsigned long hash = 5381;
    int c; 

    while((c = *key++)){
        hash = hash * 33 + c;
    }

    return hash % TABLE_SIZE;
}
