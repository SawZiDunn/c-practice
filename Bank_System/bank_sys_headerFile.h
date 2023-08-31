//
// Created by User on 5/1/2023.
//

#ifndef PROGRAMMING_CODES_BANK_SYS_HEADERFILE_H
#define PROGRAMMING_CODES_BANK_SYS_HEADERFILE_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define SIZE 1000  //symbolic constant

struct transition_record{
    char note[200];
};

struct data{
    unsigned int id;
    char name[30];
    char password[50];
    char nrc[50];
    char email[50];
    char pOrb[10]; //personal or business
    unsigned long long int ph_number;
    unsigned current_amount;
    char address[100];
    char loan_status[1];  //t or f
    float loan_rate;
    unsigned int monthly_income;
    unsigned loan_amount;
    char account_status[10];
    int account_level;
    unsigned int trans_amountPerDay;
    struct transition_record transitionRecord[100];

};

struct my_time{
    char current_time[25];
};

struct my_time currentTime[1];

struct data db[SIZE];
int users = 0;
int current_user = 0;  //for log_in process & to know current user
int other_user = 0;

int space_array[SIZE];
char int_to_char_array[10];
unsigned int character_array_to_unsignedInt_data = 0;

unsigned int current_day_toTransfer = 0;
unsigned int current_amount_to_Transfer = 0;



void welcome();
void loading_all_data_from_file();
void printing_all_data();
void saving_all_data_to_file();

void space_counter();
void log_in();
void registration();
void user_action();
int chars_count(char key[50]);
bool checkValidEmail(char temptEmail[50]);
bool email_exist_checking(char to_check[50]);
int asking_nrc();
bool nrc_validation(char nrc_toCheck[50]);
bool comparing_two_charArray(char first[50], char second[50]);
void characterArray_Copy(char acceptor[50], char transmitter[50]);
int asking_password();
bool isStrongPassword(char inputPassword[50]);
int asking_ph_number();
bool ph_num_exits(unsigned long long int toCheck_phNum);
void transfer_money();
void transaction_record(int transfer_person, int receive_person, unsigned int amount, char action);
void integer_to_character(unsigned int integer);
unsigned int charArray_to_unsignedInt(char charArray[]);
void get_time();
unsigned int get_limit_amount();
void current_data_toTransfer(unsigned int current_amount_toTransfer);
unsigned int deciding_current_transfer_amount();
void withdraw_money();


void welcome(){
    int option = 0;
    printf("Welcome to International Bank!\n");
    printf("Press 1 to log in.\nPress 2 to register.\nPress 3 to exit.\n");
    scanf("%d", &option);

    if (option == 1){
        log_in();
    }else if (option == 2){
        registration();
    }else if (option == 3){
        saving_all_data_to_file();
        exit(1);

    }else{
        printf("Invalid option!\nPlease try again.\n");
        welcome();
    }
}

void loading_all_data_from_file(){
    FILE *fptr = fopen("ncc_db1.txt", "r");

    if (fptr == NULL){
        printf("Error at loading data from the file!!!\n");
    }else {
        for (int ncc = 0; ncc<SIZE ; ncc++){
            fscanf(fptr ,"%u %s %s %s %s %s %s %u %u %f %s %d %llu %u %s %u", &db[ncc].id, &db[ncc].name[0], &db[ncc].nrc[0],&db[ncc].email[0],&db[ncc].password[0],&db[ncc].pOrb[0],&db[ncc].loan_status[0], &db[ncc].monthly_income, &db[ncc].loan_amount ,&db[ncc].loan_rate , &db[ncc].account_status[0] ,&db[ncc].account_level,&db[ncc].ph_number, &db[ncc].current_amount, &db[ncc].address[0] , &db[ncc].trans_amountPerDay);

            for (int i =0 ; i < space_array[ncc] - 15; i++){
                fscanf(fptr, "%s", &db[ncc].transitionRecord[i].note[0]);
            }

            if (db[ncc].email[0] == '\0'){
                break;
            }

            users++;
        }

    }
    fclose(fptr);
}

void printing_all_data(){
    for (int ncc = 0; ncc<users; ncc++){
        printf("%u-%s-%s-%s-%s-%s-%s-%u-%u-%f-%s-%d-%llu-%u-%s-%u", db[ncc].id,db[ncc].name,db[ncc].nrc,db[ncc].email,db[ncc].password,db[ncc].pOrb,db[ncc].loan_status, db[ncc].monthly_income, db[ncc].loan_amount ,db[ncc].loan_rate , db[ncc].account_status , db[ncc].account_level, db[ncc].ph_number, db[ncc].current_amount, db[ncc].address , db[ncc].trans_amountPerDay );

        for (int i =0 ; i < space_array[ncc] - 15; i++){
            printf("-%s", &db[ncc].transitionRecord[i].note[0]);
        }

        printf("\n");

    }

}

void saving_all_data_to_file(){
    FILE *fptr = fopen("ncc_db1.txt", "w");

    if (fptr == NULL){
        printf("Error at opening file in saving_all_data_to_file function");
    }else {
        for (int ncc = 0; ncc < users ; ncc++){
            fprintf(fptr, "%u%c%s%c%s%c%s%c%s%c%s%c%s%c%u%c%u%c%f%c%s%c%d%c%llu%c%u%c%s%c%u",db[ncc].id, ' ', db[ncc].name, ' ',db[ncc].nrc, ' ',db[ncc].email, ' ',db[ncc].password, ' ',db[ncc].pOrb, ' ',db[ncc].loan_status, ' ', db[ncc].monthly_income, ' ',db[ncc].loan_amount , ' ',db[ncc].loan_rate , ' ',db[ncc].account_status , ' ', db[ncc].account_level, ' ', db[ncc].ph_number, ' ', db[ncc].current_amount, ' ',db[ncc].address , ' ',db[ncc].trans_amountPerDay );

            for (int i =0 ; i < space_array[ncc] - 15; i++){
                fprintf(fptr, "%c%s", ' ', &db[ncc].transitionRecord[i].note[0]);
            }

            fprintf(fptr, "%c", '\n');
        }

        }

    fclose(fptr);
    }

void log_in(){
    char log_inEmail[50];
    char log_inPassword[50];

    printf("This is log-in section.\n");
    printf("Enter your email :");
    scanf(" %[^\n]", &log_inEmail[0]);

    printf("Enter your password :");
    scanf(" %[^\n]", &log_inPassword[0]);

    if (!email_exist_checking(log_inEmail)){
        if (comparing_two_charArray(db[current_user].password, log_inPassword)){
            printf("Log-in Successful!\n");
            user_action();

        }
    }

    printf("Incorrect Password!\nPlease try again.\n");
    log_in();

}

void user_action(){
    int option = 0;
    printf("Welcome Mr.%s\n", db[current_user].name);
    printf("Press 1 to check balance.\nPress 2 to transfer money.\nPress 3 to withdraw money.\nPress 4 to cash in.\nPress 5 to change account password.\nPress 6 to exit.");
    scanf(" %d", &option);

    if (option == 1){
        printf("Your current Balance is %u Baht.\n", db[current_user].current_amount);

    } else if (option == 2){
        transfer_money();

    }else if(option == 3){
        withdraw_money();

    }else if(option == 4){
        printf("Cash In");

    } else if (option == 5){
        printf("Change Account Password");

    }else if (option == 6){
        welcome();
    }else {
        printf("Invalid Option!\n");
        user_action();
    }


}

void registration(){
    char register_email[50];


    printf("Welcome to Registration Section...\n");
    printf("Enter your email :");
    scanf(" %[^\n]", &register_email[0]);

    if (checkValidEmail(register_email) && email_exist_checking(register_email)){

        characterArray_Copy(db[users].email, register_email);

    }else{
        printf("Invalid gmail format or your gmail already exists.\nPlease try again.\n");
        registration();
    }

    printf("Enter your name :");
    scanf(" %[^\n]", &db[users].name[0]);

    asking_nrc();
    asking_password();
    asking_ph_number();

    printf("Enter your current amount :");
    scanf(" %u", &db[users].current_amount);

    printf("Enter your address :");
    scanf(" %[^\n]", &db[users].address[0]);

    characterArray_Copy(db[users].pOrb, db[1].pOrb);
    characterArray_Copy(db[users].loan_status, db[1].loan_status);
    characterArray_Copy(db[users].account_status, db[1].account_status);

    db[users].monthly_income = db[1].monthly_income;
    db[users].loan_amount = db[1].loan_amount;
    db[users].loan_rate = db[1].loan_rate;
    db[users].account_level = db[1].account_level;
    db[users].trans_amountPerDay = db[1].trans_amountPerDay;

    db[users].id = users + 1;
    users++;

    printing_all_data();
    printf("Registration Complete!");
    welcome();

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

bool email_exist_checking(char to_check[50]){
    int localCount = 0;
    int toCheckCount = chars_count(to_check);

    for (int i = 0; i<users; i++){
        int existCount = chars_count(db[i].email);

        if (toCheckCount == existCount){

            for ( int j = 0; j < toCheckCount; j++){
                if (to_check[j] != db[i].email[j]){
                    break;
                }else {
                    localCount++;
                }
            }

            if ( localCount == toCheckCount){
                current_user = i;
                return false;

            }
        }
    }

    return true;

}

int asking_password(){
    char register_password[50];

    printf("Enter your password :");
    scanf(" %[^\n]", &register_password[0]);

    if (isStrongPassword(register_password)){
        printf("Your password is strong.\n");
        characterArray_Copy(db[users].password, register_password);
        return 1;

    }else {
        printf("Weak Password!!\n");
        asking_password();
    }

}


bool isStrongPassword(char inputPassword[50]) {
    int i = 0;
    int n = chars_count(inputPassword);
    int special = 0;
    int numChar = 0;
    int capChar = 0;
    int smallChar = 0;

    while (i < n) {
        if (inputPassword[i] >= 33 && inputPassword[i] <= 42) {
            special++;

        } else if (inputPassword[i] >= 48 && inputPassword[i] <= 57) {
            numChar++;

        } else if (inputPassword[i] >= 65 && inputPassword[i] <= 90) {
            capChar++;

        } else if (inputPassword[i] >= 97 && inputPassword[i] <= 122) {
            smallChar++;

        }
        i++;

        if (special > 0 && numChar > 0 && capChar > 0 && smallChar > 0) {
            return true;
        }
    }
    return false;

}

bool comparing_two_charArray(char first[50], char second[50]){
    int firstCount = chars_count(first);
    int secondCount = chars_count(second);
    int local_count = 0;

    if (firstCount == secondCount){
        for (register int i = 0; i<firstCount ; i++){   //'register' is used in order to keep variables in the CPU,
                                                          //not in the RAM, just to get faster
            if (first[i] != second[i]){
                break;
            }else {
                local_count++;
            }
        }

        if (local_count == firstCount){
            return true;
        }
    }
    return false;
}

void characterArray_Copy(char acceptor[50], char transmitter[50]){
    int loop_count = chars_count(transmitter);

    for (int i =0; i<loop_count ; i++){
        acceptor[i] = transmitter[i];
    }
}

int asking_nrc(){
    char register_nrc[50];

    printf("Enter your nrc :");
    scanf(" %[^\n]", &register_nrc[0]);

    if (nrc_validation(register_nrc)){
        printf("Valid NRC...\n");
        characterArray_Copy(db[users].nrc, register_nrc);
        return 1;

    }else {
        printf("Invalid NRC...\n");
        asking_nrc();
    }
}

bool nrc_validation(char nrc_toCheck[50]){  //wrong, need to be modified later
    int nrc_count = chars_count(nrc_toCheck);
    int nrc_char = 0;

    for (register int i = 0; i < nrc_count ; i++){
        if (nrc_toCheck[i] == ')'){
            break;
        }else {
            nrc_char++;
        }
    }

    for (int i = 0; i<users; i++){
        if(comparing_two_charArray(nrc_toCheck, db[i].nrc)){
            return true;
        }
    }
    return false;

}


int asking_ph_number(){
    unsigned long long int register_phNum;
    printf("Enter your phone number :");
    scanf(" %llu", &register_phNum);

    if (!ph_num_exits(register_phNum)){
        printf("Your phone number already exits.\nPlease try again.\n");
        asking_ph_number();

    }else {
        printf("Valid Phone Number!\n");
        db[users].ph_number = register_phNum;
        return 1;
    }

}

bool ph_num_exits(unsigned long long int toCheck_phNum){
    for (int i =0; i<users; i++){
        if (toCheck_phNum == db[i].ph_number){
            other_user = i;
            return false;
        }
    }
    return true;

}

void transfer_money(){
    unsigned long long int receive_ph_num;
    unsigned int transfer_money = 0;

    printf("Enter resipent phone number :");
    scanf(" %llu", &receive_ph_num);

    if (!ph_num_exits(receive_ph_num)){
        printf("Enter the amount to transfer to %s %s :", db[other_user].name, db[other_user].email);
        scanf("%u", &transfer_money);

        current_data_toTransfer(transfer_money);

        unsigned int total_amount = deciding_current_transfer_amount();
        unsigned int trans_amount_limit = get_limit_amount();

        total_amount += transfer_money;

        if (total_amount  > trans_amount_limit){
            printf("Exceeded Limit Amount\n");
            printf("You can only transfer only %u for today!\n", trans_amount_limit - (total_amount - transfer_money));
            user_action();
        }

        if (transfer_money > db[current_user].current_amount){
            printf("Insufficient Amount!'\n");

        }else {
            db[current_user].current_amount -= transfer_money;
            db[other_user].current_amount += transfer_money;

            transaction_record(current_user, other_user, transfer_money, 't');
            transaction_record(current_user, other_user, transfer_money, 'r');

            printf("%u has been successfully transferred to %s\nThank You!\n", transfer_money, db[other_user].name);
            printing_all_data();

        }

    }else {
        printf("No account is registered with this phone number!\n");
        user_action();
    }

    user_action();

}

void transaction_record(int transfer_person, int receive_person, unsigned int amount, char action){   //action means whether it is for transfer_person or receive_person


    
    int transfer_person_name_count = chars_count(db[current_user].name);
    int receive_person_name_count = chars_count(db[other_user].name);

    integer_to_character(amount);
    int money_amount_char_count = chars_count(int_to_char_array);



    char from[5] = {'F', 'r', 'o', 'm', '_'};
    char to[4] = {'_','T', 'o', '_'};

    int index = 0;

    if (action == 't'){
        for (int i =0 ; i<5; i++){
            index++;
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[i] = from[i];
        }

        for (int i = 0 ; i<transfer_person_name_count ; i++){
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = db[transfer_person].name[i];
            index++;
        }

        for (int i = 0 ; i< 4 ; i++){
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = to[i];

            index++;
        }

        for (int i = 0; i< receive_person_name_count ; i++){
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = db[receive_person].name[i];

            index++;
        }

        db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = '_';
        index++;

        db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = '$';
        index++;

        for (int i = 0; i < money_amount_char_count; i++){
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = int_to_char_array[i];
            index++;
        }

        get_time();

        for (int i = 0; i<25; i++){
            db[transfer_person].transitionRecord[space_array[transfer_person] - 15].note[index] = currentTime[0].current_time[i];
            index++;
        }

        space_array[transfer_person]++;


    }else if (action == 'r'){

        for (int i =0 ; i<5; i++){
            index++;
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[i] = from[i];
        }

        for (int i = 0 ; i<transfer_person_name_count ; i++){
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = db[transfer_person].name[i];
            index++;
        }


        for (int i = 0 ; i< 4 ; i++){
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = to[i];

            index++;
        }

        for (int i = 0; i< receive_person_name_count ; i++){
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = db[receive_person].name[i];

            index++;
        }

        db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = '_';
        index++;

        db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = '$';
        index++;

        for (int i = 0; i < money_amount_char_count; i++){
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = int_to_char_array[i];
            index++;
        }

        get_time();

        for (int i = 0; i<25; i++){
            db[receive_person].transitionRecord[space_array[receive_person] - 15].note[index] = currentTime[0].current_time[i];
            index++;
        }

        space_array[receive_person]++;

    }else {
        printf("Error at transaction record.");
    }
}

void space_counter(){
    FILE *fptr = fopen("ncc_db1.txt", "r");

    if (fptr == NULL){
        printf("File cannot be opened at space_counter function.");
    }else {
        char c = fgetc(fptr);
        int index = 0;
        while(!feof(fptr)){
            if (c != '\n'){
                if (c == ' '){
                    space_array[index] += 1;

                }
                c = fgetc(fptr);

            }else {
                index++;
                c = fgetc(fptr);
            }

        }
    }
    fclose(fptr);
}

void integer_to_character(unsigned int integer){
    FILE *fptr = fopen("tempt.txt", "w");

    if (fptr == NULL){
        printf("Error at opening file in integer_to_character function!\n");
    }else {
        fprintf(fptr, "%u", integer);

    }
    fclose(fptr);

    FILE *fptr2 = fopen("tempt.txt", "r");

    fscanf(fptr2, "%s", &int_to_char_array[0]);
    fclose(fptr2);
}

unsigned int charArray_to_unsignedInt(char charArray[]){

    unsigned int data;
    FILE *fptr = fopen("tempt.txt", "w");

    if (fptr == NULL){
        printf("Error at opening file in integer_to_character function!\n");
    }else {
        fprintf(fptr, "%s", charArray);

    }
    fclose(fptr);

    FILE *fptr2 = fopen("tempt.txt", "r");

    fscanf(fptr2, "%u", &data);
    fclose(fptr2);

    return data;

}

void get_time(){
    time_t tm;
    time(&tm);
//    printf("Current Time : %s", ctime(&tm));   //getting current time

    FILE *fptr = fopen("time.txt", "w");

    if (fptr == NULL){
        printf("Error at opening file in get_time function.");
    }else {
        fprintf(fptr, "%s", ctime(&tm));

    }

    fclose(fptr);

    int index = 0;
    currentTime[0].current_time[index] = '_';
    index++;

    int time_space_counter = 0;

    FILE *fptr2 = fopen("time.txt", "r");

    char c = fgetc(fptr2);

    while(!feof(fptr2)){

        if (c == ' '){
            time_space_counter++;

            if (time_space_counter == 1){
                currentTime[0].current_time[index] = '!';
                c = fgetc(fptr2);
                index++;

            }else if (time_space_counter == 4){
                currentTime[0].current_time[index] = '@';
                c = fgetc(fptr2);
                index++;
            }else {
                currentTime[0].current_time[index] = '_';
                c = fgetc(fptr2);
                index++;

            }

        }else {
            currentTime[0].current_time[index] = c;
            c = fgetc(fptr2);
            index++;
        }

    }
    fclose(fptr2);

}

unsigned int get_limit_amount(){
    int account_level = db[current_user].account_level;
    char pOrb = db[current_user].pOrb[0];
    int p_or_b = 0;

    unsigned int trans_amount_PerDay = 0;

    if (pOrb == 'p'){
        p_or_b = 1;
    }else if (pOrb == 'b'){
        p_or_b = 2;
    }

    switch (account_level) {
        case 1:
            if (p_or_b == 1){
                trans_amount_PerDay = 100000;

            }else {
                trans_amount_PerDay = 1000000;
            }
            break;

        case 2:
            if (p_or_b == 1){
                trans_amount_PerDay = 50000;
            }else {
                trans_amount_PerDay = 500000;
            }
            break;

        case 3:
            if (p_or_b == 1){
                trans_amount_PerDay = 10000;
            }else {
                trans_amount_PerDay = 100000;
            }

        default:
            break;

    }

    return trans_amount_PerDay;

}

void current_data_toTransfer(unsigned int current_amount_toTransfer){

    char get_current_day[2];
    get_time();

    get_current_day[0] = currentTime[0].current_time[9];
    get_current_day[1] = currentTime[0].current_time[10];

    current_amount_to_Transfer = current_amount_toTransfer;
    current_day_toTransfer = charArray_to_unsignedInt(get_current_day);

}

unsigned int deciding_current_transfer_amount(){  //calculating total transfer amount of same days

    current_user = 1;

    unsigned int total_amount_for_same_day = 0;

    int record_counter = space_array[current_user]-15;
    int index_counter = 0;

    char amount_char_array[10];
    char day_char_array[3];


    for (int a = record_counter-1; a>0; a--){

        int current_record_counter = chars_count(db[current_user].transitionRecord[a].note);

        //to reach '$'
        for (int aa = 0; aa <current_record_counter - 1; aa++){   //subtracting 1 from current_record_counter is not really necessary, just to be precise
            if (db[current_user].transitionRecord[a].note[aa] == '$'){
                index_counter++;
                break;
            }

            index_counter++;

        }

        int quantity_of_amount = 0;
        for (int aaa = index_counter; aaa < current_record_counter - 1 ; aaa++){  //same with the above note

            if (db[current_user].transitionRecord[a].note[aaa] == '_'){
                break;
            }

            quantity_of_amount++;
        }

        for (int x = 0; x < quantity_of_amount ; x++){
            amount_char_array[x] = db[current_user].transitionRecord[a].note[index_counter];
            index_counter++;

        }

        unsigned int current_record_amount = charArray_to_unsignedInt(amount_char_array);

        for (int i = 0; i<10;i++){  //to make sure there's no data left in the array after one loop
            amount_char_array[i] = '\0';
        }

        printf("Current Record Amount = %u\n", current_record_amount);


        //to get day of current record

        for (int xx = index_counter ; xx < current_record_counter ; xx++){
            if (db[current_user].transitionRecord[a].note[xx] == '!'){
                break;
            }

            index_counter++;
        }

        day_char_array[0] = db[current_user].transitionRecord[a].note[index_counter+5];
        day_char_array[1] = db[current_user].transitionRecord[a].note[index_counter+6];

        unsigned int current_record_day = charArray_to_unsignedInt(day_char_array);
//        printf("current record day = %u\n", current_record_day);

        total_amount_for_same_day += current_record_amount;

        if (current_record_day != current_day_toTransfer){
            break;
        }

        index_counter = 0;

    }

    printf("Total amount for same day : %u\n", total_amount_for_same_day);
    return total_amount_for_same_day;

}

void withdraw_money(){
    unsigned int withdraw_amount = 0;

    printf("Welcome Mr.%s\n", db[current_user].name);
    printf("Your current amount is %u.", db[current_user].current_amount);

    printf("Enter your amount to withdraw :");
    scanf("%u", &withdraw_amount);

    if (withdraw_amount >= db[current_user].current_amount - 1000){
        printf("Insufficient Amount!%u\n", withdraw_amount - (db[current_user].current_amount - 1000));
        withdraw_money();
    }else {
        db[current_user].current_amount -= withdraw_amount;
        printf("Successful Withdrawal of %u.\n", withdraw_amount);
        printf("Your updated balance is %u.\n", db[current_user].current_amount);
        user_action();
    }
    

}


#endif //PROGRAMMING_CODES_BANK_SYS_HEADERFILE_H
