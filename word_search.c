//
// Created by User on 12/12/2022.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void wordSearch(char toFind[]);

int main(){
    char toSearch[20];
    printf("Enter what you want to search : ");
    scanf("%s",&toSearch);
    wordSearch(toSearch);

    return 0;
}

void wordSearch(char toFind[]){

    FILE *file;
    int count=0;
    int count2=0;
    char c=0;
    int i=0;
    file= fopen("words.txt","r");
    if(file==NULL){
        printf("File cannot be opened.");

    }else{
        c= fgetc(file);
        while(!feof(file)){

            while(!feof(file)){

                if(toFind[i]==c){
                    i++;
                    c= fgetc(file);
                    count++;
                    if(count== strlen(toFind)){
                        count2++;
                        i=0;
                        break;
                    }
                }else{
                    count=0;
                    c= fgetc(file);
                    i=0;
                    break;
                }
            }
        }
        printf("We found %s %d times.",toFind,count2);
    }
    fclose(file);
}

