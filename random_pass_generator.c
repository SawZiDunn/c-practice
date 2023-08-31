//
// Created by User on 12/4/2022.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    srand(time(NULL));
    int count =0;

    int pass[10];

    for (int i = 0; i < 50; i++) {
        int x = rand() % 123;
        if (x >= 48 && x<123) {

            pass[count]=x;
            count++;

            if (count==10){
                break;
            }

            }

        }
    printf("Our Generated Password : ");

    for(int k=0;k<10;k++){
        printf("%c",pass[k]);
    }

    return 0;
}
