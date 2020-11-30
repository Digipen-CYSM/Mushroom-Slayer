#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include "Cards.h"
#include "Enemy.h"
#include "Character.h"
#include <math.h>

int* handRng;
int rCheck, deckSize;
unsigned int random_no;
CP_Image* deckSrc;

void createAttackCard(CardType* cards) {//parameter for value and mana
	cards->type = 'a';
	cards->ret = 1;
	cards->imgSrc = "Assets/cards/attack1.png";
	cards->mana = 1;
}

void createDefenceCard(CardType* cards) {//parameter for value and mana
	cards->type = 'd';
	cards->ret = 2;
	cards->mana = 1;
	cards->imgSrc = "Assets/cards/defence1.png";
}

void attackCard(Enemy* enemy,int damage) {
	enemy->health -= damage;
}

void defenceCard(int defence, Player* player) {
	player->defence += defence;
	/*return player->defence;*/
}

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
//draw a new set of cards and put it into handRng and handPtr
void drawCards(CardType* deckp,int numCards,int fCheck,CardType* handPtr) {
	//handSize = numCards;
	int j1;
	
	free(handRng);
	//free(handPtr);
	
	handRng = (int*)malloc(numCards * sizeof(int));
	//*handPtr = (CardType*)malloc(numCards * sizeof(CardType));

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

void addCardToDeck(CardType* deckp, int ndeckSize, CardType card) {
	realloc(deckp, ndeckSize * sizeof(CardType));
	deckp[ndeckSize-1] = card;
}

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

void drawHandAnimation(CardType* handPtr,float time,int handSize) {
	//for (int i = 0; i < handSize; i++) {
	//double cardWidth = (495+i*135) * (double)time / 4000;
	//	if (time < 4000 + i * 3000) {
	//		CP_Image_Draw(deckSrc[handRng[i]], (float)cardWidth, 750, 150, 230, 255);
	//	}
	//}
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
	//CP_Image_Draw(deckSrc[handRng[1]], (630 * (double)time / 3400), 750, 150, 230, 255);
	//CP_Image_Draw(deckSrc[handRng[2]], (765 * (double)time / 2800), 750, 150, 230, 255);
	//CP_Image_Draw(deckSrc[handRng[3]], (900 * (double)time / 2200), 750, 150, 230, 255);
	//CP_Image_Draw(deckSrc[handRng[4]], (1035 * (double)time / 1600), 750, 150, 230, 255);
	
}

void drawDeck(CardType* deck, int numDeck) {
	float cardWidth = 100;
	for (int i = 0; i < numDeck; i++) {
		CP_Image_Draw(deckSrc[i], cardWidth, 400, 100, 170, 255);
		cardWidth += 60;
	}
}

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

void handsCollision(int selectedCount,int* handCheckP,Player* player,CardType* hand) {
	float cardWidthS = 350;
	int nCheck;
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

