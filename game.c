#include "cprocessing.h"
#include "game.h"
#include "Cards.h"
#include <string.h>
#include <stdio.h>
//global variable
float pHealth = 300, eHealth = 300;
CardType hand[5];
CardType deck[10];
int handRng[5];
int handCheck[5] = {0,0,0,0,0};
int selectedCheck[5] = { 0,0,0,0,0 };
int mana = 5;
CP_Image handU[5][3];
CP_Image handS[5][3];

void Game_Init(void)
{
	
	//generate cards into deck
	for (int i = 0; i < 10; i++) {
		if(i<4){
			deck[i] = attackCard();
		}
		else if (i<7) {
			deck[i] = defenceCard();
		}
		else {
			deck[i] = healCard();
		}
		
	}
	//draw 5 random card from deck
	for (int i = 0; i < 5; i++) {
		int rCheck = 0;
		int oneToTen;
		oneToTen = CP_Random_RangeInt(0, 9);
		while (rCheck == 1) {			
			rCheck = 0;					
			for (int j = 0; j < 5; j++) {
				if (handRng[j] == oneToTen) {
					rCheck = 1;
				}
			}
			oneToTen = CP_Random_RangeInt(0, 9);
			
		};
		handRng[i] = oneToTen;
		hand[i] = deck[oneToTen];
		handS[i][0] = CP_Image_Load(hand[i].baseSrc);
		handS[i][1] = CP_Image_Load(hand[i].baseSrc);
		handS[i][2] = CP_Image_Load(hand[i].baseSrc);
		handU[i][0] = CP_Image_Load(hand[i].baseSrc);
		handU[i][1] = CP_Image_Load(hand[i].baseSrc);
		handU[i][2] = CP_Image_Load(hand[i].baseSrc);
	}

	
}


void Game_Update(void)
{	
	CP_Settings_Background(CP_Color_Create(255, 255, 255, 255));
	//enemy image
	CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), 1300, 400, 200, 300, 255);
	//player image
	CP_Image_Draw(CP_Image_Load("Assets/enemy/ms1.png"), 400, 400, 200, 300, 255);

	//player health and mana
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, pHealth, 30, 255);
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 270, pHealth, 30, 255);
	//enemy health and mana
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 1300, 250, eHealth, 30, 255);
	CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 1300, 270, eHealth, 30, 255);


	float cardWidth = 200;
	int selectedCount = 0;
	float cardWidthS = 350;
	//get total number of selected cards
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			selectedCount += 1;
		}
	}
	//show confirm button 
	if (selectedCount > 0) {
		CP_Image_Draw(CP_Image_Load("Assets/confirmButton1.png"), 850, 100, 200, 50, 255);

	}
	//Confirm button
	if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950)
	{
		if (CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125)
		{
			if (CP_Input_MouseClicked())
			{
				for (int i = 0; i < 5; i++) {
					if (handCheck[i] == 1 && hand[i].type == 'a') {
						eHealth = eHealth - (50 * selectedCount);
						pHealth = pHealth - 50;
						CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 1300, 250, eHealth, 30, 255);
						CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, pHealth, 30, 255);
					}
					if (handCheck[i] == 1 && hand[i].type == 'd') {
						pHealth = pHealth - 10;
						CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, pHealth, 30, 255);
					}
					if (handCheck[i] == 1 && hand[i].type == 'h') {
						pHealth = pHealth - 50;
						pHealth = pHealth + 30;
						if (pHealth >= 300) {
							pHealth = 300;
						}
						CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 400, 250, pHealth, 30, 255);
					}
				}
				for (int i = 0; i < 5; i++) {
					mana += hand[selectedCheck[i]].mana;
					selectedCount -= 1;
					handCheck[selectedCheck[i]] = 0;
					cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
				}
			}
		}
	}
	//know the index of selected card
	int sCheck = 0;
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			selectedCheck[sCheck] = i;
			sCheck += 1;
		}
	}
	//draw card image based on selected and unselected
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
			CP_Image_Draw(handS[i][0], cardWidthS, 300, 200, 300, 255); //card base
			CP_Image_Draw(handS[i][1], cardWidthS, 300, 30, 30, 255); //card value
			CP_Image_Draw(handS[i][2], cardWidthS, 250, 30, 30, 255); //card mana
		}
		else {
			CP_Image_Draw(handU[i][0], cardWidth, 700, 200, 300, 255); //card base
			CP_Image_Draw(handU[i][1], cardWidth, 700, 30, 30, 255); //card value
			CP_Image_Draw(handU[i][2], cardWidth, 650, 30, 30, 255); //card mana
		}
		cardWidth = cardWidth + 300;
	}

	cardWidthS = 350; //redeclare card width selected

	//click on selected card and bring down
	if (selectedCount > 0) {
		for (int i = 0; i < selectedCount; i++) {
			if (CP_Input_GetMouseX() >= 1000 / (float)(selectedCount + 1) + cardWidthS - 100 && CP_Input_GetMouseX() <= 1000 / (float)(selectedCount + 1) + cardWidthS + 100) {
				if (CP_Input_GetMouseY() >= 150 && CP_Input_GetMouseY() <= 450) {
					if (CP_Input_MouseClicked()) {						
						//mana, selected count, handCheck
						mana += hand[selectedCheck[i]].mana;
						selectedCount -= 1;
						handCheck[selectedCheck[i]] = 0;
					}
				}
			}
			
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
		}
	}
	
	

	//click on card 1
	if (CP_Input_GetMouseX() >= 100 && CP_Input_GetMouseX() <= 300)
	{
		if (CP_Input_GetMouseY() >= 550 && CP_Input_GetMouseY() <= 850)
		{
			if (CP_Input_MouseClicked())
			{
				if (hand[0].mana < mana) {				
					if (handCheck[0] == 0) {
						handCheck[0] = 1;
						mana -= hand[0].mana;
					}
					
					
				}
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
				if (hand[1].mana < mana) {
					if (handCheck[1] == 0) {
						handCheck[1] = 1;
						mana -= hand[1].mana;
					}
				}
				
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
				if (hand[2].mana < mana) {
					if (handCheck[2] == 0) {
						handCheck[2] = 1;
						mana -= hand[2].mana;
					}

				}
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
				if (hand[3].mana < mana) {
					if (handCheck[3] == 0) {
						handCheck[3] = 1;
						mana -= hand[3].mana;
					}
				}
				
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
				if (hand[4].mana < mana) {
					if (handCheck[4] == 0) {
						handCheck[4] = 1;
						mana -= hand[4].mana;
					}

				}
			}
		}
	}
	
	if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950)
	{
		if (CP_Input_GetMouseY() >= 400 && CP_Input_GetMouseY() <= 450)
		{
			if (CP_Input_MouseClicked()) {
				
			}
		}
	}
}

void Game_Exit(void) {

}
