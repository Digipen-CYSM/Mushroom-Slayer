//---------------------------------------------------------
// file:	Perks.c
// author:	Yijian
// email:	yijian.zhuo@digipen.edu
//
// brief:	contains function for perks
//
// documentation link:
// https://inside.digipen.edu/main/GSDP:GAM100/CProcessing
//
// Copyright © 2020 DigiPen, All rights reserved.
//---------------------------------------------------------
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
unsigned int fixed_perks[3] = { 0 };
unsigned int random_perks[3] = { 0 };
unsigned int selected_perk = 0;
CP_Image perks_image[9];


//Create antitode card
CardType create_antitode_card(void)
{
	CardType cards;
	cards.type = 'p';
	cards.poison = false;
	cards.imgSrc = "Assets/cards/antidote.png";
	cards.mana = 2;
	return cards;
}

//Create enhance attack card
CardType enhance_attack_card(void)
{
	CardType cards;
	cards.type = 'E';
	cards.ret = 2;
	cards.imgSrc = "Assets/cards/attack_e.png";
	cards.mana = 1;
	return cards;
}

//Create enhance dmg card
CardType enhance_dmg_card(void)
{
	CardType cards;
	cards.type = 'e';
	cards.multiplier = 3;
	cards.imgSrc = "Assets/cards/power_up.png";
	cards.mana = 1;
	return cards;
}

//Generate the perks depends on what the player selected
void generate_perks(unsigned int type, Player* player, CardType* deck)
{
	switch(type)
	{
		case 1:
			//+1 Max Mana
			player->oMana += 1;
			player->mana += 1;
			break;
		case 2:
			//+2 Max Mana
			player->oMana += 2;
			player->mana += 2;
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
			addCardToDeck(deck, player->deckSize, create_antitode_card());
			break;
		case 8:
			//Enhance attack card
			for (int i = 0; i < 10; i++)
			{
				if (deck[i].type == 'a')
				{
					deck[i].ret = 2;
					deck[i].imgSrc = "Assets/cards/attack_e.png";
				}
			}
			break;
		case 9:
			//x2 attack for every attack card
			player->deckSize += 1;
			addCardToDeck(deck, player->deckSize, enhance_dmg_card());
			break;
		default:
			break;
	}
}

//Draw the image for perks
unsigned int generate_perk_image(unsigned int type, float x)
{
	switch (type)
	{
		case 1:
			//+1 Max Mana
			CP_Image_Draw(perks_image[0], x, 400, 300, 450, 255);
			break;
		case 2:
			//+2 Max Mana
			CP_Image_Draw(perks_image[1], x, 400, 300, 450, 255);
			break;
		case 3:
			//Revive once (add 1 life)
			CP_Image_Draw(perks_image[2], x, 400, 300, 450, 255);
			break;
		case 4:
			//+1 card in hand size
			CP_Image_Draw(perks_image[3], x, 400, 300, 450, 255);
			break;
		case 5:
			//+5 heal
			CP_Image_Draw(perks_image[4], x, 400, 300, 450, 255);
			break;
		case 6:
			//+10 heal
			CP_Image_Draw(perks_image[5], x, 400, 300, 450, 255);
			break;
		case 7:
			//Antidote card
			CP_Image_Draw(perks_image[6], x, 400, 300, 450, 255);
			break;
		case 8:
			//Enhance attack card
			CP_Image_Draw(perks_image[7], x, 400, 300, 450, 255);
			break;
		case 9:
			//x2 attack for every attack card
			CP_Image_Draw(perks_image[8], x, 400, 300, 450, 255);
			break;
		default:
			return 0;
	}
	return type;
}

//loading perks animation
void load_perks(void)
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

//load images for perks
void load_perks_images(void)
{
	perks_image[0] = CP_Image_Load("Assets/perks/1_max_mana.png");
	perks_image[1] = CP_Image_Load("Assets/perks/2_max_mana.png");
	perks_image[2] = CP_Image_Load("Assets/perks/revive.png");
	perks_image[3] = CP_Image_Load("Assets/perks/extra_card.png");
	perks_image[4] = CP_Image_Load("Assets/perks/heal_5.png");
	perks_image[5] = CP_Image_Load("Assets/perks/heal_10.png");
	perks_image[6] = CP_Image_Load("Assets/perks/add_antidote.png");
	perks_image[7] = CP_Image_Load("Assets/perks/enhance_attack.png");
	perks_image[8] = CP_Image_Load("Assets/perks/x3_attack.png");
}

//free perks when round ended
void free_perks_images(void)
{
	for (int i = 0; i < 9; ++i)
	{
		CP_Image_Free(&perks_image[i]);
	}
}

//clear perks when selected perks
void clear_perks(void)
{
	condition = 0;
	selected = 0;
}

//excute perks and be called by game function
void excute_perks(Player* player, CardType* deck)
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
			fixed_perks[i] = generate_perk_image(level_1_perks[i], x_position);
			x_position += 400;
		}
	}

	//generate random perks after tutorial rounds
	if (perks_count_bool == 1 && perks_level_count >= 1)
	{
		for (int i = 0; i < 3; i++)
		{
			random_perks[i] = CP_Random_RangeInt(1, 9);
		}
	}

	//generate image for random perk
	if (perks_count_bool == 0 && perks_level_count >= 1)
	{
		
		for (int i = 0; i < 3; i++)
		{
			fixed_perks[i] = generate_perk_image(random_perks[i], x_position);
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
					selected_perk = fixed_perks[i];
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
					CP_Engine_SetNextGameState(game_over_init, victory_update, game_over_exit);
				}
			}
		}
	}
}

