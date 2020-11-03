#include "cprocessing.h"
#include "game.h"
void main_menu_init(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	//CP_Graphics_DrawRect(450, 100, 800, 200);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/background.jpg"), 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/title.png"), 850, 200, 1000, 300, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/startButton.png"), 850, 450, 300, 150, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/exitButton.png"), 850, 650, 300, 150, 255);
	//CP_Graphics_DrawRect(450, 100, 800, 200);
	//CP_Graphics_DrawRect(700, 400, 300, 150);
	//CP_Graphics_DrawRect(700, 600, 300, 150);
}

void main_menu_update(void)
{
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 375 && CP_Input_GetMouseY() <= 525)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_SetNextGameState(Game_Init, Game_Update, Game_Exit);
			}
		}
	}
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 575 && CP_Input_GetMouseY() <= 725)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
}

void main_menu_exit(void)
{
}