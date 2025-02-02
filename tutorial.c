//---------------------------------------------------------
// file:	Perks.c
// author:	Zhuo Yijian
//			Ho Yan Ying, Camie
// email:	yijian.zhuo@digipen.edu
//			y.ho@digipen.edu
//
// brief:	draw gameplay infomation for player
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "game.h"

void tutorial_init(void)
{
	CP_Image_Draw(CP_Image_Load("Assets/dojo/tutorial.png"), 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);
}

void tutorial_update(void)
{
	if (CP_Input_GetMouseX() >= 720 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 380 && CP_Input_GetMouseY() <= 520)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Exit);
			}
		}
	}
}


void tutorial_exit(void)
{

}