#include <stdlib.h>
#include <stdio.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
    struct node* prev;
};
typedef struct node node;


void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
void insert(int data, node* root);
node* generate_node(int data);
node* generate_bst(int* arr, size_t size);
node* search(int data, node* root);
void delete(int target, node* root);
int find_greatest_number(int* arr, size_t size);

int main(){
    int arr[] = {1, 23, 4, 6, 100};

    size_t size = sizeof(arr)/sizeof(int);
    node* root = generate_bst(arr, size);
    inorder(root);
    delete(6, root);
    inorder(root);

    return 0;
}


node* generate_node(int data){
    node* n = (node*)malloc(sizeof(node));
    
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->prev = NULL;

    return n;
}


node* generate_bst(int* arr, size_t size){
    node* root;

    for(size_t i = 0; i < size; i++){
        if (root == NULL){
            root = generate_node(find_greatest_number(arr, size));
        }

        if (!(root->data == arr[i])){
            insert(arr[i], root);
        }
    }

    return root;
}


void insert(int data, node* root){
    if (root == NULL){
        root = generate_node(data);
    } 
    else if(data < root->data && root->left == NULL) {
        root->left = generate_node(data);
        root->left->prev = root;
    } 
    else if(data > root->data && root->right == NULL) {
        root->right = generate_node(data);
        root->right->prev = root;
    }
    else if(data < root->data && root->left != NULL) {
        insert(data, root->left);
    } 
    else if(data > root->data && root->right != NULL) {
        insert(data, root->right);
    }
}


void inorder(node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

void preorder(node* root){
    if(root != NULL){
        printf("%d\n", root->data);
        inorder(root->left);
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root != NULL){
        inorder(root->left);
        inorder(root->right);
        printf("%d\n", root->data);
    }
}

node* search(int data, node* root) {
    if(root->data == data) {
        printf("\n%d found\n", data);
        return root;
    }
    else if(data < root->data && root->left != NULL) {
        search(data, root->left);
    }
    else if(data > root->data && root->right != NULL) {
        search(data, root->right);
    }
    else {
        printf("\n%d not found\n", data);
    }
}

void delete(int target, node* root) {
    if(target != root->data){
        node* target_node = search(target, root);

        if(target_node->right == NULL && target_node->left == NULL) {
            if(target_node->data > target_node->prev->data) {
                target_node->prev->right = NULL;
            } 
            else if(target_node->data < target_node->prev->data) {
                target_node->prev->left = NULL;
            }
        }
        else if((target_node->right == NULL && target_node->left != NULL) || (target_node->right != NULL && target_node->left == NULL)){
            if(target_node->data > target_node->prev->data) {
                target_node->prev->right = target_node->right;
            } 
            else if(target_node->data < target_node->prev->data) {
                target_node->prev->left = target_node->left;
            }
        }
        else if(target_node->right != NULL && target_node->left != NULL) {
            if(target_node->data > target_node->prev->data) {
                node* tleft = target_node->left;
                target_node->prev->right = target_node->right;
                target_node->prev->right->right = NULL;
                target_node->prev->right->left = NULL;
            } 
            else if(target_node->data < target_node->prev->data) {
                node* tleft = target_node->left;
                target_node->prev->left = target_node->right;
                target_node->prev->left->right = NULL;
                target_node->prev->left->left = NULL;
            }
        }
        printf("\n%d deleted\n\n", target);
    } 
    else {
        printf("\ncannot delete root data\n\n");
    }
}

int find_greatest_number(int* arr, size_t size) {
    int greatest = 0;
    for(size_t i = 0; i < size; i++) {
        if(arr[i] > greatest) {
            greatest = arr[i];
        }
    }
    return greatest;
}
