//
// Created by User on 12/7/2022.
//
#include<stdio.h>
int main(){
    char data[5]={'a','b','c','d','e'};
    char *ptr;

    ptr=&data[0];

    printf("Pointer Value: %c\n",*ptr);
    printf("Pointer Value(ptr+1): %c\n",*(ptr+4));



    return 0;
}
