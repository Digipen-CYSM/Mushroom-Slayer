#include "cprocessing.h"

void main_menu_init(void)
{
	CP_Settings_Background(CP_Color_Create(0, 0, 0, 255));
	CP_Graphics_DrawRect(450, 100, 800, 200);
	CP_Graphics_DrawRect(700, 400, 300, 150);
	CP_Graphics_DrawRect(700, 600, 300, 150);
}

void main_menu_update(void)
{

}

void main_menu_exit(void)
{
}