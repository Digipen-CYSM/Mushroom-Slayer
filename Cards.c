#include "cprocessing.h"
#include <stdio.h>
#include <stdlib.h>
#include "Cards.h"

CardType* deckPtr;
CardType* handPtr;
int* handRng;
int rCheck, rng, deckSize,handSize;
CP_Image* deckSrc;


CardType attackCard(void) {
	CardType cards;
	cards.type = 'a';
	cards.ret = 3;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 2;
	cards.baseSrc = "Assets/cards/attackBase.png";
	cards.valSrc = "Assets/cards/val3.png";
	cards.manaSrc = "Assets/cards/mana2.png";
	return cards;
}

CardType defenceCard(void) {
	CardType cards;
	cards.type = 'd';
	cards.ret = 2;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 1;
	cards.baseSrc = "Assets/cards/defenceBase.png";
	cards.valSrc = "Assets/cards/val2.png";
	cards.manaSrc = "Assets/cards/mana1.png";
	return cards;
}


//generate the deck and create pointer pointing to the deck
CardType* generateDeck(void) {
	deckSize = 10;
	deckPtr = (CardType*)malloc(deckSize * sizeof(CardType));
	for (int i = 0; i < deckSize; i++) {
		if (i < 5) {
			deckPtr[i] = attackCard();
		}
		else {
			deckPtr[i] = defenceCard();
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

