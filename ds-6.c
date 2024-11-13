#include <stdio.h>
#include <stdlib.h>

// Node structure for Doubly Linked List
struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* head = NULL;

// Create a new node
void createNode(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

// Display the linked list
void display() {
    struct DNode* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertStart(int value) {
    createNode(value);
}

// Insert at the end
void insertEnd(int value) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct DNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Reverse the linked list
void reverse() {
    struct DNode* temp = NULL;
    struct DNode* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

// Delete the first node
void deleteStart() {
    if (head == NULL) return;
    struct DNode* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
}

// Delete the last node
void deleteEnd() {
    if (head == NULL) return;
    struct DNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
}

// Main Function
int main() {
    int choice, value;
    while (1) {
        printf("\nMenu:\n1. Create Node\n2. Display\n3. Insert Start\n4. Insert End\n5. Reverse\n6. Delete Start\n7. Delete End\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to create: ");
                scanf("%d", &value);
                createNode(value);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter value to insert at start: ");
                scanf("%d", &value);
                insertStart(value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertEnd(value);
                break;
            case 5:
                reverse();
                printf("List reversed.\n");
                break;
            case 6:
                deleteStart();
                printf("First node deleted.\n");
                break;
            case 7:
                deleteEnd();
                printf("Last node deleted.\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
