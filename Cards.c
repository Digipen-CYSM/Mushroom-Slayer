#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include "Cards.h"
#include "Enemy.h"
#include "Character.h"

int* handRng;
int rCheck, deckSize,handSize;
unsigned int rng;
CP_Image* deckSrc;


CardType createAttackCard(void) {//parameter for value and mana
	CardType cards;
	cards.type = 'a';
	cards.ret = 1;
	cards.imgSrc = "Assets/cards/attack1.png";
	cards.mana = 1;
	return cards;
}

CardType createDefenceCard(void) {//parameter for value and mana
	CardType cards;
	cards.type = 'd';
	cards.ret = 2;
	cards.mana = 1;
	cards.imgSrc = "Assets/cards/defence1.png";
	return cards;
}

void attackCard(Enemy* enemy,int damage) {
	enemy->health -= damage;
}

void defenceCard(int defence, Player* player) {
	player->defence += defence;
	/*return player->defence;*/
}

//generate the deck and create pointer pointing to the deck
CardType* generateDeck(void) {
	deckSize = 10;
	deckPtr = (CardType*)malloc(deckSize * sizeof(CardType));
	for (int i = 0; i < deckSize; i++) {
		if (i < 5) {
			deckPtr[i] = createAttackCard();
		}
		else {
			deckPtr[i] = createDefenceCard();
		}
	}
	return deckPtr;
}

//draw a new set of cards and put it into handRng and handPtr
CardType* drawCards(CardType* deckp,int numCards,int fCheck) {
	handSize = numCards;
	if (fCheck == 1) {
		handPtr = (CardType*)malloc(numCards * sizeof(CardType));
		handRng = (int*)malloc(numCards * sizeof(int));
	}
	else if (fCheck == 2) {
		realloc(handPtr, numCards * sizeof(CardType));
		realloc(handRng, numCards * sizeof(int));
		
	}
	
	for (int i = 0; i < numCards; i++) {
		rCheck = 1;
		while (rCheck == 1) {
			rCheck = 0;
			rng = CP_Random_RangeInt(0, playerPtr->deckSize-1);
			for (int j = 0; j < numCards; j++) {
				if (handRng[j] == (int)rng && i != 0 && rng <= 0) {
					rCheck = 1;
				}
			}
		}
		handRng[i] = rng;
		handPtr[i] = deckp[rng];
	}
	return handPtr;
}

void loadDeckImg(CardType* deckp,int numDeck, int nCheck) {
	if (nCheck == 1) {
		deckSrc = (CP_Image*)malloc(numDeck * sizeof(CP_Image));
	}
	else {
		realloc(deckSrc, numDeck);
	}
	for (int i=0; i < numDeck; i++) {
		deckSrc[i] = CP_Image_Load(deckp[i].imgSrc);
	}
}

void addCardToDeck(CardType* deckp, int ndeckSize, CardType card) {
	realloc(deckp, ndeckSize * sizeof(CardType));
	deckp[ndeckSize-1] = card;
	//loadDeckImg(deckp, ndeckSize);
	//return deckB;
}

void drawHandSrc(int* handCheck,int selectedCount) {
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

