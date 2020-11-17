#include "cprocessing.h"
#include "Perks.h"
#include "Character.h"
#include "Enemy.h"
#include "Cards.h"

CardType create_antitode_card(void)
{
	CardType cards;
	cards.type = 'p';
	cards.abnormal_status = 0;
	cards.imgSrc = "Assets/cards/attack1.png";
	cards.mana = 2;
	return cards;
}

CardType enhance_attack_card(void)
{
	CardType cards;
	cards.type = 'a';
	cards.ret = 2;
	cards.imgSrc = "Assets/cards/attack1.png";
	cards.mana = 1;
	return cards;
}

CardType enhance_dmg_card(void)
{
	CardType cards;
	cards.type = 'd';
	cards.multiplier = 2;
	cards.imgSrc = "Assets/cards/attack1.png";
	cards.mana = 1;
	return cards;
}

void healing(void)
{

}

void max_mana(void) 
{

}

void add_life(void)
{

}

void max_card(void)
{

}

void run_perk(void)
{

}

void random_generated_perks(void)
{

}

void selected_perks(void)
{

}

