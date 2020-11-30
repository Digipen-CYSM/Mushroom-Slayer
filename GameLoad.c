#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include "GameLoad.h"
#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
#include "Perks.h"
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
void drawEnemyCard(int* turns) {
	if ((*turns % 3) == 0) {
		CP_Image_Draw(CP_Image_Load("Assets/cards/attack2.png"), 1550, 470, 150, 230, 255);
	}
	else {
		CP_Image_Draw(CP_Image_Load("Assets/cards/attack1.png"), 1550, 470, 150, 230, 255);
	}
}
void confirmPressed(int* handCheck, CardType* hand, Player* player, Enemy* enemy, int handSize, CardType* deck, int pressed, int* turns) {
	if (pressed == 1) {
		if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950 && CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125) {
			if (CP_Input_MouseClicked()) {
				int damage = 0, defence = 0;
				for (int i = 0; i < handSize; i++) {
					if (handCheck[i] == 1) {
						if (hand[i].type == 'a') {
							damage += hand[i].ret;
						}
						else if (hand[i].type == 'd') {
							defence += hand[i].ret;							
						}
						else
						{
							handCheck[i] = 0;
							break;
						}
						handCheck[i] = 0;
						
						
					}
				}
				player->mana = player->oMana;
				attackCard(enemy, damage);
				defenceCard(defence, player);
				drawCards(deck, handSize, 0,hand);
				char print[100];
				CP_Settings_TextSize(50);
				for (int i = 0; i < 5; i++) {
					
					sprintf_s(print, 100, "%d", hand[i].mana);
					CP_Font_DrawText(print, 800 + (float)(i * 30), 100);
					

				}
				if (*turns % 3 == 0) {
					enemyAttack(player, 3);
				}
				else {
					enemyAttack(player, 1);
				}
				
				//after marcus done animation uncomment
				//player->defence = 0;
				*turns = *turns + 1;
				(void)pressed;
			}
			
		}		
		//pressed = 0;
	}
}
