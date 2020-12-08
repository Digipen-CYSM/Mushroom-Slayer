//---------------------------------------------------------
// file:	game.c
// author:	Ho Yan Ying, Camie
//			
// email:	y.ho@digipen.edu
//
// brief:	starting screen of digipen logo
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "MainMenu.h"
int fade;
void digipenload_init(void)
{
	CP_Settings_Background(CP_Color_Create( 0, 0, 0, 255));
	fade = 0;

}
void digipenload_update(void)
{
	int width = CP_System_GetWindowWidth();
	int height = CP_System_GetWindowHeight();
	CP_Image_Draw(CP_Image_Load("Assets/DigiPen_RED.png"), (float)width/2, (float)height/2, (float)width/2, (float)height/2, fade);
	if (fade <= 255)
	{
		fade += 3;
	}

	if (fade >= 255)
	{
		CP_Engine_SetNextGameState(main_menu_init, main_menu_update, main_menu_exit);
	}
	
}
void digipenload_exit(void)
{

}
