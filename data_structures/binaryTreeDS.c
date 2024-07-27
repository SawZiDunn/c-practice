//
// Created by User on 12/19/2022.
//
#include<stdio.h>
#include "stdlib.h"
struct node* createNode(int key);
void insertToRight(struct node* whichNode,int key);
void insertToLeft(struct node* whichNode,int key);

struct node{
    int data;
    struct node *left;
    struct node *right;
};

int main(){
    struct node *root=createNode(15);
    insertToRight(root,5);
    insertToLeft(root,10);


    return 0;
}

struct node* createNode(int key){
    struct node *newNode= (struct node*)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

void insertToRight(struct node* whichNode,int key){
    whichNode->right=createNode(key);
}
void insertToLeft(struct node* whichNode,int key){
    whichNode->left=createNode(key);
}