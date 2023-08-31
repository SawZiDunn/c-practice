//
// Created by User on 12/30/2022.
//

#include "stdio.h"
int bubbleSort(int arr[], int len);
int printArray(int arr[],int len);

int main(){
    int myArr[]={5,4,3,2,1};
    int len = sizeof(myArr) / sizeof(myArr[0]);


    bubbleSort(myArr, len);


    return 0;
}

int bubbleSort(int arr[],int len){
    int i,j,temp;

    for(i=0;i<len-1;i++){

        for(j=0;j<len-i-1;j++){

            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printArray(arr,len);
}



int printArray(int arr[],int len){
    int i;
    for(i=0;i<len;i++){
        printf("%d ",arr[i]);
    }
}



