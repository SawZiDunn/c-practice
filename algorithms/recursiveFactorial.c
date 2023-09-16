//
// Created by User on 1/20/2023.
//
#include<stdio.h>
int finding_factorial(int key);

int main(){
    int key;

    printf("Enter the number you want the factorial of :");
    scanf("%d", &key);

    int result = finding_factorial(key);
    printf("The factorial of %d is %d.", key, result);

    return 0;
}

int finding_factorial(int key){
    if(key <= 1){
        return 1;
    }else{
        return key * finding_factorial(key - 1);

    }

}
