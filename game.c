#include "cprocessing.h"
#include "game.h"
#include "Cards.h"
#include <string.h>
#include <stdio.h>
#include "GameOver.h"
#include "GameLoad.h"
#include "Character.h"
#include "Enemy.h"
//global variable
float time = 0, timeFloat;
int pHealth = 20, eHealth = 20, nCheck;
CardType* hand;
CardType* deck;

int handCheck[5] = {0,0,0,0,0}; //change to dynamic
int* handCheckP = handCheck;
int selectedCheck[5] = { 0,0,0,0,0 };
int mana = 3,enemyMove = 0;
CP_Image confirmButton;
void Game_Init(void)
{
	//load bg, char, enemy src
	loadImg();

	//generate deck array
	deck = generateDeck();

	//generate card in hand
	hand = drawCards(deck, 5, 1);

	//load deck img src
	loadDeckImg(deck, 10);

	//load player hp and mana img src
	hpAndManaLoad();

	//load enemy img src
	hpLoadE();

	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");

	
}


void Game_Update(void)
{	
	time += CP_System_GetDt();

	//draw background, char, enemy
	drawBg();	

	//draw player health and mana
	drawHealthSrc(pHealth);
	drawManaSrc(mana);

	//draw enemy hp
	drawHealthSrcE(eHealth);

	float cardWidth = 420;
	int selectedCount = 0;
	float cardWidthS = 350;
	
	for (int i = 0; i < 5; i++) {
		if (CP_Input_GetMouseX() >= cardWidth && CP_Input_GetMouseX() <= cardWidth + 150)
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
	for (int i = 0; i < 5; i++) {
		if (handCheck[i] == 1) {
			selectedCount += 1;
		}
	}
	cardWidthS = 350;
	//click on selected card and bring down
	if (selectedCount > 0) {
		for (int i = 0; i < selectedCount; i++) {
			if (CP_Input_GetMouseX() >= 1000 / (float)(selectedCount + 1) + cardWidthS - 100 && CP_Input_GetMouseX() <= 1000 / (float)(selectedCount + 1) + cardWidthS + 100) {
				if (CP_Input_GetMouseY() >= 150 && CP_Input_GetMouseY() <= 450) {
					if (CP_Input_MouseClicked()) {
						//mana, selected count, handCheck
						nCheck = 0;
						for (int j = 0; j < 5; j++) {
							if (handCheckP[j] == 1 && nCheck == i) {
								mana += hand[j].mana;
								handCheckP[j] = 0;
								break;
							}
							if (handCheckP[j] == 1) {
								nCheck += 1;
							}
						}
						//selectedCount -= 1;//might not work
					}
				}
			}
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
		}
	}
	
	//draw hand src
	drawHandSrc(handCheckP, selectedCount);

	
	
	//enemy move
	//if (enemyMove == 1) {
	//	if (time < timeFloat + 3) {
	//		CP_Image_Draw(handS[0][0], 1500, 300, 200, 300, 255); //card base
	//		CP_Image_Draw(handS[0][1], 1500, 407, 170, 80, 255); //card value
	//		CP_Image_Draw(handS[0][2], 1500 - 67, 170, 41, 23, 255); //card mana
	//	}
	//	else {
	//		enemyMove = 0;
	//		pHealth -= 3;
	//	}
	//}
	//if (pHealth == 0)
	//{
	//	CP_Engine_SetNextGameState(game_over_init, game_over_update, game_over_exit);
	//}	
	



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
	//if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950) {
	//	if (CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125) {
	//		if (CP_Input_MouseClicked()) {
	//			for (int i = 0; i < selectedCount; i++) {
	//				//if its attack card
	//				if (hand[selectedCheck[i]].type == 'a') {
	//					if (eHealth <= 0) {
	//						eHealth = 0;
	//						CP_Engine_SetNextGameState(game_over_init, victory_update, game_over_exit);
	//					}
	//					else {
	//						eHealth -= hand[selectedCheck[i]].ret;
	//					}
	//					
	//				}
	//				//if its def card
	//				if (hand[selectedCheck[i]].type == 'd') {
	//					//pHealth = pHealth - 10;
	//				}				
	//				mana += hand[selectedCheck[i]].mana;
	//				
	//				//generate new number that is not included in handRng
	//				int rCheck = 1;					
	//				while (rCheck == 1) {
	//					rCheck = 0;
	//					oneToTen = CP_Random_RangeInt(0, 9);
	//					for (int j = 0; j < 5; j++) {
	//						if (handRng[j] == oneToTen) {
	//							rCheck = 1;
	//						}
	//					}
	//					
	//				}
	//				handRng[selectedCheck[i]] = oneToTen;
	//				//replace selected card in hand[] 
	//				hand[selectedCheck[i]] = deck[oneToTen];
	//				
	//				//reset selected
	//				handCheck[selectedCheck[i]] = 0;
	//				
	//				//(void)selectedCheck[i];
	//			}
	//			selectedCount = 0;
	//			timeFloat = time;
	//			enemyMove = 1;
	//		}
	//		
	//		
	//	}
	//}
	
	



}

void Game_Exit(void) {

}
