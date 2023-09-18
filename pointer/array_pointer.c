//
// Created by User on 12/7/2022.
//
#include<stdio.h>
int main(){
    char *string = "Hey!";

    printf("Pointer Value at index 0: %c\n",*string);
    printf("Pointer Value at index 1: %c\n",*(string + 1));
    printf("Pointer Value at index 2: %c\n",*(string + 2));
    printf("Pointer Value at index 2: %c\n", string[3]);

    printf("Printing string from index 0: %s\n", string);
    printf("Printing string from index 1: %s\n", string + 1);
    printf("Printing string from index 2: %s\n", string + 2);

    // If we add 1 to char, it only adds 1 byte to the char's memory address.
    // But, if we add 1 to int, it will add 4 bytes to the int's memory address.
    //That allows to see the next char or int in an array.

    printf("========================");

    int i, data[10],total=0;
    printf("Enter 10 numbers:\n");

    for(i = 0; i < 10; i++){
        printf("Your number:");
        // (data + i) is the memory address of data[i] or
        //               the memory address of index i of array data
        // thus, data[i] = *(data + i)
        scanf("%d", data + i);  //(data + i) = &(data[i])
        total += *(data+i);

    }
    printf("%d\n", total);
    for(int k = 0; k < 10; k++){
        printf("Number :%d  Memory Address :%x\n",data[k],data+k);

    }


    return 0;
}
