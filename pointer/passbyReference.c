//
// Created by User on 12/8/2022.
//

#include<stdio.h>

void swap(int *d1,int *d2);

int main(){
    int data1 = 10, data2 = 20;
    int *p;
    p = &data2; // or int *p = &data2, literally the same

    // reference is the memory address of a variable, it's literally pointer

    printf("data1 : %d\ndata2 : %d\n", data1, data2);
    swap(&data1,p); //pass by reference, p is literally %data2
    printf("data1 : %d\ndata2 : %d\n", data1, data2);

    return 0;
}

void swap(int *d1, int *d2){
    int temp = *d1;
    *d1 = *d2;
    *d2 = temp;

}
