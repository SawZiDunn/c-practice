//
// Created by User on 12/8/2022.
//
#include<stdio.h>
#include<string.h>

//structure in C can be written in two ways

struct movie{
    int released_year;
    char name[10];

};

typedef struct
{
    char name[10];
    int age;

} person;

int main(){
    
    struct movie movie1;
    struct movie movie2;

    movie1.released_year = 1997;
    strcpy(movie1.name,"The Hound");

    movie2.released_year = 2011;
    strcpy(movie2.name,"The Pink");

    printf("============");

    person people[2];
    strcpy(people[0].name, "Jim");
    people[0].age = 21;

    strcpy(people[1].name, "Jack");
    people[1].age = 25;

    return 0;
}