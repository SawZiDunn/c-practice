#include "stdio.h"
#include "math.h"

int jumpSearch(int arr[], int len, int key);

int main(){
    int myArr[] = {2,3,5,6,7,8,25,36,41,50,60,61,62,63,64,68,69,70,71};

    int len = sizeof(myArr) / sizeof(myArr[0]);
    int key = 61;
    int index = jumpSearch(myArr, len, key);

    if (index >= 0){
        printf("We found %d at index %d.", key, index);
    }else{
        printf("%d is not found.", key);
    }

    return 0;
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

    int median = (low + step)/2;
    if(arr[median] == key){
        return median;
    }else if(arr[median] > key){
        step = median-1;
    }else{
        low = median+1;
    }

    for (int i=low;i<step;i++){
        if(arr[i] == key){
            return i;
        }
    }

    return -1;
}


