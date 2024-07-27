#include<stdio.h>
#include<stdbool.h>
#include "stdlib.h"
#define SIZE 1000

void printAllData();
void log_in();
int chars_count(char key[50]);
void myStrCmp(char inputKey[50]);
bool checkValidEmail(char temptEmail[50]);
void passChecking(char pass[50], int userIndex);
void recordingData_toFile();
void userActionSector();
void readFile();
void menu();
void registration();
void isStrongPassword(char inputPassword[50]);

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
int strong_pass = -1;
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
            red = 0;
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

void myStrCmp(char inputKey[50]){  //checking whether the email already exits or not
    int full = 0;

    int second = chars_count(inputKey);

    for (int i =0; i < global_index; i++){
        int first = chars_count(info[i].email);
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
    int count = chars_count(pass);
    int count1 = chars_count(info[userIndex].password);
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

int chars_count(char key[50]){
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

        if (temptEmail[i] == ' ' ){
            break;

        }

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
    printf("Press 2 to return to menu.\n");
    printf("Press 3 to exit.\n");
    scanf(" %d", &userAction);

    if (userAction == 1){
        printf("This is user action sector.\n");
        printf("More acton will come here.\n");
    }else if(userAction == 2){
        menu();
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

    scanf(" %[^\n]", &info[global_index].email[0]);


    if(checkValidEmail(info[global_index].email)){
        myStrCmp(info[global_index].email);
        if (e_found == -1){

            while(strong_pass == -1){
                printf("Enter your password :");
                scanf(" %s", &info[global_index].password[0]);

                isStrongPassword(info[global_index].password);
                if (strong_pass == -1){
                    printf("Your password is weak!\nTry a new one.\n");
                    strong_pass = -1;
                }
            }

            printf("Enter your age :");
            scanf(" %d", &info[global_index].age);

            printf("Enter Username :");
            scanf(" %[^\n]", &info[global_index].name[0]);

            info[global_index].id = global_index + 1;

            global_index++;
            printf("Registration Successful\n");
            strong_pass = -1;
            recordingData_toFile();
            printAllData();
            menu();

        }else{
            printf("This email already exits.\nTry another email\n");
            e_found = -1;
            registration();
        }
    }else{
        printf("Invalid email format!\nTry again!\n");
        e_found = -1;
        registration();
    }

}

void isStrongPassword(char inputPassword[50]){
    int i = 0;
    int n = chars_count(inputPassword);
    int special = 0;
    int numChar = 0;
    int capChar = 0;
    int smallChar = 0;

    while (i < n){
        if (inputPassword[i] >=33 && inputPassword[i] <= 42){
            special++;

        }else if (inputPassword[i] >=48 && inputPassword[i] <= 57) {
            numChar++;

        }else if (inputPassword[i] >=65 && inputPassword[i] <= 90){
            capChar++;

        }else if(inputPassword[i] >=97 && inputPassword[i] <= 122){
            smallChar++;

        }
        i++;

        if (special > 0 && numChar > 0 && capChar > 0 && smallChar > 0){
            strong_pass = 1;
            break;
        }
    }


}