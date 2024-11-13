#include <stdio.h>
#include <stdlib.h>

// Node structure for Singly Linked List
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Create a new node
void createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Display the linked list
void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
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
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Reverse the linked list
void reverse() {
    struct Node *prev = NULL, *current = head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Delete the first node
void deleteStart() {
    if (head == NULL) return;
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete the last node
void deleteEnd() {
    if (head == NULL) return;
    struct Node* temp = head;
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
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
