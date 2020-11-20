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
	bool abnormal_status;
} CardType;

CardType createAttackCard(void);
CardType createDefenceCard(void);
void loadDeckImg(CardType* deckp, int numDeck);
CardType* generateDeck(void);
CardType* drawCards(CardType* deck, int numCards, int fCheck);
void drawHandSrc(int* handCheck, int selectedCount);
void attackCard(Enemy* enemy, int damage);
void defenceCard(int defence, Player* player);
void handuCollision(CardType* hand, Player* player, int* handCheckP);
void handsCollision(int selectedCount, int* handCheckP, Player* player, CardType* hand);
