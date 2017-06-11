#ifndef __UI_5_TIPS_H__
#define __UI_5_TIPS_H__

/**
@file UI5PlayingTips.h
Definição das funções que imprimem as ajudas durante o jogo
*/

#include "UI5Playing.h"
#include "../items.h"
#include "../genMonsters.h"

/** \brief Descrição do lobo */
#define WOLF_DESC	"Wolfs are fast and\ncan attack diagonaly\nbut don't deal\nmuch damage.\nThey are known\nto attack in groups!"
/** \brief Descrição do morcego */
#define BAT_DESC	"Bats can fly over\nwalls and attack\ndiagonaly but they can't \ntake many hits or deal\nmuch damage."
/** \brief Descrição do ogre */
#define OGRE_DESC	"Ogres are a sturdy foe!\nAlthough they can't\nattack diagonaly,\ntheir attacks deal\na lot of damage!\nThey usualy prefer\nto protect their treasure."
/** \brief Descrição do arqueiro */
#define ARCHER_DESC	"Archers attack at range!\nThey don't have a lot of\nhealth but if you're not\ncarefull you might die\nbefore you can\nreach one."
/** \brief Descrição do dragão */
#define DRAGON_DESC	"The Dragon is the\nstrongest enemy you'll\nencounter!\nBe carefull around him\nhe has many different\nkinds of attacks"
/** \brief Descrição da poção de vida */
#define HEALTH_POTION_DESC		"Restores health."
/** \brief Descrição da poção de mana */
#define MANA_POTION_DESC		"Restores Mana."
/** \brief Descrição do pergaminho de fogo */
#define SCROLL_FIRE_DESC		"Launches a fireball\nthat deals damage\nin an area."
/** \brief Descrição do pergaminho de relampago */
#define SCROLL_LIGHTNING_DESC	"Casts a lighting bolt\n on a single target\nThe bolt then jumps\nto a nearby enemy."
/** \brief Descrição do pergaminho de veneno */
#define SCROLL_POISON_DESC		"Cast a poison spell\nthat deals damage\nover time to\none target."
/** \brief Descrição do pergaminho de teleport */
#define SCROLL_TELEPORT_DESC	"Teleports to a\nrandom location\non the map."
/** \brief Descrição do arma de nivel 1 */
#define SWORD_BRONZE_DESC		"It's not very good\nbut it's better\nthan punching."
/** \brief Descrição do arma de nivel 2 */
#define SWORD_IRON_DESC			"Now this is a\ndecent weapon."
/** \brief Descrição do arma de nivel 3 */
#define SWORD_STEEL_DESC		"Steel, "
/** \brief Descrição do arma de nivel 4 */
#define SWORD_PALLADIUM_DESC	"This weapon cuts\nthrough anything like\nit's butter. Except\nrock, rock is still\npretty tough."
/** \brief Descrição do armadura de nivel 1 */
#define ARMOUR_BRONZE_DESC		"Better this\nthen nothing."
/** \brief Descrição do armadura de nivel 2 */
#define ARMOUR_IRON_DESC		"Standard protection,\nnot amazing\nbut it will\nwork for now."
/** \brief Descrição do armadura de nivel 3 */
#define ARMOUR_STEEL_DESC		"I want to see wolfs\ntry and bit through this!"
/** \brief Descrição do armadura de nivel 4 */
#define ARMOUR_PALLADIUM_DESC	"This is made of the\nmost impenetrable\nmaterial ever.\nEven rain can't\nget through!"
/** \brief Lista dos tipos de item */
#define ITEM_TYPES 				{"Potion","Scroll","Weapon","Armour"}
/** \brief Array de descições do items */
#define ITEM_DESCRIPTIONS		{"Empty", \
								 HEALTH_POTION_DESC, \
								 MANA_POTION_DESC, \
								 SCROLL_FIRE_DESC, \
								 SCROLL_LIGHTNING_DESC, \
								 SCROLL_POISON_DESC, \
								 SCROLL_TELEPORT_DESC, \
								 "Empty", \
								 "Empty", \
								 "Empty", \
								 SWORD_BRONZE_DESC, \
								 SWORD_IRON_DESC, \
								 SWORD_STEEL_DESC, \
								 SWORD_PALLADIUM_DESC, \
								 ARMOUR_BRONZE_DESC, \
								 ARMOUR_IRON_DESC, \
								 ARMOUR_STEEL_DESC, \
								 ARMOUR_PALLADIUM_DESC}
/**
\brief Imprime o botão para ligar ou desligar as ajudas
@param name Nome do jogador
*/
void imprime_helpButton(char *name);
/**
\brief Imprime os botões para pedir ajuda sobre os inimigos
@param name Nome do jogador
@param monstros Lista dos monstros
@param num_monstros Número de monstros
*/
void imprime_helpEnemies(char *name, MSTR monstros[], int num_monstros);
/**
\brief Imprime o botão para pedir ajuda sobre o boss
@param name Nome do jogador
@param pos Posição do dragão
*/
void imprime_helpBoss(char *name, POSICAO pos);
/**
\brief Imprime os botões para pedir ajuda sobre os items no inventário
@param name Nome do jogador
@param bag Inventario do jogador
*/
void imprime_helpInvetory(char *name, INVT bag);
/**
\brief Imprime a descrição do item pedido
@param item Item pedido
*/
void imprime_itemDescription(int item);
/**
\brief Imprime a descrição do monstro pedido
@param monstro Monstro pedido
*/
void imprime_monsterDescription(int isInBossBattle, MSTR monstro);
/**
\brief Imprime a area de ataque de um monstro
@param e Estado do jogo
@param monstro Monstro pedido
*/
void imprime_monsterAttackArea(ESTADO e, MSTR monstro);
/**
\brief Imprime a area de ataque de um lobo
@param e Estado do jogo
@param monstro Monstro pedido
*/
void i_wolfAttackArea(ESTADO e,MSTR monstro);
/**
\brief Imprime a area de ataque de um morcego
@param e Estado do jogo
@param monstro Monstro pedido
*/
void i_batAttackArea(ESTADO e, MSTR monstro);
/**
\brief Imprime a area de ataque de um ogre
@param e Estado do jogo
@param monstro Monstro pedido
*/
void i_ogreAttackArea(ESTADO e, MSTR monstro);
/**
\brief Imprime a area de ataque de um arqueiro
@param e Estado do jogo
@param monstro Monstro pedido
*/
void i_archerAttackArea(ESTADO e, MSTR monstro);
/**
\brief Imprime a area de ataque de um dragão
@param e Estado do jogo
*/
void i_dragonAttackArea(ESTADO e);

#endif