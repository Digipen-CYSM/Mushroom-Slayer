#include "cprocessing.h"
#include "tutorial.h"

float animateButtons = 0;
int i;
CP_Image buttonsStart[5], buttonsExit[5];
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
}

void main_menu_update(void)
{
	CP_Image_Draw(buttonsStart[0], 850, 450, 300, 150, 255);
	CP_Image_Draw(buttonsExit[0], 850, 650, 300, 150, 255);
	animateButtons += CP_System_GetDt();
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
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 1000)
	{
		if (CP_Input_GetMouseY() >= 575 && CP_Input_GetMouseY() <= 725)
		{
			if (CP_Input_MouseClicked())
			{
				if (animateButtons >= 0.6f) {
					i++;
				}
				CP_Image_Draw(buttonsExit[i], 850, 650, 300, 150, 255);
				CP_Engine_Terminate();
			}
		}
	}
}

void main_menu_exit(void)
{

}