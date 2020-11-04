#include "cprocessing.h"
#include "game.h"
#include "Cards.h"

//global variable
float pHealth = 300, eHealth = 300;
CardType hand[5];
CardType deck[];
int deckSize = 10;

void Game_Init(void)
{
	CP_Settings_Background(CP_Color_Create(255, 255, 255, 255));
	//enemy image
	CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), 1300, 400, 200, 300, 255);
	//player image
	CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), 400, 400, 200, 300, 255);
	//player health
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, 300, 30, 255);

}

void Game_Update(void)
{	
	float cardWidth = 200;
	for (int i = 0; i < 5; i++) {
		CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), cardWidth, 700, 200, 300, 255); //card base
		CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), cardWidth, 700, 30, 30, 255); //card value
		cardWidth = cardWidth + 300;
	}

	//player health
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, pHealth, 30, 255);
	//enemy health
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 1300, 250, eHealth, 30, 255);

	//click on card 1
	if (CP_Input_GetMouseX() >= 100 && CP_Input_GetMouseX() <= 300)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
	//click on card 2
	if (CP_Input_GetMouseX() >= 400 && CP_Input_GetMouseX() <= 600)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
	//click on card 3
	if (CP_Input_GetMouseX() >= 700 && CP_Input_GetMouseX() <= 900)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
	//click on card 4
	if (CP_Input_GetMouseX() >= 1000 && CP_Input_GetMouseX() <= 1200)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
	//click on card 5
	if (CP_Input_GetMouseX() >= 1300 && CP_Input_GetMouseX() <= 1500)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				CP_Engine_Terminate();
			}
		}
	}
	


}

void Game_Exit(void) {

}
