//
// Created by User on 12/8/2022.
//
#include<stdio.h>
#include<string.h>

struct labour{
    int a;
    char myarr[10];

};

int main(){
    
    struct labour l1;
    struct labour l2;
    l1.a=25;
    strcpy(l1.myarr,"Howareyou?");

    l2.a=52;
    strcpy(l2.myarr,"SawZiDunn");


    printf("a is %d\nmyarr is %s\n",l1.a,l1.myarr);
    printf("a is %d\nmyarr is %s",l2.a,l2.myarr);




    return 0;
}