#include "cprocessing.h"
#include <stdio.h>
#include "Cards.h"
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

CardType healCard(void) {
	CardType cards;
	cards.type = 'h';
	cards.ret = 3;
	//cards.ret = CP_Random_RangeInt(1, 3)
	cards.mana = 1;
	cards.baseSrc = "Assets/cards/healBase.png";
	cards.valSrc = "Assets/cards/val3.png";
	cards.manaSrc = "Assets/cards/mana1.png";
	return cards;
} 

