#pragma once
#include "Character.h"
#include "Enemy.h"
#include <stdbool.h>

typedef struct CardType {
	char type;
	int ret;
	int multiplier;
	int mana;
	char *valSrc;
	char *baseSrc;
	char *manaSrc;
	char* imgSrc;
	bool poison;
} CardType;

CardType createAttackCard(void);
CardType createDefenceCard(void);
void loadDeckImg(CardType* deckp, int numDeck,int nCheck);
CardType* generateDeck(void);
CardType* drawCards(CardType* deck, int numCards, int fCheck);
void drawHandSrc(int* handCheck, int selectedCount);
void drawDeck(CardType* deck, int numDeck);
void attackCard(Enemy* enemy, int damage);
void defenceCard(int defence, Player* player);
void handuCollision(CardType* hand, Player* player, int* handCheckP);
void handsCollision(int selectedCount, int* handCheckP, Player* player, CardType* hand);
void addCardToDeck(CardType* deckp, int deckSize, CardType card);

CardType* deckPtr;
CardType* handPtr;