#include "items.h"

void usePotion(ESTADO *e,int *item){
	
	int *current;
	int bonus,max;
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

void equipItem(ESTADO *e, int *itemToEquip){
	int *equipedItem;
	if(*itemToEquip>=SWORD_BRONZE && *itemToEquip<=SWORD_PALLADIUM){
		equipedItem=&(e->bag.weapon);
	}else{
		equipedItem=&(e->bag.armour);
	}
	int tmp = *itemToEquip;
	*itemToEquip = *equipedItem;
	*equipedItem = tmp;
}
int getSpellCost(int item){
	int costs[] = COST_ARRAY;
	return costs[item-3];
}

ESTADO useItem(ESTADO e){
	int *item = &e.bag.inv[e.action-40];
	if(*item<3){
		usePotion(&e,item);
	}else if(*item<10){
		if(e.mp>=getSpellCost(*item)){
			e.complexItem.isBeingUsed=1;
			e.complexItem.type=*item;
			e.complexItem.lastPickedTarget=-1;
			e.complexItem.isBeingCast=0;
			e.complexItem.unCastable=0;
			*item=0;
		}else{
			e.complexItem.unCastable=1;
		}
	}else{
		equipItem(&e,item);
	}
	return e;
}
POSICAO itAct2Pos(int action){
	POSICAO p;
	p.x = (action - 10000) / 100;
	p.y = (action - 10000) % 100;
	return p;
}
void castScroll_Fire(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int pXmax=p.x+2;
	int pYmax=p.y+2;
	for(p.x=pXmax-3;p.x<pXmax;p.x++){
		for (p.y=pYmax-3;p.y < pYmax; p.y++){
			int monIdx=getMonstro(*e,p);
			if(monIdx < e->num_monstros){
				e->monstros[monIdx].hp-=SCROLL_FIRE_DMG;
				if(e->monstros[monIdx].hp<1){
					killMonster(monIdx,e->monstros,--e->num_monstros);
				}
			}
			if(com_jogador(*e,p)){
				e->hp-=SCROLL_FIRE_DMG;
			}
		}
	}
	e->mp-=SCROLL_COST_FIRE;
}
void castScroll_Teleport(ESTADO *e){
	e->jog=itAct2Pos(e->action);
	e->mp-=SCROLL_COST_TELEPORT;
}
ESTADO castScroll(ESTADO e){
	switch(e.complexItem.type){
		case 3: castScroll_Fire(&e);
				break;
		case 6: castScroll_Teleport(&e);
				break;
	}
	e.complexItem.isBeingUsed=0;
	e.complexItem.isBeingCast=1;
	return e;
}
ESTADO handleComplexItem(ESTADO e){
	if(e.complexItem.lastPickedTarget==e.action){
		e=castScroll(e);
	}else{
		e.complexItem.lastPickedTarget=e.action;
		e.complexItem.isBeingCast=0;
	}
	return e;
}