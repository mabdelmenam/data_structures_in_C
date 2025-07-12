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

//Hash function
unsigned int hash (const char* key){
    unsigned long hash = 5381;
    int c; 

    while((c = *key++)){
        hash = hash * 33 + c;
    }

    return hash % TABLE_SIZE;
}

//Insert function - inserts a new key-value pair into the hash table or updates the value if the key already exists

void insert(HashTable* table, const char* key, const char* value){
    int index = hash(key); 

    //Hey table, give me the pointer to first node (HashNode) at this index and ill walk through it using a pointer called "current"
    //current is a pointer to the current node were examining in the chain or linked list
    //current-key is the key stored inside that node
    //key is the key were trying to insert
    //buckets[index] is a pointer to the first node
    HashNode* current = table->buckets[index];

    while( current != NULL ){ //looping through linkedlist in the current bucket 
        if (strcmp(current->key, key) == 0){ // if the key were inserting " current->key" is equal to the key already in the linked list, then we 
            //need to update the value for that key
            free(current->value); //free the current value in the node
            current->value = strdup(value); //update it with the new value
            return;
        }
        current = current->next;
    }

        HashNode* newNode = malloc(sizeof(HashNode));
        newNode->key = strdup(key);
        newNode->value = strdup(value);

        //Make the new node point to whatever the current first node is in the bucket
        newNode->next = table->buckets[index];

        table->buckets[index] = newNode;
}

//Print function
void print_table(HashTable* table){
    for(int i = 0; i< TABLE_SIZE; i++){
        HashNode* node = table->buckets[i]; //This declares a pointer to HashNode, node is a variable that stores the address of HashNode in memory
        if(node != NULL){
            printf("Bucket number %d: \n", i);
            while( node != NULL )//looping through the linked list or chain
            {
                printf("%s => %s \n", node->key, node->value);
                node = node->next;
            }

        }
    }
}

int main(){

    HashTable* table = malloc(sizeof(HashTable));

    for(int i = 0;i < TABLE_SIZE;i++){
        table->buckets[i] = NULL;
    }

     // Insert test entries
    insert(table, "cat", "meow");
    insert(table, "dog", "bark");
    insert(table, "cow", "moo");
    insert(table, "cat", "purr"); // Should update "cat" value

    // Print results
    printf("=== Hash Table Contents ===\n");
    print_table(table);
    return 0;
}
