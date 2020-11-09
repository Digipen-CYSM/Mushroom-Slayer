#include "cprocessing.h"
#include "game.h"
#include "Cards.h"
#include <string.h>
#include <stdio.h>
#include "GameOver.h"
//global variable
float pHealth = 20, eHealth = 20, time = 0, timeFloat;
CardType hand[5];
CardType deck[10];
int handRng[5];
int handCheck[5] = {0,0,0,0,0};
int selectedCheck[5] = { 0,0,0,0,0 };
int mana = 5,enemyMove = 0;
int oneToTen;
char manaStr2[10];
CP_Image handS[10][3];
CP_Image manaSrc[10];
CP_Image confirmButton, backGround, enemyImg,healthImg, playerImg;

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
	//draw 5 random card from deck ,should load all image including inside the deck, atm i is according to hand position
	for (int i = 0; i < 5; i++) {
		int rCheck = 1;
		while (rCheck == 1) {
			rCheck = 0;
			oneToTen = CP_Random_RangeInt(0, 9);
			for (int j = 0; j < 5; j++) {
				if (handRng[j] == oneToTen && i!=0) {
					rCheck = 1;
				}
			}
			

		}
		handRng[i] = oneToTen;
		hand[i] = deck[oneToTen];
	}


	//load mana bar img and deck img
	for (int i = 0; i < 10; i++) {
		handS[i][0] = CP_Image_Load(deck[i].baseSrc);
		handS[i][1] = CP_Image_Load(deck[i].valSrc);
		handS[i][2] = CP_Image_Load(deck[i].manaSrc);
		char str[100] = "Assets/manaBar/mana";
		int manaStr = 48+i;
		manaStr2[0] = (char)manaStr;
		strcat_s(str, sizeof(str), manaStr2);
		strcat_s(str, sizeof(str), ".png");

		manaSrc[i] = CP_Image_Load(str);
	}

	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
	//load background img
	backGround = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
	//load enemy img
	enemyImg = CP_Image_Load("Assets/enemy/ms1.png");
	healthImg = CP_Image_Load("Assets/health.jpg");
	playerImg = CP_Image_Load("Assets/character/Character.png");
}


void Game_Update(void)
{	
	time += CP_System_GetDt();
	//background animation
	CP_Image_Draw(backGround, 850, 600, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() + 300, 255);
	
	if (enemyMove == 1) {
		if (time < timeFloat + 3) {
			CP_Image_Draw(handS[0][0], 1500, 300, 200, 300, 255); //card base
			CP_Image_Draw(handS[0][1], 1500, 407, 170, 80, 255); //card value
			CP_Image_Draw(handS[0][2], 1500 - 67, 170, 41, 23, 255); //card mana
		}
		else {
			enemyMove = 0;
			pHealth -= 3;
		}
	}
	if (pHealth == 0)
	{
		CP_Engine_SetNextGameState(game_over_init, game_over_update, game_over_exit);
	}
	//enemy image
	CP_Image_Draw(enemyImg, 1300, 470, 300, 400, 255);
	//enemy health and mana
	CP_Image_Draw(healthImg, 1300, 300, eHealth*15, 30, 255);
	//CP_Image_Draw(CP_Image_Load("Assets/health.jpg"), 1300, 270, eHealth, 30, 255);
	
	//player image
	CP_Image_Draw(playerImg, 400, 470, 270, 370, 255);


	//player health and mana
	CP_Image_Draw(healthImg, 400, 300, pHealth*15, 30, 255);
	CP_Image_Draw(manaSrc[mana], 50, 500, 50, 300, 255);
	


	float cardWidth = 550;
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
		CP_Image_Draw(confirmButton, 850, 100, 200, 50, 255);
	}

	
	//know the index of selected card
	int sCheck = 0;
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			selectedCheck[sCheck] = i;
			sCheck += 1;
		}
	}

	//Confirm button
	if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950) {
		if (CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125) {
			if (CP_Input_MouseClicked()) {
				for (int i = 0; i < selectedCount; i++) {
					//if its attack card
					if (hand[selectedCheck[i]].type == 'a') {
						if (eHealth <= 0) {
							eHealth = 0;
							CP_Engine_SetNextGameState(game_over_init, victory_update, game_over_exit);
						}
						else {
							eHealth -= hand[selectedCheck[i]].ret;
						}
						
					}
					//if its def card
					if (hand[selectedCheck[i]].type == 'd') {
						//pHealth = pHealth - 10;
					}
					//if its healing card
					if (hand[selectedCheck[i]].type == 'h') {
						if ((pHealth + hand[selectedCheck[i]].ret) > 20) {
							pHealth = 20;
						}
						else {
							pHealth += hand[selectedCheck[i]].ret;
						}
						
					}						
					mana += hand[selectedCheck[i]].mana;
					
					//generate new number that is not included in handRng
					int rCheck = 1;					
					while (rCheck == 1) {
						rCheck = 0;
						oneToTen = CP_Random_RangeInt(0, 9);
						for (int j = 0; j < 5; j++) {
							if (handRng[j] == oneToTen) {
								rCheck = 1;
							}
						}
						
					}
					handRng[selectedCheck[i]] = oneToTen;
					//replace selected card in hand[] 
					hand[selectedCheck[i]] = deck[oneToTen];
					
					//reset selected
					handCheck[selectedCheck[i]] = 0;
					
					//(void)selectedCheck[i];
				}
				selectedCount = 0;
				timeFloat = time;
				enemyMove = 1;
			}
			
			
		}
	}
	
	

	//draw card image based on selected and unselected
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
			CP_Image_Draw(handS[handRng[i]][0], cardWidthS, 300, 200, 300, 255); //card base
			CP_Image_Draw(handS[handRng[i]][1], cardWidthS, 407, 170, 80, 255); //card value
			CP_Image_Draw(handS[handRng[i]][2], cardWidthS - 67, 170, 41, 23, 255); //card mana
		}else{
			CP_Image_Draw(handS[handRng[i]][0], cardWidth, 750, 150, 230, 255); //card base
			CP_Image_Draw(handS[handRng[i]][1], cardWidth, 830, 130, 60, 255); //card value
			CP_Image_Draw(handS[handRng[i]][2], cardWidth - 52, 650, 36, 20, 255); //card mana
		}
		cardWidth = cardWidth + 135;
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
	//redeclare card width
	cardWidth = 495;
	//generate mouse collision for unselected cards
	for (int i = 0; i < 5; i++) {
		if (CP_Input_GetMouseX() >= cardWidth && CP_Input_GetMouseX() <= cardWidth+130)
		{
			if (CP_Input_GetMouseY() >= 635 && CP_Input_GetMouseY() <= 865)
			{
				if (CP_Input_MouseClicked())
				{
					if (hand[i].mana <= mana) {
						if (handCheck[i] == 0) {
							handCheck[i] = 1;
							mana -= hand[i].mana;
						}

					}
				}
			}
		}
		cardWidth += 135;
	}	

}

void Game_Exit(void) {

}
