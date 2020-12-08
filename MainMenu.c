//---------------------------------------------------------
// file:	MainMenu.c
// author:	Ho Yan Ying, Camie
//			Zhuo Yijian
// email:	y.ho@digipen.edu
//			Zhuo Yijian
//
// brief:	draw image for main menu
//			start button to go into game, 
//			exit button to terminate game
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include "tutorial.h"
#include "credits.h"

float animateButtons = 0;
int i;
CP_Image buttonsStart[5], buttonsExit[5], buttons_credits[5];
void main_menu_init(void)
{
	i = 0;
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/background.png"), 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/title.png"), 850, 200, 1000, 300, 255);
	buttonsStart[0] = CP_Image_Load("Assets/menubuttons/start/start1.png");
	buttonsStart[1] = CP_Image_Load("Assets/menubuttons/start/start2.png");
	buttonsStart[2] = CP_Image_Load("Assets/menubuttons/start/start3.png");
	buttonsStart[3] = CP_Image_Load("Assets/menubuttons/start/start4.png");
	buttonsStart[4] = CP_Image_Load("Assets/menubuttons/start/start5.png");
	buttonsExit[0] = CP_Image_Load("Assets/menubuttons/exit/exit1.png");
	buttonsExit[1] = CP_Image_Load("Assets/menubuttons/exit/exit2.png");
	buttonsExit[2] = CP_Image_Load("Assets/menubuttons/exit/exit3.png");
	buttonsExit[3] = CP_Image_Load("Assets/menubuttons/exit/exit4.png");
	buttonsExit[4] = CP_Image_Load("Assets/menubuttons/exit/exit5.png");
	buttons_credits[0] = CP_Image_Load("Assets/menubuttons/credits/credits1.png");
	buttons_credits[1] = CP_Image_Load("Assets/menubuttons/credits/credits2.png");
	buttons_credits[2] = CP_Image_Load("Assets/menubuttons/credits/credits3.png");
	buttons_credits[3] = CP_Image_Load("Assets/menubuttons/credits/credits4.png");
	buttons_credits[4] = CP_Image_Load("Assets/menubuttons/credits/credits5.png");
}

void main_menu_update(void)
{
	CP_Image_Draw(buttonsStart[0], 850, 450, 300, 150, 255);
	CP_Image_Draw(buttonsExit[0], 850, 600, 300, 150, 255);
	CP_Image_Draw(buttons_credits[0], 850, 750, 300, 150, 255);
	animateButtons += CP_System_GetDt();

	//start button
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 375 && CP_Input_GetMouseY() <= 525)
		{
			if (CP_Input_MouseClicked())
			{
				if (animateButtons >= 0.6f) {
					i++;
				}
				CP_Image_Draw(buttonsStart[i], 850, 450, 300, 150, 255);
				CP_Engine_SetNextGameState(tutorial_init, tutorial_update, tutorial_exit);
				
			}
		}
	}

	//exit button
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 525 && CP_Input_GetMouseY() <= 675)
		{
			if (CP_Input_MouseClicked())
			{
				if (animateButtons >= 0.6f) {
					i++;
				}
				CP_Image_Draw(buttonsExit[i], 850, 600, 300, 150, 255);
				CP_Engine_Terminate();
			}
		}
	}

	//credits
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 675 && CP_Input_GetMouseY() <= 825)
		{
			if (CP_Input_MouseClicked())
			{
				if (animateButtons >= 0.6f) {
					i++;
				}
				CP_Image_Draw(buttons_credits[i], 850, 750, 300, 150, 255);
				CP_Engine_SetNextGameState(Credit_Init, Credit_Update, Credit_Exit);
			}
		}
	}
}

void main_menu_exit(void)
{
	CP_Image_Free(buttonsStart);
	CP_Image_Free(buttonsExit);
	CP_Image_Free(buttons_credits);
}