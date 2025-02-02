#pragma once
#include "cprocessing.h"
#include "Character.h"
#include "Cards.h"

int perks_loading_count, perks_level_count;
bool perks_count_bool;

void excute_perks(Player* player, CardType* hand);
void load_perks_images(void);
void free_perks_images(void);
CardType enhance_attack_card(void);
CardType enhance_dmg_card(void);
CardType create_antitode_card(void);
unsigned int generate_perk_image(unsigned int type, float x);
void clear_perks(void);
