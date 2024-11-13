#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(struct node* last, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
    } else {
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
    return last;
}

struct node* insert(struct node* last, int data, int pos) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    if (last == NULL) {
        last = temp;
        last->next = last;
    } else if (pos == 1) {
        temp->next = last->next;
        last->next = temp;
    } else {
        struct node* curr = last->next;
        for (int i = 1; i < pos - 1 && curr->next != last->next; i++)
            curr = curr->next;
        temp->next = curr->next;
        curr->next = temp;
        if (curr == last)
            last = temp;
    }
    return last;
}

struct node* delete(struct node* last, int pos) {
    if (last == NULL)
        return NULL;
    struct node* temp;
    if (pos == 1) {
        temp = last->next;
        if (last == last->next) {
            last = NULL;
        } else {
            last->next = temp->next;
        }
        free(temp);
    } else {
        struct node* curr = last->next;
        for (int i = 1; i < pos - 1 && curr->next != last->next; i++)
            curr = curr->next;
        temp = curr->next;
        curr->next = temp->next;
        if (temp == last)
            last = curr;
        free(temp);
    }
    return last;
}

struct node* reverse(struct node* last) {
    if (last == NULL || last->next == last)
        return last;
    struct node* prev = last;
    struct node* curr = last->next;
    struct node* next = curr->next;
    while (curr != last) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    return curr;
}

struct node* concatenate(struct node* last1, struct node* last2) {
    if (last1 == NULL)
        return last2;
    if (last2 == NULL)
        return last1;
    struct node* temp = last1->next;
    last1->next = last2->next;
    last2->next = temp;
    return last2;
}

void display(struct node* last) {
    if (last == NULL)
        return;
    struct node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    struct node* last1 = NULL;
    struct node* last2 = NULL;
    int choice, data, pos;
    while (1) {
        printf("1. Create\n2. Insert\n3. Delete\n4. Reverse\n5. Concatenate\n6. Display\n7. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                last1 = create(last1, data);
                break;
            case 2:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                last1 = insert(last1, data, pos);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                last1 = delete(last1, pos);
                break;
            case 4:
                last1 = reverse(last1);
                break;
            case 5:
                printf("Creating second list\n");
                printf("Enter data for second list: ");
                scanf("%d", &data);
                last2 = create(last2, data);
                last1 = concatenate(last1, last2);
                break;
            case 6:
                display(last1);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}