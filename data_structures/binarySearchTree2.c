//
// Created by User on 7/1/2023.
//

#include<stdio.h>
#include<stdlib.h>

void insert_numbers();
struct Node * create_node(int data);
struct Node * creating_bst_in_detail(int start, int end);
void preOrder(struct Node* node);

struct array{
    int num_array[1000];
    int index;
};

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct array arr;

int main(){
    insert_numbers();

    int n = sizeof(arr.num_array) / sizeof(arr.num_array[0]);  //finding array length

    struct Node* root = creating_bst_in_detail(0, n-1);

    preOrder(root);

    return 0;
}


void insert_numbers(){
    arr.index = 0;

    for (int i = 1; i<=1000; i++){
        arr.num_array[arr.index] = i;
        arr.index++;

    }
}

struct Node * create_node(int data){
    struct Node * new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

//the most important function
struct Node * creating_bst_in_detail(int start, int end){


    if (start > end){
        return NULL;
    }

    int mid = (start + end) / 2;


    struct Node* root = create_node(arr.num_array[mid]);

    root->left = creating_bst_in_detail(start, mid-1);
    root->right = creating_bst_in_detail(mid +1, end);

    return root;

}

void preOrder(struct Node* node)
{
    if (node == NULL)
        return;

    printf("%d ", node->data);

    preOrder(node->left);
    preOrder(node->right);
}







