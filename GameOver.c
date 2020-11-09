#include "cprocessing.h"

void game_over_init(void)
{
	CP_Image_Draw(CP_Image_Load("Assets/mainMenu/background.png"), 850, 450, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight(), 255);

}

void game_over_update(void)
{
	CP_Settings_TextSize(300);
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
	CP_Font_DrawText("Game Over!", 450, 450);
}

void victory_update(void)
{
	CP_Settings_TextSize(300);
	CP_Settings_Fill(CP_Color_Create(0, 0, 0, 255));
	CP_Font_DrawText("Victory!", 450, 450);
}

void game_over_exit(void)
{

}