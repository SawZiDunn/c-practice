//
// Created by User on 12/10/2022.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node; // struct node is defined as node

void print(struct node *ptr);
void insertAfter(node *prenode,int data_newnode);
void searchingData(node *myNode,int Data);
struct node* insertBeginning(node *next_node, int newData);
void insertBeginningREF(node **nextnode, int newData);

int main(){
    node *head = NULL;

    node *one = malloc(sizeof(struct node));
    one->data = 10; // (*one).data = 10;
    one->next = NULL;

    node *two = malloc(sizeof(struct node));
    two->data = 20;
    two->next = NULL;
    one->next = two;

    one = insertBeginning(one, 8);
    print(one);

    return 0;

}

void print(node *ptr){
    while(ptr != NULL){ // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next; // not necessary if we use for loop
    }

}
void insertAfter(node *prenode, int data_newnode){
    if(prenode == NULL){
        printf("Previous node is NUll.\n");
        return;
    }else{
        node *newNode = malloc(sizeof(struct node));
        newNode->next = prenode->next;
        prenode->next = newNode;
        newNode->data = data_newnode;
    }
}

void searchingData(node *myNode, int Data){
    int flag = 0;
    while (myNode != NULL){

        if(myNode->data == Data){
            flag = 1;
            break;
        }else{
            myNode = myNode->next;
        }
    }

    if(flag == 1){
        printf("We found your data.\n");
    }else{
        printf("Your data is not found.\n");
    }

}

struct node* insertBeginning(node *next_node, int newData){
    if(next_node == NULL){
        printf("Node is null.\n");
    }else{
        node *newNode= malloc(sizeof(struct node));
        newNode->data = newData;
        newNode->next = next_node;
        next_node = newNode;
        return next_node;
    }
}

void insertBeginningREF(node **nextnode, int newData){
    if(nextnode==NULL){
        printf("Node is null.\n");

    }else{
        node *newNode= malloc(sizeof(struct node));

        newNode->data = newData;
        newNode->next = (*nextnode);
        (*nextnode) = newNode;
    }

}