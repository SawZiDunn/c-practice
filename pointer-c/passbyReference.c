//
// Created by User on 12/8/2022.
//
void swap(int *d1,int *d2);
#include<stdio.h>
int main(){
    int data1=10,data2=20;
    printf("data1 : %d\ndata2 : %d\n",data1,data2);
    swap(&data1,&data2); //pass by reference
    printf("data1 : %d\ndata2 : %d\n",data1,data2);




    return 0;
}

void swap(int *d1,int *d2){
    int a=*d1;
    *d1=*d2;
    *d2=a;

}
