//
// Created by User on 12/7/2022.
//
#include<stdio.h>

int main(){
    int age=20;

    int *p=&age;

    printf("Address of age is %x.\n", &age);
    printf("Memory address is %x\n", p);

    printf("Pointer is %d\n", *p);
    printf("Value is %d.\n", age);



    return 0;
}