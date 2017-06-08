#ifndef __HTML_5_TIPS_H__
#define __HTML_5_TIPS_H__

#include "html5Playing.h"
#include "../items.h"

#define WOLF_DESC	"Wolfs are fast and\ncan attack diagonaly\nbut don't deal\nmuch damage.\nThey are known\nto attack in groups!"

#define BAT_DESC	"Bats can fly over\nwalls and attack\ndiagonaly but they can't \ntake many hits or deal\nmuch damage."

#define OGRE_DESC	"Ogres are a sturdy foe!\nAlthough they can't\nattack diagonaly,\ntheir attacks deal\na lot of damage!\nThey usualy prefer\nto protect their treasure."

#define ARCHER_DESC	"Archers attack at range!\nThey don't have a lot of\nhealth but if you're not\ncarefull you might die\nbefore you can\nreach one."

#define DRAGON_DESC	"The Dragon is the strongest\nenemy you'll encounter!\nbe carefull around him\nhe can attack both at\nrange and up close\nTIP: Watch for the patterns!"

#define HEALTH_POTION_DESC		"Restores health."
#define MANA_POTION_DESC		"Restores Mana."
#define SCROLL_FIRE_DESC		"Launches a fireball\nthat deals damage\nin an area."
#define SCROLL_LIGHTNING_DESC	"Casts a lighting bolt\n on a single target\nThe bolt then jumps\nto a nearby enemy."
#define SCROLL_POISON_DESC		"Cast a poison spell\nthat deals damage\nover time to\none target."
#define SCROLL_TELEPORT_DESC	"Teleports to a\nrandom location\non the map."
#define SWORD_BRONZE_DESC		"It's not very good\nbut it's better\nthan punching."
#define SWORD_IRON_DESC			"Now this is a\ndecent weapon."
#define SWORD_STEEL_DESC		"Wow its so sharp!"
#define SWORD_PALLADIUM_DESC	"This weapon cuts\nthrough anything like\nit's butter. Except\nrock, rock is still\npretty tough."
#define ARMOUR_BRONZE_DESC		"Better this instead\nthen nothing."
#define ARMOUR_IRON_DESC		"Standard protection,\nnot amazing\nbut it will\nwork for now."
#define ARMOUR_STEEL_DESC		"I want to see wolfs\ntry and bit through this!"
#define ARMOUR_PALLADIUM_DESC	"This is made of the\nmost impenetrable\nmaterial ever.\nEven rain can't\nget through!"

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

/* TMP */
#define MON_HP_WOLF		10
#define MON_HP_BAT		5
#define MON_HP_OGRE		35
#define MON_HP_ARCHER	10
#define MON_HP_DRAGON	80

void imprime_helpButton(char *name);
void imprime_helpEnemies(char *name, MSTR monstros[], int num_monstros);
void imprime_helpInvetory(char *name, INVT bag);
void imprime_monsterDescription(MSTR monstro);
void imprime_itemDescription(int item);
void imprime_monsterAttackArea(ESTADO e, MSTR monstro);
void i_wolfAttackArea(ESTADO e,MSTR monstro);
void i_batAttackArea(ESTADO e, MSTR monstro);
void i_ogreAttackArea(ESTADO e, MSTR monstro);
void i_archerAttackArea(ESTADO e, MSTR monstro);
void i_dragonAttackArea(ESTADO e);

#endif