#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
    int isThreaded;
};

struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->isThreaded = 0;
    return temp;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);
    struct node* curr = root;
    struct node* parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (data < curr->data) {
            if (curr->left == NULL)
                break;
            curr = curr->left;
        } else {
            if (curr->isThreaded)
                break;
            curr = curr->right;
        }
    }
    struct node* newNode = createNode(data);
    if (data < parent->data)
        parent->left = newNode;
    else {
        newNode->right = parent->right;
        parent->right = newNode;
        parent->isThreaded = 0;
    }
    return root;
}

struct node* leftmost(struct node* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}

void inorder(struct node* root) {
    struct node* curr = leftmost(root);
    while (curr != NULL) {
        printf("%d ", curr->data);
        if (curr->isThreaded)
            curr = curr->right;
        else
            curr = leftmost(curr->right);
    }
}

int main() {
    struct node* root = NULL;
    int choice, data;
    while (1) {
        printf("1. Insert\n2. Display\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            root = insert(root, data);
        } else if (choice == 2) {
            inorder(root);
            printf("\n");
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}