//
// Created by User on 12/7/2022.
//
#include<stdio.h>
int main(){
    int i, data[10],total=0;
    printf("Enter 10 numbers:\n");

    for(i=0;i<10;i++){
        printf("Your number :");
        scanf("%d",data+i);
        total+=*(data+i);



    }
    printf("%d\n",total);
    for(int k=0;k<10;k++){
        printf("Number :%d  Memory Address :%x\n",data[k],data+k);

    }
    return 0;
}