#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
struct node* root= NULL;

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* insert(struct node* root, int data){
    if(root== NULL){
        return createnode(data);
    }
    if(data> root->data){
        root->right= insert(root->right, data);
    }
    else if(data< root->data){
        root->left= insert(root->left, data);
    }
    return root;
}


void inorder(struct node* root){
    if(root!= NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root!= NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int search(struct node* root, int key){
    if(root == NULL ){
        return 0;
    }
    if(root->data==key){
        return 1;
    } 

    else if(key < root->data){
        return search(root->left, key);
    }
    else {
        return search(root->right,key);
    }
}

struct node* deleteLeafNode(struct node* root, int key) {
    if(root==NULL){
        return root;
    }

    if(key < root->data){
        root->left= deleteLeafNode(root->left, key);
    }
    else if( key> root->data){
        root->right= deleteLeafNode(root->right, key);
    }

    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            return NULL;
        }
        else{
            printf("value is not a leaf node! \n");
        }
    }
    return root;
}

struct node* findMin(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;  
}

struct node* findMax(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;  
}

struct node* deleteNode(struct node* root, int key) {
    if(root==NULL){
        return root;
    }

    if(key < root->data){
        root->left= deleteNode(root->left, key);
    }
    else if( key> root->data){
        root->right= deleteNode(root->right, key);
    }

    else{
        if(root->right==NULL){
            struct node* temp= root->left;
            free(root);
            return temp;
        }
        else if (root->left== NULL){ 
            struct node* temp= root->right;
            free(root);
            return temp;
        }
        else {
            struct node* temp = findMin(root->right);  
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);  
        }
    }
    return root;
}


int main() {
    root= insert(root,25);
    root= insert(root, 9);
    root= insert(root, 19);
    root= insert(root, 14);
    root= insert(root, 16);
    root= insert(root, 2);
    root= insert(root, 9);
    printf("\nInorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    
    if(search(root,16)){
        printf("16 is present in the given BST!!\n");
    }
    else {
        printf("16 is not present in the given BST!!\n");
    }
   
    deleteLeafNode(root,16);
    printf("After deletion: ");
    inorder(root);   
    printf("\n");

    root= deleteNode(root,25);
    printf("After deletion: ");
    inorder(root);
    printf("\n");
    return 0;
}