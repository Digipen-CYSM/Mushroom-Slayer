#pragma once

typedef struct CardType {
	char type;
	int ret;
	int mana;
	char *valSrc;
	char *baseSrc;
	char *manaSrc;
} CardType;

CardType attackCard(void);
CardType defenceCard(void);
CardType healCard(void);