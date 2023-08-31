//
// Created by User on 12/10/2022.
//
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void print(struct node *hello);
void insertAfter(struct node *prenode,int data_newnode);
void searchingData(struct node *myNode,int Data);
struct node* insertBeginning(struct node *nextnode, int newData);
void insertBeginningREF(struct node **nextnode, int newData);

int main(){
    struct node *head=NULL;

    struct node *one= malloc(sizeof(struct node));
    one->data=10;
    one->next=NULL;

    struct node *two= malloc(sizeof(struct node));
    two->data=20;
    two->next=NULL;
    one->next=two;

    two= malloc(sizeof(struct node));
    two->data=30;
    two->next=NULL;
    one->next->next=two;

//    insertAfter(three,40);
//    print(one);
//    searchingData(one,10);
//    struct node *newNode=insertBeginning(one,9);
//    print(newNode);
    insertBeginningREF(&one, 8);
    print(one);

    return 0;

}

void print(struct node *hello){
    while(hello!=NULL){
        printf("data :%d\n",hello->data);
        hello=hello->next;
    }

}
void insertAfter(struct node *prenode,int data_newnode){
    if(prenode==NULL){
        printf("Previous node is NUll.");
        return;
    }else{
        struct node *newNode=malloc(sizeof(struct node));
        newNode->next=prenode->next;
        prenode->next=newNode;
        newNode->data=data_newnode;
    }
}

void searchingData(struct node *myNode,int Data){
    int flag=0;
    while(myNode!=NULL){

        if(myNode->data==Data){
            flag=1;
            break;
        }else if(myNode->data!=Data){
            myNode=myNode->next;
        }
    }
    if(flag==1){
        printf("We found your data.\n");
    }else{
        printf("Your data is not found.\n");
    }

}

struct node* insertBeginning(struct node *nextnode, int newData){
    if(nextnode==NULL){
        printf("Node is null.");
    }else{
        struct node *newNode= malloc(sizeof(struct node));
        newNode->data=newData;
        newNode->next=nextnode;
        nextnode=newNode;
        return nextnode;
    }

}

void insertBeginningREF(struct node **nextnode, int newData){
    if(nextnode==NULL){
        printf("Node is null.");
    }else{
        struct node *newNode= malloc(sizeof(struct node));
        newNode->data=newData;
        newNode->next=(*nextnode);
        (*nextnode)=newNode;
    }

}