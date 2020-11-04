//---------------------------------------------------------
// file:	main.c
// author:	[NAME]
// email:	[DIGIPEN EMAIL ADDRESS]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright � 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "MainMenu.h"

int main(void)
{
	//test
	CP_System_SetWindowSize(1700, 900);
	CP_Engine_SetNextGameState(main_menu_init, main_menu_update, main_menu_exit);
	CP_Engine_Run();
	return 0;
}
