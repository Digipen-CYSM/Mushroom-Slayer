//---------------------------------------------------------
// file:	game.c
// author:	Chia Shi Bo
//			Zhuo Yijian
//			Marcus Chong
//			Ho Yan Ying, Camie
// email:	
//			yijian.zhuo@digipen.edu
//			youlongmarcus.c@digipen.edu
//			y.ho@digipen.edu
//
// brief:	gameplay for tutorial round
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cprocessing.h"
#include "Cards.h"
#include "Enemy.h"
#include "Character.h"

int* handRng;
int rCheck, deckSize;
unsigned int random_no;
CP_Image* deckSrc;

//Done By: Marcus
void createAttackCard(CardType* cards) {
	cards->type = 'a';
	cards->ret = 1;
	cards->imgSrc = "Assets/cards/attack1.png";
	cards->mana = 1;
}

//Done By: Marcus
void createDefenceCard(CardType* cards) {
	cards->type = 'd';
	cards->ret = 2;
	cards->mana = 1;
	cards->imgSrc = "Assets/cards/defence1.png";
}

//Done By: Marcus
void attackCard(Enemy* enemy,int damage) {
	enemy->health -= damage;
}

//Done By: Marcus
void defenceCard(int defence, Player* player) {
	player->defence += defence;
}

//Done By: Chia Shi Bo
//generate the deck and create pointer pointing to the deck
CardType* generateDeck(CardType* deckPtr) {
	deckSize = 10;
	deckPtr = (CardType*)malloc(deckSize * sizeof(CardType));
	for (int i = 0; i < deckSize; i++) {
		if (i < 5) {
			createAttackCard(&deckPtr[i]);
		}
		else {
			createDefenceCard(&deckPtr[i]);
		}
	}
	return deckPtr;
}

//Done By: Camie
//draw a new set of cards and put it into handRng and handPtr
void drawCards(CardType* deckp,int numCards,int fCheck,CardType* handPtr) {
	int j1;
	
	free(handRng);
	
	handRng = (int*)malloc(numCards * sizeof(int));

	for (int i = 0; i < numCards; i++) {
		if (i == 0) {
			random_no = CP_Random_RangeInt(0, playerPtr->deckSize - 1);
			handRng[i] = random_no;
			handPtr[i] = deckp[random_no];

		}
		else {
			random_no = CP_Random_RangeInt(0, playerPtr->deckSize - 1);
			j1 = 0;
			while (j1 < i) {
				if ((int)random_no == handRng[j1]) {
					random_no = CP_Random_RangeInt(0, playerPtr->deckSize - 1);
				}
				else {
					j1++;
				}
			}
			handRng[i] = random_no;
			handPtr[i] = deckp[random_no];
		}
	}
	for (int i = 0; i < 5; i++) {
		fCheck = handPtr[i].mana;
	}
}

//Done by: Camie
void loadDeckImg(CardType* deckp,int numDeck, int nCheck) {
	if (nCheck == 1) {
		deckSrc = (CP_Image*)malloc(numDeck * sizeof(CP_Image));
	}
	else {
		free(deckSrc);
		deckSrc = (CP_Image*)malloc(numDeck * sizeof(CP_Image));
	}
	for (int i=0; i < numDeck; i++) {
		deckSrc[i] = CP_Image_Load(deckp[i].imgSrc);
	}
}

//Done by: Zhuo Yijian
void addCardToDeck(CardType* deckp, int ndeckSize, CardType card) {
	realloc(deckp, ndeckSize * sizeof(CardType));
	deckp[ndeckSize-1] = card;
}

//Done by: Camie
void drawHandSrc(int* handCheck,int selectedCount,int handSize) {
	float cardWidth = 495, cardWidthS = 350;
	for (int i = 0; i < handSize; i++) {		
		if (handCheck[i] == 0) {
			CP_Image_Draw(deckSrc[handRng[i]], cardWidth, 750, 150, 230, 255);
		}
		else {
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
			CP_Image_Draw(deckSrc[handRng[i]], cardWidthS, 300, 200, 300, 255);
		}
		cardWidth += 135;
	}
}

//Done by: Camie
void drawHandAnimation(CardType* handPtr,float time,int handSize) {
	if (time < 6000) {
		CP_Image_Draw(deckSrc[handRng[0]], (float)(495 * (double)time / 6000), 750, 150, 230, 255);
	}
	
	if (time > 6000 && time <12000) {
		CP_Image_Draw(deckSrc[handRng[1]], (float)(630 * ((double)time-6000) / 6000), 750, 150, 230, 255);
	}
	if (time > 12000 && time < 18000) {
		CP_Image_Draw(deckSrc[handRng[2]], (float)(765 * ((double)time - 12000) / 7000), 750, 150, 230, 255);
	}
	if (time > 18000 && time < 24000) {
		CP_Image_Draw(deckSrc[handRng[3]], (float)(900 * ((double)time- 18000)/ 8000), 750, 150, 230, 255);
	}
	if (time > 24000 && time < 30000) {
		CP_Image_Draw(deckSrc[handRng[4]], (float)(1035 * ((double)time - 24000) / 8000), 750, 150, 230, 255);
	}
	if (time > 6000) {
		CP_Image_Draw(deckSrc[handRng[0]], 495, 750, 150, 230, 255);
	}
	if (time > 12000) {
		CP_Image_Draw(deckSrc[handRng[1]], 630, 750, 150, 230, 255);
	}
	if (time > 18000) {
		CP_Image_Draw(deckSrc[handRng[2]], 765, 750, 150, 230, 255);
	}
	if (time > 24000) {
		CP_Image_Draw(deckSrc[handRng[3]], 900, 750, 150, 230, 255);
	}
	if (time > 30000) {
		CP_Image_Draw(deckSrc[handRng[4]], 1035, 750, 150, 230, 255);
	}
}

//Done by: Chia Shi bo
void drawDeck(CardType* deck, int numDeck) {
	float cardWidth = 100;
	for (int i = 0; i < numDeck; i++) {
		CP_Image_Draw(deckSrc[i], cardWidth, 400, 100, 170, 255);
		cardWidth += 60;
	}
}

//Done by: Chia Shi Bo
void handuCollision(CardType* hand,Player* player,int* handCheckP) {
	float cardWidth = 420;	
	for (int i = 0; i < 5; i++) {
		if (CP_Input_GetMouseX() >= cardWidth && CP_Input_GetMouseX() <= cardWidth + 135)
		{
			if (CP_Input_GetMouseY() >= 635 && CP_Input_GetMouseY() <= 865)
			{
				if (CP_Input_MouseClicked())
				{
					if (hand[i].mana <= player->mana) {
						if (handCheckP[i] == 0) {
							handCheckP[i] = 1;
							player->mana -= hand[i].mana;
						}
					}
				}
			}
		}
		cardWidth += 135;
	}
}

//Done by: Chia Shi bo
void handsCollision(int selectedCount,int* handCheckP,Player* player,CardType* hand) {
	float cardWidthS = 350;
	int nCheck;
	if (selectedCount > 0) {
		for (int i = 0; i < selectedCount; i++) {
			if (CP_Input_GetMouseX() >= 1000 / (float)(selectedCount + 1) + cardWidthS - 100 && CP_Input_GetMouseX() <= 1000 / (float)(selectedCount + 1) + cardWidthS + 100) {
				if (CP_Input_GetMouseY() >= 150 && CP_Input_GetMouseY() <= 450) {
					if (CP_Input_MouseClicked()) {
						nCheck = 0;
						for (int j = 0; j < 5; j++) {
							if (handCheckP[j] == 1 && nCheck == i) {
								player->mana += hand[j].mana;
								handCheckP[j] = 0;
								break;
							}
							if (handCheckP[j] == 1) {
								nCheck += 1;
							}
						}
						selectedCount -= 1;
					}
				}
			}
			cardWidthS = 1000 / (float)(selectedCount + 1) + cardWidthS;
		}
	}
}

