#include <stdio.h>
#include <stdlib.h>

// structure to create a linkedList
typedef struct node {
    int data; 
    struct node* next; //pointer to the address of the next Node 
} node;

void printList(node* head){
    node* temp = head;
    while(temp != NULL){
        printf("Address: %p\tData: %d\tNext Address: %p\n",temp, temp->data, temp->next); //or we can write (*temp).next,(*temp).data
        temp = temp->next;
    }
}
node* createLinkedList(int n){

    int i = 0;

    node* head = NULL;
    node* temp = NULL;
    node* p = NULL; //used to traverse the linked list

    for( int i = 0; i < n; i++){
        temp = (node*)malloc(sizeof(node)); //give a memory block the size(in bytes) of a node, malloc returns a void pointer to the assigned memory block
        //printf("temp: %p\n", temp);
        printf("\nEnter the data for the node %d: ", i+1);
        scanf("%d", &(temp->data));
        
        //temp-data or (*temp).data does the same thing , it deferences the pointer, giving the actual struct
        // means: "Go to the struct pointed to by temp, then get its 'data' field"
        temp->next = NULL; //Set the next pointer of the current node (temp) to nothing

        if( head == NULL){ // used if the linked list is still empty, aka the first iteration of the loop
            head = temp; 
            printf("head: %p\n", head);
        }else{
            p = head;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = temp;
        }
    }

    return head;
}
int main(){
    node *head = NULL; //create a variable named head that will store the address of a node based upon where it lives in memory, but right node it points to nothing. ( a pointer to a node)
    int n = 0;

    printf("\nHow many nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n); //returns a pointer to the first node of the newly allocated linked listed, that returned pointer is stored in head
    printList(head);
    return 0;
}