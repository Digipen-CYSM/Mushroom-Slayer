#include "cprocessing.h"
#include <stdio.h>
#include "Cards.h"
CardType attackCard(void) {
	CardType cards;
	cards.type = 'a';
	cards.ret = 3;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 2;
	return cards;
}

CardType defenceCard(void) {
	CardType cards;
	cards.type = 'd';
	cards.ret = 2;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 1;
	return cards;
}

CardType healCard(void) {
	CardType cards;
	cards.type = 'd';
	cards.ret = 3;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 1;
	return cards;
} 

