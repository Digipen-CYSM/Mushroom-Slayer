#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include "GameLoad.h"
#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
CP_Image confirmButton, backGround, enemyImg, healthImg, playerImg;


void loadImg(void) {
	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
	//load background img
	backGround = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
	//load enemy img
	enemyImg = CP_Image_Load("Assets/enemy/ms1.png");

	playerImg = CP_Image_Load("Assets/character/Character.png");
}

void drawBg(void) {
	CP_Image_Draw(backGround, 850, 600, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() + 300, 255);
	//enemy image
	CP_Image_Draw(enemyImg, 1300, 470, 300, 400, 255);
	//player image
	CP_Image_Draw(playerImg, 400, 470, 270, 370, 255);
}

void drawConfrim(void) {
	//show confirm button
	CP_Image_Draw(confirmButton, 850, 100, 200, 50, 255);
}

void confirmPressed(int* handCheck, CardType* hand, Player* player, Enemy* enemy, int handSize,CardType* deck) {
	if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950 && CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125) {
		if (CP_Input_MouseClicked()) {
			for (int i = 0; i < handSize; i++) {
				if (handCheck[i] == 1) {
					if (hand[i].type == 'a') {
						attackCard(enemy,hand[i].ret);
												
					}
					else if (hand[i].type == 'd') {
						defenceCard(hand[i].ret, player);										
					}
					else
					{
						handCheck[i] = 0;
						break;
					}
					handCheck[i] = 0;
					player->mana += hand[i].mana;

				}
			}
			drawCards(deck, handSize, 0);
		}		
	}
}
