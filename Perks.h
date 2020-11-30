#pragma once
#include "cprocessing.h"
#include "Character.h"
#include "Cards.h"

void selected_perks(Player* player, CardType* hand);
CardType enhance_attack_card(void);
CardType enhance_dmg_card(void);
CardType create_antitode_card(void);
unsigned int generate_perk_image(unsigned int type, float x);
void generate_perks(unsigned int type, Player* player, CardType* hand);
