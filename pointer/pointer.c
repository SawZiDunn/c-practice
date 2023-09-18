//
// Created by User on 12/7/2022.
//
#include<stdio.h>

int main(){
    int age = 20;
    int *p = &age;

    printf("Memory address of the age variable is %p.\n", &age);
    printf("Memory address of the age variable is %p.\n", p);

    printf("Memory address of the pointer variable p is %x\n", *p);
    // use *p to get the actual value, i.e, tha value the pointer is pointing

    printf("The value of age is %d.\n", *p);

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