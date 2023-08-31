//
// Created by User on 12/5/2022.
//
#include<stdio.h>
#include<stdlib.h>

int db[100];
int main() {
    int key = 10;
    int age = 0;
    int option = 0;
    int dbIndex =0;
    int userId = 0;
    int userId1 =0;
    int flag = 0;
    int global_flag=0;
    int red_flag=0;

    while (key <= 10) {
        printf("Welcome to our game!!!\n");
        printf("Enter your age : ");

        scanf("%d", &age);
        if (age >= 17) {
            printf("You can start playing the game!\n");

            while (true) {
                global_flag = 0;

                printf("Press 1 to Log In!\nPress 2 to Register!\nPress 3 to go back\nPress 4 to Exit\n");
                scanf("%d", &option);
                while (true) {
                    if (option == 1) {
                        printf("You can Log In.\n");
                        printf("Enter your Id :");
                        scanf("%d", &userId);

                        for (int i = 0; i < 100; i++) {
                            if (userId == db[i]) {
                                flag = 1;
                            }
                        }
                        if (flag == 1) {
                            printf("Play the game now!\n");
                            flag =0;
                        } else {
                            printf("Your Id is invalid!\n");
                            break;
                        }

                    } else if (option == 2) {
                        if(global_flag==1){
                            break;
                        }
                        printf("You can Register.\n");
                        printf("Enter your Id :");
                        scanf("%d", &userId);
                        for(int i=0;i<100;i++){
                            if(db[i]==userId){
                                flag=1;
                            }
                        }
                        while(true){
                            if(flag==1){
                                printf("Use Id is already taken!'\n");
                                flag = 0;
                                break;
                            }else{
                                printf("Confirm your Id :");
                                scanf("%d", &userId1);
                                if(userId==userId1){
                                    db[dbIndex]=userId;
                                    dbIndex++;
                                    printf("Registration Success!\n");
                                    global_flag=1;
                                    break;
                                }else{
                                    printf("Recheck your Id!\n");
                                    break;
                                }
                            }
                        }


                    } else if (option == 3) {
                        break;

                    } else if (option == 4) {
                        exit(1);
                    } else {
                        printf("Invalid Option!\n");
                    }
                }
            }

        }else{
        printf("You cannot play the game!\nPlease try again!\n");
    }

    }

    return 0;
}