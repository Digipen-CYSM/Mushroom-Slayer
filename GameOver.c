//---------------------------------------------------------
// file:	MainMenu.c
// author:	Zhuo Yijian
//			Ho Yan Ying, Camie
// email:	yijian.zhuo@digipen.edu
//			y.ho@digipen.edu
//
// brief:	game over or victory screen
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "MainMenu.h"

void game_over_init(void)
{
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/background.png"), 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);

}

void game_over_update(void)
{
	CP_Settings_TextSize(300);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Font_DrawText("Game Over!", 210, 450);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/Exit.png"), 850, 630, 850, 200, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/exitButton.png"), 850, 750, 300, 150, 255);
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		CP_Engine_Terminate();
	}
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 680 && CP_Input_GetMouseY() <= 820)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
}

void victory_update(void)
{
	CP_Settings_TextSize(300);
	CP_Settings_Fill(CP_Color_Create(0, 100, 0, 255));
	CP_Font_DrawText("Victory!", 410, 450);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/Exit.png"), 850, 630, 850, 200, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/exitButton.png"), 850, 750, 300, 150, 255);
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		CP_Engine_Terminate();
	}
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 680 && CP_Input_GetMouseY() <= 820)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
}

void game_over_exit(void)
{

}