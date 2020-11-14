#pragma once

typedef struct CardType {
	char type;
	int ret;
	int mana;
	char *valSrc;
	char *baseSrc;
	char *manaSrc;
	char *imgSrc;
} CardType;

CardType attackCard(void);
CardType defenceCard(void);
void loadDeckImg(CardType* deckp, int numDeck);
CardType* generateDeck(void);
CardType* drawCards(CardType* deck, int numCards, int numDeck);
void drawHandSrc(int numHand);