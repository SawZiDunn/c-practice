//
// Created by User on 12/9/2022.
//
#include<stdio.h>
int main(){
    int num;
    FILE *fptr;

    fptr = fopen("zidunn.txt","a");
    if(fptr==NULL){
        printf("File cannot be opened!");
    }else{
        printf("Enter a number to store :");
        scanf("%d",&num);
        fprintf(fptr,"%d%c",num,'\n');
        fclose(fptr);
    }

    return 0;
}
