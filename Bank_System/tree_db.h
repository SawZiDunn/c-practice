//
// Created by User on 6/19/2023.
//

#ifndef PROGRAMMING_CODES_TREE_DB_H
#define PROGRAMMING_CODES_TREE_DB_H


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

struct Node{

    struct Node* left;
    struct Node* right;
    struct data db;
};

#endif //PROGRAMMING_CODES_TREE_DB_H
