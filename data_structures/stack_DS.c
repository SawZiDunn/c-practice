#include "stdio.h"
#include "stdlib.h"
#define MAX 5

struct stack{
    int data[MAX];
    int top;
};

typedef struct stack st;

st *createEmptyStack(){
    st *st1 = malloc(sizeof(st));
    st1->top = -1;
    return st1;
}

int isEmpty(st *myStack){
    if(myStack->top == -1){
        printf("\nStack is empty.\nYou cannot print any data.\n");
        return 1;
    }else{
        return 0;
    }
}

int isFull(st *myStack){
    if(myStack->top >= MAX-1){
        printf("Stack is full.");
        return 1;
    }else{
        return 0;
    }
}

void push(st *myStack, int key){
    if(!isFull(myStack)){
        myStack->top++;
        myStack->data[myStack->top] = key;
    }
}

void pop(st *myStack){
    if(!isEmpty(myStack)){
        printf("Data :%d\n", myStack->data[myStack->top]);
        myStack->top--;
    }
}

void printStack(st *myStack){
    printf("You have %d numbers in your stack!\n", myStack->top + 1);
    while(myStack->top != -1){
        pop(myStack);
    }
}

int main(){
    st *myStack = createEmptyStack();

    push(myStack, 5);
    push(myStack, 6);
    push(myStack, 7);
    pop(myStack);

    printStack(myStack);
    return 0;
}
