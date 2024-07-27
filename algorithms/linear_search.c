//
// Created by User on 12/30/2022.
//
#include "stdio.h"
#include "string.h"

#define string_array_length 5
#define each_string_length 15

int linear_search_num(int arr[], int toFind, int length);
int linear_search_string(char *arr[], char toFind[], int length);

int main(){
    int num_array[] = {2, 3, 5, 6, 7, 8, 25, 36, 41, 50, 60, 60, 60};
    char *string_array[string_array_length][each_string_length] = {"battleship", "boot", "cannon", "iron", "top hat"};



//    int len = sizeof(num_array) / sizeof(num_array[0]); // for num_array
    int len = sizeof(string_array) / sizeof(string_array[0]);  // for string_array

//    printf("Enter the number to search:");
//    int key;
//    scanf(" %d", &key);

    printf("Enter the word to search:");
    char key[each_string_length];
    scanf("%[^\n]", &key);

//    int index = linear_search_num(num_array, key, len);
    int index = linear_search_string(*string_array, key, len); // this * is important

    if (index >= 0){
        printf("We found %s at index %d.", key, index); // %s for string and %d for int
    }else{
        printf("%s is not found.", key);
    }

    return 0;
}

int linear_search_num(int arr[], int toFind, int length){

    for(int i=0 ; i<length; i++){

        if(arr[i] == toFind){
            return i;  // returning the index the number was found

        }
    }
    return -1;
}

int linear_search_string(char *arr[], char toFind[], int length)
{
    int count = 0;

    for(int i = 0; i < length; i++)
    {
        if (strcmp(arr[i], toFind) == 0)
        {
            count++;
            return i;
        }
    }

    return -1;

}