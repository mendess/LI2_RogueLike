#ifndef __SHOP_H__
#define __SHOP_H__

#include <limits.h>

#include "jogo.h"

#define POTION_BUY_PRICE	20
#define SCROLL_BUY_PRICE	30
#define SWORD_BUY_PRICE		50
#define ARMOUR_BUY_PRICE	50

#define POTION_SELL_PRICE	5
#define SCROLL_SELL_PRICE	7
#define SWORD_SELL_PRICE	12
#define ARMOUR_SELL_PRICE	12

int getItemBuyPrice(char item);
int hasEnoughSpace(char inv[]);
void putItemInv(char inv[],char item);
char buyItem(char action,char lootTable[],INVT *bag);
int getItemSellPrice(char item);
void sellItem_Bag(char action, INVT *bag);
void sellEquipment(char action, INVT *bag);
ESTADO shop(ESTADO e);
#endif