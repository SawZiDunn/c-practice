//
// Created by User on 12/9/2022.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void alphabetGenerator();
void countAlpha();
int arr[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
void dataPrint();
int biggestNum();
void printASCII();
void writingToaFile();

int main(){
    alphabetGenerator();
    countAlpha();
    dataPrint();
    printASCII();
    writingToaFile();
    return 0;
}

void alphabetGenerator(){
    FILE *fptr;
    fptr=fopen("alpha.txt","w");

    srand(time(NULL));
    for(int i=0;i<1000;i++){
        int ranData=rand()%123;
        if(ranData>=97){
            fprintf(fptr,"%c",ranData);
        }else{
            i--;
        }
    }
    fclose(fptr);
}

void countAlpha(){
    FILE *fptr;
    fptr= fopen("alpha.txt","r");
    int c= fgetc(fptr);
    while(!feof(fptr)){
        int index=c-97;  //We get index here...
        arr[index]++;

        c= fgetc(fptr);
    }
    fclose(fptr);

}
void dataPrint(){
    int alpha=97;
    for(int i=0;i<26;i++){
//        printf("Counting of %c :%d\n",alpha,arr[i]);
        alpha++;
    }
}

int biggestNum(){
    int biggestEle=0;
    for(int i=0;i<26;i++){
        if (arr[i]>biggestEle){
            biggestEle=arr[i];
        }
    }
    return biggestEle;
}

void printASCII(){
    int biggestEle = biggestNum();
    for(int k=0;k<biggestEle;k++){
        for(int j=0;j<26;j++){
            if(arr[j]!=0){
                printf("%c  ",j+97);
                arr[j]--;
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

void writingToaFile(){
    FILE *fptr;
    fptr= fopen("data.txt","w");
    fclose(fptr);

    FILE *fptr2;
    fptr2= fopen("data.txt","a");

    if(fptr2==NULL){
        printf("File cannot be opened");
    }else{
        int biggestEle = biggestNum();
        for(int k=0;k<biggestEle;k++){
            for(int j=0;j<26;j++){
                if(arr[j]!=0){
                    fprintf(fptr2,"%c  ",j+97);
                    arr[j]--;
                }else{
                    fprintf(fptr2,"%c  ",' ');
                }
            }
            fprintf(fptr2,"%c",'\n');
        }


    }
    fclose(fptr2);
}