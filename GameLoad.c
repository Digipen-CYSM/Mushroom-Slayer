//---------------------------------------------------------
// file:	level1_1.c
// author:	Chia Shi Bo
//			Zhuo Yijian
//			Marcus Chong
//			Ho Yan Ying, Camie
// email:	
//			yijian.zhuo@digipen.edu
//			youlongmarcus.c@digipen.edu
//			y.ho@digipen.edu
//
// brief:	functions for animation and gameplay
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include "cprocessing.h"
#include <string.h>
#include <stdio.h>
#include "GameLoad.h"
#include "Cards.h"
#include "Character.h"
#include "Enemy.h"
#include "Perks.h"

CP_Image confirmButton, backGround[10], enemyImg[10], healthImg, playerImg, poison_effect[2];
int round_count = 0;

void loadImg(int stage) {
	//load confirm button image
	confirmButton = CP_Image_Load("Assets/confirmButton1.png");
	//load background img
	if (stage == 0) {
		backGround[0] = CP_Image_Load("Assets/dojo/dojo.png");
		enemyImg[0] = CP_Image_Load("Assets/enemy/MsDummy/msdummy.png");
	}
	else if (stage == 1) {
		backGround[0] = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
		backGround[1] = CP_Image_Load("Assets/BG/Village BG/Village BG2.png");
		backGround[2] = CP_Image_Load("Assets/BG/Village BG/Village BG3.png");
		backGround[3] = CP_Image_Load("Assets/BG/Village BG/Village BG4.png");
		enemyImg[0] = CP_Image_Load("Assets/enemy/ms1.png");
		enemyImg[1] = CP_Image_Load("Assets/enemy/ms2.png");
		enemyImg[2] = CP_Image_Load("Assets/enemy/ms3.png");
		enemyImg[3] = CP_Image_Load("Assets/enemy/ms4.png");
	}
	else if (stage == 2) {
		backGround[0] = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
		backGround[1] = CP_Image_Load("Assets/BG/Village BG/Village BG2.png");
		backGround[2] = CP_Image_Load("Assets/BG/Village BG/Village BG3.png");
		backGround[3] = CP_Image_Load("Assets/BG/Village BG/Village BG4.png");
		enemyImg[0] = CP_Image_Load("Assets/enemy/MsWizard/mswizard1.png");
		enemyImg[1] = CP_Image_Load("Assets/enemy/MsWizard/mswizard2.png");
		enemyImg[2] = CP_Image_Load("Assets/enemy/MsWizard/mswizard3.png");
		enemyImg[3] = CP_Image_Load("Assets/enemy/MsWizard/mswizard4.png");
	}
	else if (stage == 3) {
		backGround[0] = CP_Image_Load("Assets/BG/Village BG/Village BG1.png");
		backGround[1] = CP_Image_Load("Assets/BG/Village BG/Village BG2.png");
		backGround[2] = CP_Image_Load("Assets/BG/Village BG/Village BG3.png");
		backGround[3] = CP_Image_Load("Assets/BG/Village BG/Village BG4.png");
		enemyImg[0] = CP_Image_Load("Assets/enemy/MsBoss/msboss1.png");
		enemyImg[1] = CP_Image_Load("Assets/enemy/MsBoss/msboss2.png");
		enemyImg[2] = CP_Image_Load("Assets/enemy/MsBoss/msboss3.png");
		enemyImg[3] = CP_Image_Load("Assets/enemy/MsBoss/msboss4.png");
	}

	playerImg = CP_Image_Load("Assets/character/Character.png");
	poison_effect[0] = CP_Image_Load("Assets/effects/poison/poison1.png");
	poison_effect[1] = CP_Image_Load("Assets/effects/poison/poison2.png");
}

void freeImg(int stage) {
	CP_Image_Free(&confirmButton);
	if (stage == 0) {
		CP_Image_Free(&backGround[0]);
		CP_Image_Free(&enemyImg[0]);
	}
	else{
		for (int i = 0; i < 4; i++) {
			CP_Image_Free(&backGround[i]);
			CP_Image_Free(&enemyImg[i]);
		}
	}
	CP_Image_Free(&playerImg);
	CP_Image_Free(&poison_effect[0]);
	CP_Image_Free(&poison_effect[1]);
}

void draw_poison_effect()
{
	if(frame_count <= 30)
	{
		CP_Image_Draw(poison_effect[0], 380, 450, 300, 400, 255);
	}
	else if(frame_count > 30 && frame_count <= 60)
	{
		CP_Image_Draw(poison_effect[1], 380, 450, 300, 400, 255);
	}
	else
	{
		frame_count = 0;
	}
}

void drawBg(int frame) {
	CP_Image_Draw(backGround[frame], 850, 600, (float)CP_System_GetWindowWidth(), (float)CP_System_GetWindowHeight() + 300, 255);
	//enemy image
	CP_Image_Draw(enemyImg[frame], 1300, 470, 250, 350, 255);
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
				int damage = 0, defence = 0, multiplier = 1;
				for (int i = 0; i < handSize; i++) {
					if (handCheck[i] == 1) {
						if (hand[i].type == 'a') {
							damage += hand[i].ret;
						}
						else if (hand[i].type == 'd') {
							defence += hand[i].ret;							
						}
						else if (hand[i].type == 'e')
						{
							multiplier = hand[i].multiplier;
						}
						else if (hand[i].type == 'p')
						{
							poison = hand[i].poison;
						}
						else
						{
							handCheck[i] = 0;
							break;
						}
						handCheck[i] = 0;
					}
				}
				damage = damage * multiplier;
				if (perks_level_count >= 1)
				{
					if (poison == true)
					{
						playerPtr->health -= 1;
					}
					else if (poison == false)
					{
						(round_count)++;
					}

					if ((round_count) % 3 == 0 && (round_count) != 0)
					{
						poison = true;
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

				//player->defence = 0;
				*turns = *turns + 1;
				(void)pressed;
			}
			
		}		
		//pressed = 0;
	}
}
