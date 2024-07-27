//
// Created by User on 27/11/2022.
//
#include<stdio.h>
int main(){
    int myArray[100];
    int k=0;
    int line=0;
    FILE *file;

    file = fopen("saw.txt","w");//Adding numbers 1 to 100 in the file...
    if(file==NULL){
        printf("File cannot be opened!");
    }else{
        for(int i=1;i<=100;i++){
            fprintf(file,"%d%c",i,'\n');
        }
        fclose(file);
    }

    file = fopen("saw.txt","r");//Reading numbers and adding them to an array...
    int i=0;
    while(fscanf(file,"%d",&myArray[i])!=EOF){
        i++;
    }
    fclose(file);

    for(int j=0;j<100;j++){                 //Print numbers in the array...
        printf("%d\n",myArray[j]);
    }

    return 0;
}
