#pragma once
#include "Character.h"
typedef struct CardType {
	char type;
	int ret;
	int mana;
	char *valSrc;
	char *baseSrc;
	char *manaSrc;
	char* imgSrc;
} CardType;

CardType createAttackCard(void);
CardType createDefenceCard(void);
void loadDeckImg(CardType* deckp, int numDeck);
CardType* generateDeck(void);
CardType* drawCards(CardType* deck, int numCards, int fCheck);
void drawHandSrc(int* handCheck, int selectedCount);
int attackCard(int health, int damage);
void defenceCard(int defence, Player* player);
