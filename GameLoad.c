#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include "GameLoad.h"
#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
#include "Perks.h"
CP_Image confirmButton, backGround[10], enemyImg, healthImg, playerImg;


void loadImg(int stage) {
	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
	//load background img
	if (stage == 0) {
		backGround[0] = CP_Image_Load("Assets/dojo/dojo.png");
	}
	else if (stage == 1) {
		backGround[0] = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
		backGround[1] = CP_Image_Load("Assets/BG/Village BG/Village BG2.png");
		backGround[2] = CP_Image_Load("Assets/BG/Village BG/Village BG3.png");
		backGround[3] = CP_Image_Load("Assets/BG/Village BG/Village BG4.png");
	}
	
	//load enemy img
	enemyImg = CP_Image_Load("Assets/enemy/ms1.png");

	playerImg = CP_Image_Load("Assets/character/Character.png");
}

void freeImg(int stage) {
	CP_Image_Free(confirmButton);
	if (stage == 0) {
		CP_Image_Free(backGround[0]);
	}
	else if (stage == 1) {
		for (int i = 0; i < 4; i++) {
			CP_Image_Free(backGround[i]);
		}
	}

	//load enemy img
	CP_Image_Free(enemyImg);

	CP_Image_Free(playerImg);

}

void drawBg(int frame) {
	CP_Image_Draw(backGround[frame], 850, 600, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() + 300, 255);
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
