#include<stdio.h>
#include<stdbool.h>
#include "stdlib.h"
#define SIZE 1000

void printAllData();
void log_in();
int strCount(char key[50]);
void myStrCmp(char inputKey[50]);
bool checkValidEmail(char temptEmail[50]);
void passChecking(char pass[50], int userIndex);
void recordingData_toFile();
void userActionSector();
void readFile();
void menu();
void registration();

struct Worker{
    int id;
    int age;
    char name[50];
    char email[50];
    char password[50];
};

struct Worker info[SIZE];
int e_found = -1;
int p_found = -1;
int global_index = 0;

int main(){
    readFile();
    printAllData();
    menu();

    return 0;
}

void menu(){
    int key = 0;
    printf("This is menu section!\n");
    printf("Press 1 to log in!\n");
    printf("Press 2 to Register!\n");
    printf("Press 3 to Exit!\n");
    scanf(" %d", &key);

    if (key == 1){
        log_in();

    }else if(key == 2){
        registration();

    }else if(key == 3){
        exit(1);

    }else{
        printf("Invalid Option!\n");
        menu();
    }
}

void printAllData(){
    for (int i = 0; i < global_index; i++){
        printf("Id : %d - Name : %s - Age : %d - Email : %s - Password : %s\n", info[i].id, info[i].name, info[i].age, info[i].email, info[i].password);
    }
}

void log_in(){
    char lEmail[50];
    char l_password[50];
    int red = 0;
    printf("This is log in form.\n");
    printf("Press 1 to log in!\n");
    printf("Press 2 to return to Menu sector\n");
    scanf(" %d", &red);

    if (red == 1){
        printf("Enter your email :");
        scanf(" %[^\n]", &lEmail[0]);

        printf("Enter your Password :");
        scanf(" %[^\n]", &l_password[0]);


        e_found = -1;
        myStrCmp(lEmail);

        p_found = -1;
        passChecking(l_password, e_found);


        if (e_found != -1 && p_found == 1){
            printf("Log in Successful!\n");
            userActionSector();
        }else{
            printf("You cannot log in!\nTry again!\n");
            log_in();
        }

    }else if(red == 2){
        menu();
    }else{
        printf("Invalid Option!\nTry Again!\n");
        log_in();
    }


}

void myStrCmp(char inputKey[50]){
    int full = 0;

    int second = strCount(inputKey);

    for (int i =0; i < global_index; i++){
        int first = strCount(info[i].email);
        if (first == second){
            for (int j = 0; j < second; j++){
                if (info[i].email[j] == inputKey[j]){
                    full++;
                }else{
                    break;
                }
            }
        }

        if (full == second){
            e_found = i;
            break;
        }
    }
}

void passChecking(char pass[50], int userIndex){
    int is_full = 0;
    int count = strCount(pass);
    int count1 = strCount(info[userIndex].password);
    if (count == count1){
        for (int i=0; i<count; i++){
            if (pass[i] == info[userIndex].password[i]){
                is_full++;

            }else{
                break;
            }
        }
        if(is_full == count){
            p_found = 1;

        }
    }
}

int strCount(char key[50]){
    int charCount = 0;
    for (int i =0; i<50; i++){
        if (key[i] == '\0'){
            break;
        }else{
            charCount++;
        }
    }

    return charCount;
}

bool checkValidEmail(char temptEmail[50]){
    char sample[10] = "@gmail.com";
    int mark = 0;
    for (int i =0; i < 50; i++){
        if (sample[mark] == temptEmail[i]){
            mark++;
            if (mark == 10){
                return true;
            }
        }else{
            mark = 0;
        }
    }
    return false;
}

void recordingData_toFile(){
    FILE *fptr = fopen("new.txt", "w");

    if (fptr == NULL){
        printf("File cannot be opened!");

    }else{
        for (int i=0;i<global_index;i++){
            fprintf(fptr, "%d %d %s %s %s%c", info[i].id, info[i].age, info[i].name, info[i].email, info[i].password, '\n');
        }
    }
    fclose(fptr);
}

void userActionSector(){
    int userAction = 0;
    printf("Welcome Sir %s.\n", info[e_found].name);
    printf("Press 1 to go to User Acton Sector.\n");
    printf("Press 2 to return to registration sector.\n");
    printf("Press 3 to exit.\n");
    scanf(" %d", &userAction);

    if (userAction == 1){
        printf("This is user action sector.\n");
        printf("More acton will come here.\n");
    }else if(userAction == 2){
        registration();
    }else if(userAction == 3){
        exit(1);

    }else{
        printf("Invalid Option!");
        userActionSector();
    }
}

void readFile(){
    FILE *fptr = fopen("new.txt", "r");

    if (fptr == NULL){
        printf("File cannot be opened.\n");
    }else{
        for (int i=0;i<SIZE; i++){
            fscanf(fptr, "%d %d %s %s %s", &info[i].id, &info[i].age, &info[i].name[0], &info[i].email[0], &info[i].password[0]);

            if (info[i].name[0] == '\0'){
                break;
            }else{
                global_index++;
            }

        }

    }
    fclose(fptr);
}

void registration(){
    printf("This is registration section.\n");
    printf("Enter your email to register :");
    scanf(" %s", &info[global_index].email[0]);

    if(checkValidEmail(&info[global_index].email[0])){
        myStrCmp(info[global_index].email);
        if (e_found == -1){
            printf("Enter your password :");
            scanf(" %s", &info[global_index].password[0]);

            printf("Enter your age :");
            scanf(" %d", &info[global_index].age);

            printf("Enter Username :");
            scanf(" %[^\n]", &info[global_index].name[0]);

            info[global_index].id = global_index + 1;

            global_index++;
            printf("Registration Successful\n");
            recordingData_toFile();
            menu();



        }else{
            printf("This email already exits.\nTry another email\n");
            e_found = -1;
            registration();
        }
    }else{
        printf("Invalid email format!\nTry again!");
        registration();
    }

}