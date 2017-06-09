#ifndef __SHOP_H__
#define __SHOP_H__

/**
@file shop.h
Definição da lógica da loja
*/

#include <limits.h>

#include "estrutura.h"

#define POTION_BUY_PRICE	20
#define SCROLL_BUY_PRICE	30
#define SWORD_BUY_PRICE		50
#define ARMOUR_BUY_PRICE	50

#define POTION_SELL_PRICE	5
#define SCROLL_SELL_PRICE	7
#define SWORD_SELL_PRICE	12
#define ARMOUR_SELL_PRICE	12

/**
\brief Devolve o preco de um dado item
@param item Item a ser avaliado
@returns Preço do item
*/
int getItemBuyPrice(int item);
/**
\brief Verifica se o jogador tem espaço que chegue para guardar o item que quer comprar
@param inv Inventario do jogador
@returns 1 se o jogador tiver espaço no inventário 0 se o jogador não tiver
*/
int hasEnoughSpace(int inv[]);
/**
\brief Coloca um item no inventario
@param inv Inventario do jogador
@param item Item que vai ser adicionado
*/
void putItemInv(int inv[],int item);
/**
\brief Tenta comprar um item e retorna se foi possivel
@param action Acao que o jogador fez (item selecionado)
@param lootTable Lista de item à venda
@param *bag Apontador para o inventario do jogador
@returns 0 se a compra foi bem sucedida, 1 se o jogador não tem dinheiro que chegue e 2 se o jogador não tem espaço no inventario
*/
int buyItem(int action,int lootTable[],INVT *bag);

#endif