//
// Created by User on 12/7/2022.
//
// Changing Constant Value using pointer
#include<stdio.h>
int main() {
    const int num = 25;
    int *ptr;
    ptr = &num;
    printf("Before changing: %d\n", num);
    *ptr = 58;
    printf("After changing: %d", num);


    return 0;
}