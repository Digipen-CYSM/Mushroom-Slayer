#pragma once
#include "Character.h"
#include "Enemy.h"
#include <stdbool.h>

typedef struct CardType {
	char type;
	int ret;
	int multiplier;
	int mana;
	const char* imgSrc;
	bool poison;
} CardType;

void createAttackCard(CardType* cards);
void createDefenceCard(CardType* cards);
void loadDeckImg(CardType* deckp, int numDeck,int nCheck);
CardType* generateDeck(CardType* deckPtr);
void drawCards(CardType* deck, int numCards, int fCheck, CardType* handPtr);
void drawHandSrc(int* handCheck, int selectedCount,int handSize);
void drawDeck(CardType* deck, int numDeck);
void attackCard(Enemy* enemy, int damage);
void defenceCard(int defence, Player* player);
void handuCollision(CardType* hand, Player* player, int* handCheckP);
void handsCollision(int selectedCount, int* handCheckP, Player* player, CardType* hand);
void addCardToDeck(CardType* deckp, int deckSize, CardType card);
void drawHandAnimation(CardType* handPtr, int frame,int handSize);
