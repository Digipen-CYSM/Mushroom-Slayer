#include "cprocessing.h"
#include <stdio.h>
#include "Cards.h"
CardType hand[50];
CardType* deckPtr;
CardType* handPtr;
CardType deck[50];
int handRng[50], rCheck = 1, oneToTen;
CP_Image deckSrc[50];


CardType attackCard(void) {
	CardType cards;
	cards.type = 'a';
	cards.ret = 3;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 2;
	cards.baseSrc = "Assets/cards/attackBase.png";
	cards.valSrc = "Assets/cards/val3.png";
	cards.manaSrc = "Assets/cards/mana2.png";
	cards.imgSrc = "Assets/cards/attackBase.png";
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
	cards.imgSrc = "Assets/cards/defenceBase.png";
	return cards;
}



CardType* generateDeck(void) {
	//generate cards into deck
	for (int i = 0; i < 10; i++) {
		if (i < 5) {
			deck[i] = attackCard();
		}
		else {
			deck[i] = defenceCard();
		}
	}
	deckPtr = deck;
	return deckPtr;
}

CardType* drawCards(CardType* deckp,int numCards,int numDeck) {	
	for (int i = 0; i < numCards; i++) {
		while (rCheck == 1) {
			rCheck = 0;
			oneToTen = CP_Random_RangeInt(0, numDeck);
			for (int j = 0; j < numCards; j++) {
				if (handRng[j] == oneToTen && i != 0) {
					rCheck = 1;
				}
			}
		}
		handRng[i] = oneToTen;
		hand[i] = deckp[oneToTen];
	}

	return handPtr;
}

void loadDeckImg(CardType* deckp,int numDeck) {
	for (int i=0; i < numDeck; i++) {
		deckSrc[i] = CP_Image_Load(deckp[i].imgSrc);
	}
}

void drawHandSrc(int numHand) {
	float cardWidth = 350;
	for (int i = 0; i < numHand; i++) {
		//take note need to specify what i is
		CP_Image_Draw(deckSrc[i], cardWidth, 750, 150, 230, 255);
		cardWidth += 135;
	}
}