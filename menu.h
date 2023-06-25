extern int file_num;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dos.h>

#define MAX_CHARACTERS 5



typedef struct {
    char name[20];
    int level;
} Character;


void AddCharacter();
void UpdateLevel();
void CalculateExperience();
void ListCharacters();
int calculation(int level);



void main_menu() {
    int input;

    do {


        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t\t _______________________________\n");
        printf("\t\t\t\t\t|                               |\n");
        printf("\t\t\t\t\t| 1) Add Character              |\n");
        printf("\t\t\t\t\t| 2) Update Level               |\n");
        printf("\t\t\t\t\t| 3) Experience Calculator      |\n");
        printf("\t\t\t\t\t| 4) Check current characters   |\n");
        printf("\t\t\t\t\t| 5) Check Server maintainance  |\n");
        printf("\t\t\t\t\t| 6) Exit                       |\n");
        printf("\t\t\t\t\t|_______________________________|\n\n");


        printf("\t\t\t\t\t   Enter your choice (1-5): ");
        scanf("%d", &input);

        switch (input) {
            case 1:
                system("cls");
                AddCharacter();
                break;
            case 2:
                system("cls");
                UpdateLevel();
                break;
            case 3:
                system("cls");
                CalculateExperience();
                break;
            case 4:
                system("cls");
                ListCharacters();
                break;
            case 5:
                system("cls");
                ShellExecute(NULL, "open", "a.jpg", NULL, NULL, SW_SHOWNORMAL);
            case 6:
                printf("\t\t\t\t\t _______________________________\n");
                printf("\t\t\t\t\t|                               |\n");
                printf("\t\t\t\t\t| Exiting...                    |\n");
                printf("\t\t\t\t\t|_______________________________|\n\n");
                return 0;
            default:
                printf("\t\t\t\t      _____________________________________\n");
                printf("\t\t\t\t     |                                     |\n");
                printf("\t\t\t\t     | Invalid choice! Please try again!   |\n");
                printf("\t\t\t\t     |_____________________________________|\n\n");
                system("pause");
                system("cls");
                break;
        }
    } while (input != 5);

    return 0;
}

void AddCharacter() {
    char file_name[20];
    int character;
    int level;

    //set specific character array for unique database
    sprintf(file_name, "list%d.txt", file_num);

    printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
    printf("\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t| Add Character                 |\n");
    printf("\t\t\t\t\t|_______________________________|\n\n");


    printf("\t\t\t\t\t _______________________________ \n");
    printf("\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t|  1. Altria                    |\n");
    printf("\t\t\t\t\t|  2. Arcueid                   |\n");
    printf("\t\t\t\t\t|  3. Scathach                  |\n");
    printf("\t\t\t\t\t|  4. Skadi                     |\n");
    printf("\t\t\t\t\t|  5. Morgan                    |\n");
    printf("\t\t\t\t\t|_______________________________|\n\n");
    printf("\t\t\t\t\t   Enter your choice (1-5): ");
    scanf("%d", &character);
    printf("\n");

    printf("\t\t\t\t\t   Enter character level: ");
    scanf("%d", &level);

    //open and append to retain and modify previous data
    FILE *file = fopen(file_name, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
   //store character information into txt file
   if((character >0 && character <6) && (character >0 && level <101)){
    if(character == 1){
        fprintf(file, "Altria %d\n", level);
    }
     else if(character == 2){
        fprintf(file, "Arcueid %d\n", level);
     }
     else if(character == 3){
        fprintf(file, "Scathach %d\n", level);
     }
     else if(character == 4){
        fprintf(file, "Skadi %d\n", level);
     }
     else if(character == 5){
        fprintf(file, "Morgan %d\n", level);
     }

    fclose(file);

    printf("\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t| Character added successfully! |\n");
    printf("\t\t\t\t\t|_______________________________|\n\n");
    system("pause");
    system("cls");
   }
   else{
    printf("\t\t\t\t\t _______________________________\n");
    printf("\t\t\t\t\t|                               |\n");
    printf("\t\t\t\t\t| Invalid Input!                |\n");
    printf("\t\t\t\t\t|_______________________________|\n\n");
    system("pause");

    system("cls");
   }
}


void UpdateLevel() {
    char file_name[20];

    //set specific character array for unique database
    sprintf(file_name, "list%d.txt", file_num);

    //open and read to obtain stored data
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t\t _______________________________\n");
        printf("\t\t\t\t\t|                               |\n");
        printf("\t\t\t\t\t| No characters added!          |\n");
        printf("\t\t\t\t\t|_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }


    Character characters[MAX_CHARACTERS];
    int count = 0, choice, newLevel;
    char name[20];
    int level;

    // stored into struct
    while (fscanf(file, "%s %d\n", name, &level) != EOF) {
        strcpy(characters[count].name, name);
        characters[count].level = level;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t\t _______________________________\n");
        printf("\t\t\t\t\t|                               |\n");
        printf("\t\t\t\t\t| No characters added!          |\n");
        printf("\t\t\t\t\t|_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }

        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t     ___________________________________________________ \n");
        printf("\t\t\t    |                                                   |\n");
        printf("\t\t\t    | Select a character to update the level:           |\n");
        printf("\t\t\t    |___________________________________________________|\n\n");

    //Data displayed
    for (int i = 0; i < count; i++) {
        printf("\t\t\t\t\t         %d. %s\n", i + 1, characters[i].name);
        printf("\t\t\t\t\t________________________________\n\n");
    }


    printf("\t\t\t\t\t   Enter your choice (1-%d): ", count);
    scanf("%d", &choice);
    printf("\n");

    if (choice < 1 || choice > count) {
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | Invalid choice!               |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
    }
    else {

        printf("\t\t\t\t         Enter new level for %s: ", characters[choice - 1].name);
        scanf("%d", &newLevel);
      if(newLevel <1 || newLevel > 100){
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | Invalid Level!                |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
      }

        else{file = fopen(file_name, "w");
        if (file == NULL) {
            printf("Error opening file.\n");
            return;
         }

        for (int i = 0; i < count; i++) {
            if (i == choice - 1) {

                //modify selected character lvl
                fprintf(file, "\t\t\t\t\t%s %d\n", characters[i].name, newLevel);
            } else
            {   //retain unmodified data in txt file
                fprintf(file, "\t\t\t\t\t%s %d\n", characters[i].name, characters[i].level);
            }
        }

        fclose(file);

        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | Level updated successfully!   |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
    }
    }
    system("pause");
    system("cls");
}

void CalculateExperience() {

    char file_name[20];

    //set specific character array for unique database
    sprintf(file_name, "list%d.txt", file_num);

    //open and read to obtain stored data
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t\t _______________________________\n");
        printf("\t\t\t\t\t|                               |\n");
        printf("\t\t\t\t\t| No characters added!          |\n");
        printf("\t\t\t\t\t|_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }


    Character characters[MAX_CHARACTERS];
    int count = 0, choice, ExperienceRequired;
    char name[20];
    int level;

    // stored into struct
    while (fscanf(file, "%s %d\n", name, &level) != EOF) {
        strcpy(characters[count].name, name);
        characters[count].level = level;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | No characters added!          |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }

        printf("\t\t\t         ______________________________________________\n");
        printf("\t\t\t        |                                              |\n");
        printf("\t\t\t        | Select a character to calculate experience:  |\n");
        printf("\t\t\t        |______________________________________________|\n\n");

    //display character information from struct
    for (int i = 0; i < count; i++) {
        printf("\t\t\t\t\t         %d. %s\n", i + 1, characters[i].name);
        printf("\t\t\t\t\t________________________________\n\n");
    }


    printf("\t\t\t\t\t   Enter your choice (1-%d): ", count);
    scanf("%d", &choice);
    printf("\n");

    if (choice < 1 || choice > count) {
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | Invalid choice!               |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
    } else {
        int currentLevel = characters[choice - 1].level;
        if (currentLevel >= 100) {
            printf("\t\t\t\t\t _______________________________\n");
            printf("\t\t\t\t\t|                               |\n");
            printf("\t\t\t\t\t| Already at maximum level!     |\n");
            printf("\t\t\t\t\t|_______________________________|\n\n");
        } else {
            //recursion to calculate exp required
            ExperienceRequired = calculation(currentLevel);


            printf("\t\t\t    Experience required to level up to 100 for %s: %d         \n\n", characters[choice - 1].name, ExperienceRequired);

        }
    }

    system("pause");
    system("cls");
}


//recursion function
int calculation(int level)
{
    if (level >= 100) {
        return 0;
    } else {
        return (100 * pow(level, 1.5)) + calculation(level + 1);
    }
}






void ListCharacters() {

    char file_name[20];

    //set specific character array for unique database
    sprintf(file_name, "list%d.txt", file_num);

    //open and read to obtain stored data
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | No characters added!          |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }


    Character characters[MAX_CHARACTERS];
    int count = 0;
    char name[20];
    int level;

    //store information
    while (fscanf(file, "%s %d\n", name, &level) != EOF) {
        strcpy(characters[count].name, name);
        characters[count].level = level;
        count++;
    }

    fclose(file);

    if (count == 0) {
        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t        _______________________________\n");
        printf("\t\t\t\t       |                               |\n");
        printf("\t\t\t\t       | No characters added!          |\n");
        printf("\t\t\t\t       |_______________________________|\n\n");
        system("pause");
        system("cls");
        return;
    }

        printf("oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo.oOo\n\n");
        printf("\t\t\t\t           _______________________________\n");
        printf("\t\t\t\t          |                               |\n");
        printf("\t\t\t\t          | Character List:               |\n");
        printf("\t\t\t\t          |_______________________________|\n\n");


    //display information
    for (int i = 0; i < count; i++) {
        printf("\t\t\t\t\t         %d. %s - Level %d          \n", i+1, characters[i].name, characters[i].level);
        printf("\t\t\t\t\t____________________________________\n\n");
    }

    system("pause");
    system("cls");
}

