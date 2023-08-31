//
// Created by User on 12/8/2022.
//
#include<stdio.h>
void passbyPointer(int *p1);

int main(){
    int *p;
    int data=25;
    p=&data;

    passbyPointer(p);
    printf("The value of data: %d",data);

    return 0;
}
void passbyPointer(int *p1){
    (*p1)++;

}
