//
// Created by User on 12/9/2022.
//
#include<stdio.h>
#include<stdlib.h>

void writeNumsTofile();
void readfile();
int arr[100];
void printArray();

int main(void){
    writeNumsTofile();
    readfile();
    printArray();

    return 0;
}

void writeNumsTofile(){
    FILE *fptr;
    fptr=fopen("hi.txt","w");
    if(fptr==NULL){
        printf("File cannot be opened.");
        exit(1);
    }else{
        for(int i = 1; i <= 100; i++){
            fprintf(fptr,"%d%c",i,'\n');
        }
    }
    fclose(fptr);
}

void readfile(){
    int index=0;
    int data=0;
    FILE *fptr;
    fptr= fopen("hi.txt","r");
    if(fptr==NULL){
        printf("File cannot be opened.");
        exit(1);
    }else{
        while(fscanf(fptr,"%d",&data)==1){
            arr[index]=data;
            index++;
        }
    }
    fclose(fptr);
}

void printArray(){
    for(int i=0;i<100;i++){
        printf("ArrayData: %d\n",arr[i]);
    }
}