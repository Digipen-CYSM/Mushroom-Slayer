//---------------------------------------------------------
// file:	MainMenu.c
// author:	Ho Yan Ying, Camie
//			Zhuo Yijian
// email:	y.ho@digipen.edu
//			Zhuo Yijian
//
// brief:	
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include <stdio.h>
#include "cprocessing.h"
#include "MainMenu.h"

CP_Image Credit[4];
float counter = 0;
int count = 0;

void Credit_Init(void)
{
    counter = 0;
    count = 0;
    //loading images into a array
    Credit[0] = CP_Image_Load("Assets/Credits/Credit_1.png");
    Credit[1] = CP_Image_Load("Assets/Credits/Credit_2.png");
    Credit[2] = CP_Image_Load("Assets/Credits/Credit_3.png");
    Credit[3] = CP_Image_Load("Assets/Credits/Credit_4.png");

}

//Printing credits screen 
void Credit_Update(void)
{
    CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
    CP_Image_Draw(Credit[count], 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);
    ++counter;
    if (counter == 127)
    {
        ++count;
        CP_Image_Draw(Credit[count], 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);
        counter = 0;
    }

    if (count == 4)
    {
        CP_Engine_SetNextGameState(main_menu_init, main_menu_update, main_menu_exit);
    }
}

void Credit_Exit(void)
{
    //Freeing up loaded credit image
    /*CP_Image_Free(Credit);
    CP_Image_Free(&Background_Image);*/
}