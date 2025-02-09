//
// Created by User on 12/7/2022.
//
#include<stdio.h>

int main(){
    const int num = 25;
    int *ptr = &num;

    printf("Before changing: %d\n", num);
    *ptr = 58;
    printf("After changing: %d\n", num);

    char *string = "Hello World";  //using string in C
    printf("%s\n", string);

    char *str;
    str = "How are you?";
    printf("%s\n", str);


    return 0;
}