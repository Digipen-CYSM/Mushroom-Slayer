#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include "Cards.h"
#include "Enemy.h"
#include "Character.h"
#include "game.h"

CardType* deckPtr;
CardType* handPtr;
int* handRng;
int rCheck, rng, deckSize,handSize;
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

int attackCard(int health,int damage) {
	health -= damage;
	return health;
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
	
	for (int i = 0; i < numCards; i++) {
		rCheck = 1;
		while (rCheck == 1) {
			rCheck = 0;
			rng = CP_Random_RangeInt(0, deckSize-1);
			for (int j = 0; j < numCards; j++) {
				if (handRng[j] == rng && i != 0) {
					rCheck = 1;
				}
			}
		}
		handRng[i] = rng;
		handPtr[i] = deckp[rng];
	}
	return handPtr;
}

void loadDeckImg(CardType* deckp,int numDeck) {
	deckSrc = (CP_Image*)malloc(numDeck * sizeof(CP_Image));
	for (int i=0; i < numDeck; i++) {
		deckSrc[i] = CP_Image_Load(deckp[i].imgSrc);
	}
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

