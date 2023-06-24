extern int file_num;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>
#define MAX_ACCOUNTS 10
#define INPUT 10



struct users {
    char username[INPUT];
    char password[INPUT];
};

void login() {
    int flag = 0, i, count;
    char username[INPUT];
    char password[INPUT];


    struct users accounts[MAX_ACCOUNTS];

    //open txt file to put data into struct variables with while condition
    FILE* file = fopen("accountCredentials.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    count = 0;
    while (count < MAX_ACCOUNTS && fscanf(file, "%s %s", accounts[count].username, accounts[count].password) == 2) {
        count++;
    }

    fclose(file);

    while (flag == 0) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t\tEnter Username> ");
        scanf("%s", username);
        printf("\t\t\t\t\tEnter Password> ");
        scanf("%s", password);

        //match username and password to give access
        for (i = 0; i < count; i++) {
            if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
                flag = 1;

                //file_num for unique database file according to login account
                file_num = i + 1;
                break;
            }
        }

        if (flag == 1) {
            printf("\t\t\t\t\t ___________________________________\n");
            printf("\t\t\t\t\t|                                   |\n");
            printf("\t\t\t\t\t|         Login Successful!         |\n");
            printf("\t\t\t\t\t|___________________________________|\n");
        } else {
            printf("\t\t\t\t\t ___________________________________\n");
            printf("\t\t\t\t\t|                                   |\n");
            printf("\t\t\t\t\t|    Username/Password incorrect!   |\n");
            printf("\t\t\t\t\t|___________________________________|\n");
        }
            sleep(2);
            system("cls");
    }



}