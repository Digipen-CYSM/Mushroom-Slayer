//---------------------------------------------------------
// file:	main.c
// author:	[Name]
// email:	[Digpen Email]
//
// brief:	Main entry point for the sample project
//			of the CProcessing library
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "MainMenu.h"
#include "digipenload.h"

int main(void)
{
	CP_System_SetWindowSize(1700, 900);
	CP_Engine_SetNextGameState(digipenload_init, digipenload_update, digipenload_exit);
	CP_Engine_Run();
	return 0;
}
