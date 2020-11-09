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
	CP_Font_DrawText("Game Over!", 450, 450);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/Exit.png"), 850, 630, 500, 170, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/exitButton.png"), 850, 750, 300, 150, 255);
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		CP_Engine_SetNextGameState(main_menu_init, main_menu_update, main_menu_exit);
	}
}

void victory_update(void)
{
	CP_Settings_TextSize(300);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("Victory!", 450, 450);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/Exit.png"), 850, 630, 500, 170, 255);
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/exitButton.png"), 850, 750, 300, 150, 255);
	if (CP_Input_KeyTriggered(KEY_ESCAPE))
	{
		CP_Engine_SetNextGameState(main_menu_init, main_menu_update, main_menu_exit);
	}
}

void game_over_exit(void)
{

}