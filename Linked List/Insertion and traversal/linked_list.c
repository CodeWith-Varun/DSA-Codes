#include <stdio.h>
#include <stdlib.h>

// structure for a node in the linked list
// used typedef just for the sake of simplisity
typedef struct node {
    int data;
    struct node *next;  // pointer to the next node
} List;

// Method for inserting the data at the beginning
List *insertionInBeginning(List *head, int data) {
    // case when list is empty
    if(head == NULL) {
        // allocating space of size List and proving its reference to head pointer
        // i.e., storing the address of that memory in the head pointer
        head = (List *) malloc(sizeof(List));
        // adding the data
        head->data = data;
        // As the list is empty that's why this is the last node as well so next pointer is also NULL
        head->next = NULL;

    // case when list is not empty
    } else {
        // creating a new node using the above method
        List *node = (List *) malloc(sizeof(List));
        // adding the data in the node
        node->data = data;
        // making the next pointer equals to head... that is creating a link between new node and earlier first node
        node->next = head;
        // making head pointer equals to node that is creating this node as first
        head = node;
    }
    return head;
}

List *insertionInEnd(List *head, int data) {
    // Empty list case
    if(head == NULL) {
        head = (List *) malloc(sizeof(List));
        head->data = data;
        head->next = NULL;
    } else {
        // creating a temporary variable
        List *temp = head;
        // Iterating over the list to get the pointer to the last node
        while(temp->next != NULL) {
            temp = temp->next;
        }
        // Now temp points to the last node
        // creating a new node using the above method
        List *node = (List *) malloc(sizeof(List));
        // adding the data in the node
        node->data = data;
        // making the next pointer of this node as NULL as this is the last node
        node->next = NULL;
        // making a link between earlier last node and this new node
        temp->next = node;
    }
    return head;
}

List *insertionAtPosition(List *head, int data, int position) {
    // Empty list case
    if(head == NULL) {
        head = (List *) malloc(sizeof(List));
        head->data = data;
        head->next = NULL;
    } else {
        List *temp = head;
        // Iterating over the list to get the pointer pointing to the node present at position = position - 1
        for(int i=1; i<position && temp->next != NULL; i++) {
            temp = temp->next;
        }
        // temp points to the node at position - 1
        // creating a new node using the above method
        List *node = (List *) malloc(sizeof(List));
        // adding the data in the node
        node->data = data;
        // creating a link between new node and node present at position = position (node present at temp->next)
        node->next = temp->next;
        // creating a link between node present at position - 1 (temp node) and this new node
        temp->next = node;
    }
    return head;
}

void printList(List *head) {
    // Using a temporary variable temp equals to head initially
    List *temp = head;
    // ITerating over the list
    while(temp->next != NULL) {
        // Printing the data
        printf("%d -> ", temp->data);
        // Incrementing the temp pointer
        temp = temp->next;
    }
    // Printing the data in the last node
    printf("%d\n",temp->data);
}

int main()
{
    List *head = NULL;
    head = insertionAtPosition(head, 1, 1);
    printList(head);
    head = insertionAtPosition(head, 2, 1);
    printList(head);
    head = insertionAtPosition(head, 3, 1);
    printList(head);
    return 0;
}