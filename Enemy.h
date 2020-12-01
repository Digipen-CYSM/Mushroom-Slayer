#pragma once

typedef struct Enemy {
	int health;
	int mana;
} Enemy;

Enemy mushRoomT(void);
Enemy mushRoom1(void);
void hpLoadE(void);
void drawHealthSrcE(Enemy enemy);
void enemyAttack(Player* player, int damage);