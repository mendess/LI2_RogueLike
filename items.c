#include "items.h"

void usePotion(ESTADO *e,char *item){
	
	char *current;
	char bonus,max;
	if(*item==1){
		current = &(e->hp);
		max = getClassHp(e->classe);
		bonus = HP_POT_POWER;
	}else{
		current = &(e->mp);
		max = getClassMp(e->classe);
		bonus = MP_POT_POWER;
	}
	if(*current!=max){
		if(*current+bonus>max){
			*current=max;
		}else{
			*current+=bonus;
		}
		*item=0;
	}
}

void equipItem(ESTADO *e, char *itemToEquip){
	char *equipedItem;
	if(*itemToEquip>9 && *itemToEquip<14){
		equipedItem=&(e->bag.weapon);
	}else{
		equipedItem=&(e->bag.armour);
	}
	char tmp = *itemToEquip;
	*itemToEquip = *equipedItem;
	*equipedItem = tmp;
}

ESTADO useItem(ESTADO e){
	char *item = &e.bag.inv[e.action-20];
	if(*item<3){
		usePotion(&e,item);
	}else if(*item<10){
		e.usingItem=*item;
		*item=0;
	}else{
		equipItem(&e,item);
	}
	return e;
}
ESTADO castScroll(ESTADO e){
	return e;
}