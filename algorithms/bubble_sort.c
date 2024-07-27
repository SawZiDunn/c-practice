//
// Created by User on 12/30/2022.
//

#include "stdio.h"

int bubbleSort(int arr[], int n);
int printArray(int arr[],int len);

int main(){
    int myArr[]={5,4,3,2,1, 0, 5, 7, 8};
    int n = sizeof(myArr) / sizeof(myArr[0]);

    bubbleSort(myArr, n);
    return 0;
}

int bubbleSort(int arr[], int n){
    int i, j, temp;

    for(i = 0; i < n - 1; i++){

        for(j = 0; j < n - i - 1; j++){

            if(arr[j] > arr[j + 1]){
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printArray(arr, n);
    return 0;
}

int printArray(int arr[],int len){
    int i;
    for(i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}



