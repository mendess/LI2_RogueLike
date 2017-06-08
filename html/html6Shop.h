#ifndef __HTML6_H__
#define __HTML6_H__

#include "../shop.h"

#include "htmlMaster.h"

#define SHOP_SCREENS	{"ScreenShop.png","ScreenShop1.png","ScreenShop2.png","ScreenShop3.png","ScreenShop4.png","ScreenShop5.png"}

void imprime_shop_item(char *name, int item, int index);
void imprime_inv_slot_shop(char *name, int item,int i, int isDeletingItems);
void imprime_equipment_shop(char *name, INVT bag);
void imprime_price(int x, int y, int amount);
void imprime_shop_prices(int lootTable[],int gold);
void imprime_shop_messages(int shopFeedback);
void imprimeShop(ESTADO e);

#endif