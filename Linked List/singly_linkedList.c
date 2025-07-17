#include <stdio.h>
#include <stdlib.h>

// structure to create a linkedList
typedef struct node {
    int data; 
    struct node* next; //pointer to the address of the next Node 
} node;

void printList(node* head){
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        printf("Address: %p\tData: %d\n",temp->next, temp->data); //or we can write (*temp).next,(*temp).data
        printf("Test what is TEMP: %p", (void*)temp); 
    }
}
node* createLinkedList(int n){

    int i = 0;

    node* head = NULL;
    node* temp = NULL;
    node* p = NULL; //used to traverse the linked list

    for( int i = 0; i < n; i++){
        temp = (node*)malloc(sizeof(node)); //give a memory block the size(in bytes) of a node, malloc returns a void pointer to the assigned memory block
        printf("temp: %p", temp);
        printf("\nEnter the data for the node %d: ", i+1);
        scanf("%d ", &(temp->data));
        
        printf (" %d ", temp->data);
        temp->next = NULL; // or (*temp).data = NULL does the same thing

        if( head == NULL){ // used if the linked list is still empty, aka the first iteration of the loop
            head = temp; 
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
    node *head = NULL;
    int n = 0;

    printf("\nHow many nodes: ");
    scanf("%d", &n);
    head = createLinkedList(n);
    printList(head);
    return 0;
}