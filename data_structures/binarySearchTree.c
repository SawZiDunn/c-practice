//
// Created by User on 12/25/2022.
//
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int key){
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

struct node* insertNode(struct node* root,int key){
    if(root==NULL){
        return createNode(key);
    }

    if(key<root->data){
        root->left=insertNode(root->left,key);

    }else if(key> root->data){
        root->right=insertNode(root->right,key);
    }
    return root;
}

void inOrderTraversal(struct node *node){
    if(node!=NULL){
        inOrderTraversal(node->left);
        printf("Data :%d\n", node->data);
        inOrderTraversal(node->right);

    }
}

void search(struct node * node,int tofind){
    if(node!=NULL){
        search(node->left, tofind);
        if(node->data==tofind){
            printf("We found %d.",node->data);
            return;
        }
        search(node->right, tofind);

    }
}

int main(){
    struct node *root=NULL;
    root=insertNode(root,55);
    root= insertNode(root,45);
    root= insertNode(root,65);
    root= insertNode(root,35);
    root= insertNode(root,54);
    root= insertNode(root,64);
    root= insertNode(root,66);
    root= insertNode(root,1);
    root= insertNode(root,2);
    root= insertNode(root,9);
    root= insertNode(root,58);

    inOrderTraversal(root);
    search(root,63);

    return 0;
}