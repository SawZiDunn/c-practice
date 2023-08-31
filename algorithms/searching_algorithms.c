//
// Created by User on 12/30/2022.
//
#include "stdio.h"
#include "math.h"

int linear_search(int arr[], int toFind, int length);
int jumpSearch(int arr[], int len, int key);

int main(){
    int myArr[] = {2,3,5,6,7,8,25,36,41,50,60, 60, 60};

    int len = sizeof(myArr) / sizeof(myArr[0]);
    int key = 60;
    linear_search(myArr, key, len);

//    if (index >= 0){
//        printf("We found %d at index %d.", key, index);
//    }else{
//        printf("%d is not found.", key);
//    }

    return 0;
}

int linear_search(int arr[], int toFind, int length){
    int count = 0;

    for(int i=0 ; i<length; i++){

        if(arr[i] == toFind){
            count++;
            printf("We found at index %d.\n", i);

        }
    }

    if(count==0){
        printf("%d is not found.",toFind);
    }else{
        printf("We found %d ", toFind);
        printf("%d times.",count);
    }
}

int jumpSearch(int arr[], int len, int key){
    int step = sqrt(len);  // can also add floor()
    int low;
    low = 0;

    while (arr[step-1] < key){
        low = step;
        step = step + sqrt(len);
        if(step>len){
            step=len;
            break;
        }
    }

    for (int i=low;i<step;i++){
        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}