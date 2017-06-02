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
int hitMonster(ESTADO *e, POSICAO target,int dmg){
	int monIdx = getMonstro(*e,target);
	if(monIdx < e->num_monstros){
		e->monstros[monIdx].hp-=dmg;
		if(e->monstros[monIdx].hp<1){
			killMonster(monIdx,e->monstros,--e->num_monstros);
		}
	}
	return monIdx < e->num_monstros;
}
void castScroll_Fire(ESTADO *e){
	POSICAO p = itAct2Pos(e->action);
	int pXmax=p.x+2;
	int pYmax=p.y+2;
	for(p.x=pXmax-3;p.x<pXmax;p.x++){
		for (p.y=pYmax-3;p.y < pYmax; p.y++){
			hitMonster(e,p,SCROLL_FIRE_DMG);
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
void castScroll_Lightning(ESTADO *e){
	POSICAO target = itAct2Pos(e->action);
	hitMonster(e,target,SCROLL_LIGHTNING_DMG);
	int num_bolts=1;
	int found;
	do{
		found=0;
		int pXmax=target.x+3;
		int pYmax=target.y+3;
		target.x=pXmax-5;
		target.y=pYmax-5;
		while(target.x < pXmax && !found){
			while(target.y < pYmax && !found){
				if(hitMonster(e,target,SCROLL_LIGHTNING_DMG-(num_bolts*10))){
					found=1;
					num_bolts++;
				}
				target.x++;
				target.y++;
			}
		}
	}while(found);
	e->mp-=SCROLL_COST_LIGHTNING;
}
ESTADO castScroll(ESTADO e){
	switch(e.complexItem.type){
		case 3: castScroll_Fire(&e);
				break;
		case 4: castScroll_Lightning(&e);
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