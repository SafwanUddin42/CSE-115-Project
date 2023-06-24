#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

#include "splash.h"
#include "login.h"
#include "menu.h"



int file_num;

int main(void)
{
    //functions called for program

    sscreen();

    login();

    main_menu();


    return 0;

}
