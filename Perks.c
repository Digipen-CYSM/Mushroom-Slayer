#include <stdio.h>
#include <stdlib.h>
#include "cprocessing.h"
#include "Perks.h"
#include "Character.h"
#include "Enemy.h"
#include "Cards.h"
#include "GameLoad.h"
#include "GameOver.h"
#include "level1_1.h"

bool condition = 0, selected = 0;
int position = 0;
unsigned int perks[3] = { 0 };
unsigned int random_perks[3] = { 0 };
unsigned int selected_perk = 0;



CardType create_antitode_card(void)
{
	CardType cards;
	cards.type = 'p';
	cards.poison = 0;
	cards.imgSrc = "Assets/cards/antidote.png";
	cards.mana = 2;
	return cards;
}

CardType enhance_attack_card(void)
{
	CardType cards;
	cards.type = 'a';
	cards.ret = 2;
	cards.imgSrc = "Assets/cards/attack_e.png";
	cards.mana = 1;
	return cards;
}

CardType enhance_dmg_card(void)
{
	CardType cards;
	cards.type = 'e';
	cards.multiplier = 2;
	cards.imgSrc = "Assets/cards/power_up.png";
	cards.mana = 1;
	return cards;
}

void generate_perks(unsigned int type, Player* player, CardType* hand)
{
	switch(type)
	{
		case 1:
			//+1 Max Mana
			player->oMana += 1;
			break;
		case 2:
			//+2 Max Mana
			player->oMana += 2;
			break;
		case 3:
			//Revive once (add 1 life)
			player->life += 1;
			break;
		case 4:
			//player->handSize += 1;
			player->handSize += 1;
			break;
		case 5:
			//+5 heal
			player->health += 5;
			break;
		case 6:
			//+10 heal
			player->health += 10;
			break;
		case 7:
			//Antidote card
			player->deckSize += 1;
			addCardToDeck(hand, player->deckSize, create_antitode_card());
			break;
		case 8:
			//Enhance attack card
			player->deckSize += 1;
			addCardToDeck(hand, player->deckSize, enhance_attack_card());
			break;
		case 9:
			//x2 attack for every attack card
			player->deckSize += 1;
			addCardToDeck(hand, player->deckSize, enhance_dmg_card());
			break;
		default:
			break;
	}
}

unsigned int generate_perk_image(unsigned int type, float x)
{
	switch (type)
	{
		case 1:
			//+1 Max Mana
			CP_Image_Draw(CP_Image_Load("Assets/perks/1_max_mana.png"), x, 400, 300, 450, 255);
			break;
		case 2:
			//+2 Max Mana
			CP_Image_Draw(CP_Image_Load("Assets/perks/1_max_mana.png"), x, 400, 300, 450, 255);
			break;
		case 3:
			//Revive once (add 1 life)
			CP_Image_Draw(CP_Image_Load("Assets/perks/revive.png"), x, 400, 300, 450, 255);
			break;
		case 4:
			//+1 card in hand size
			CP_Image_Draw(CP_Image_Load("Assets/perks/extra_card.png"), x, 400, 300, 450, 255);
			break;
		case 5:
			//+5 heal
			CP_Image_Draw(CP_Image_Load("Assets/perks/heal_5.png"), x, 400, 300, 450, 255);
			break;
		case 6:
			//+10 heal
			CP_Image_Draw(CP_Image_Load("Assets/perks/heal_10.png"), x, 400, 300, 450, 255);
			break;
		case 7:
			//Antidote card
			CP_Image_Draw(CP_Image_Load("Assets/perks/add_antidote.png"), x, 400, 300, 450, 255);
			break;
		case 8:
			//Enhance attack card
			CP_Image_Draw(CP_Image_Load("Assets/perks/enhance_attack.png"), x, 400, 300, 450, 255);
			break;
		case 9:
			//x2 attack for every attack card
			CP_Image_Draw(CP_Image_Load("Assets/perks/x2_attack.png"), x, 400, 300, 450, 255);
			break;
		default:
			return 0;
	}
	return type;
}

void load_perks()
{
	if (perks_loading_count >= 1)
	{
		unsigned int random_no_1 = CP_Random_RangeInt(1, 9);
		unsigned int random_no_2 = CP_Random_RangeInt(1, 9);
		unsigned int random_no_3 = CP_Random_RangeInt(1, 9);
		generate_perk_image(random_no_1, 450);
		generate_perk_image(random_no_2, 850);
		generate_perk_image(random_no_3, 1250);
		perks_loading_count--;
	}

	if (perks_loading_count <= 0)
	{
		perks_count_bool = 0;
	}
}

void free_perks_images()
{

}

void clear_perks()
{

}

void selected_perks(Player* player, CardType* deck)
{
	const unsigned int level_1_perks[3] = {7, 8, 9};
	float x_position = 450;

	drawBg(0);
	drawConfrim();
	load_perks();	

	//fixed perk for tutorial
	if (perks_count_bool == 0 && perks_level_count == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			perks[i] = generate_perk_image(level_1_perks[i], x_position);
			x_position += 400;
		}
	}

	if (perks_count_bool == 1 && perks_level_count >= 1)
	{
		for (int i = 0; i < 3; i++)
		{
			random_perks[i] = CP_Random_RangeInt(1, 9);
		}
	}

	//random perk
	if (perks_count_bool == 0 && perks_level_count >= 1)
	{
		
		for (int i = 0; i < 3; i++)
		{
			perks[i] = generate_perk_image(random_perks[i], x_position);
			x_position += 400;
		}
	}

	float x_clickposition = 450;
	
	//detect which perk user select
	for (int i = 0; i < 3; i++)
	{
		if (CP_Input_GetMouseX() >= (x_clickposition - 150) + ( i * 350 ) && CP_Input_GetMouseX() <= (x_clickposition + 150) + (i * 350))
		{
			if (CP_Input_GetMouseY() >= 175 && CP_Input_GetMouseY() <= 625)
			{
				if (CP_Input_MouseClicked())
				{
					selected_perk = perks[i];
					position = i;
					condition = true;
				}
			}
		}
	}

	//Highlight selected perks
	if (condition == true)
	{
		CP_Image_Draw(CP_Image_Load("Assets/perks/select_perks.png"), x_clickposition + (position * 400), 400, 300, 450, 255);
		selected = true;
	}
	
	//Confirm button
	if (selected == true)
	{
		if (CP_Input_GetMouseX() >= 750 && CP_Input_GetMouseX() <= 950 && CP_Input_GetMouseY() >= 75 && CP_Input_GetMouseY() <= 125)
		{
			if (CP_Input_MouseClicked())
			{
				generate_perks(selected_perk, player, deck);

				if (perks_level_count == 0)
				{
					condition = false;
					CP_Engine_SetNextGameState(level1_1_Init, level1_1_Update, level1_1_Exit);
				}
				else
				{
					//next level
					CP_Engine_SetNextGameState(level1_1_Init, level1_1_Update, level1_1_Exit);
				}
			}
		}
	}
}

