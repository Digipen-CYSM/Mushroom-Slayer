#pragma once

typedef struct CardType {
	char type;
	int ret;
	int mana;
} CardType;

CardType attackCard(void);
CardType defenceCard(void);
CardType healCard(void);