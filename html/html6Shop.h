#ifndef __HTML6_H__
#define __HTML6_H__

#include "../shop.h"

#include "htmlMaster.h"

void imprime_shop_item(char *name, char item, int index);
void imprime_inv_slot_shop(char *name, char item,int i);
void imprime_equipment_shop(char *name, INVT bag);
void imprime_price(int x, int y, int amount);
void imprime_shop_prices(char lootTable[],int gold);
void imprime_shop_messages(char shopFeedback);
void imprimeShop(ESTADO e);

#endif