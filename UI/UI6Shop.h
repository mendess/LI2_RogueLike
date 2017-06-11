#ifndef __UI6_H__
#define __UI6_H__

/**
@file UI6Shop.h
Definição das funções para imprimir a interface da loja
*/
#include <stdio.h>

#include "../estrutura.h"
#include "../shop.h"
#include "UIMacros.h"

/** \brief Ecras da loja */
#define SHOP_SCREENS	{"ScreenShop.png","ScreenShop1.png","ScreenShop2.png","ScreenShop3.png","ScreenShop4.png","ScreenShop5.png"}

/**
\brief Imprime um item da loja
@param name Nome do jogador
@param item Item a imprimir
@param index Indice onde imprimir (0-3)
*/
void imprime_shop_item(char *name, int item, int index);
/**
\brief Imprime um item da inventario
@param name Nome do jogador
@param item Item a imprimir
@param i Indice onde imprimir (0-5)
@param isDeletingItems Se o jogador está a apagar items
*/
void imprime_inv_slot_shop(char *name, int item, int i, int isDeletingItems);
/**
\brief Imprime os items que o jogador tem equipadas
@param weapon Arma que o jogador tem equipada
@param armour Armadura que o jogador tem equipada
*/
void imprime_equipment_shop(int weapon, int armour);
/**
\brief Imprime um preço
@param x Coordenada x do preço
@param y Coordenada y do preço
@param amount Quantidade de dinheiro
*/
void imprime_price(int x, int y, int amount);
/**
\brief Imprime os preços dos items à venda
@param lootTable Lista de items para venda
*/
void imprime_shop_prices(int lootTable[]);
/**
\brief Função mestra que imprime a interface da loja
@param e Estado do Jogo
*/
void imprimeShop(ESTADO e);

#endif