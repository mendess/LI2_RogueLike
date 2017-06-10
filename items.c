#include "items.h"

int usePotion(ESTADO *e,int *item){
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
		return 0;
	}else{
		return 2;
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
int lightningHasTargets(ESTADO e){
	int found,i,j;
	found=0;
	for(i=-2;i<3 && !found;i++){
		for(j=-2;j<3 && !found;j++){
			POSICAO newTarget = {e.jog.x+i,e.jog.y+j};
			if(com_monstros(e,newTarget)){
				found=1;
			}
		}
	}
	return found;
}
ESTADO useItem(ESTADO e){
	if(e.isDeletingItems){
		e.bag.inv[e.action-40]=0;
	}else{
		int *item = &e.bag.inv[e.action-40];
		if(*item<3){
			e.feedback=usePotion(&e,item);
		}else if(*item<10){
			int hasTargets = *item==SCROLL_LIGHTNING ? lightningHasTargets(e) : 1;
			int hasMana = e.mp>=getSpellCost(*item);
			if(hasMana){
				if(hasTargets){
					e.complexItem.isBeingUsed=1;
					e.complexItem.type=*item;
					e.complexItem.lastPickedTarget=-1;
					e.complexItem.isBeingCast=0;
					e.feedback=0;
					*item=0;
				}else{
					e.feedback=4;
				}
			}else{
				e.feedback=1;
			}
		}else{
			equipItem(&e,item);
		}
	}
	return e;
}
int getItemSpace(int inv[]){
	int i=0,foundSpace=0;
	while(i<INVT_SIZE && !foundSpace){
		if(inv[i]){
			i++;
		}else{
			foundSpace=1;
		}
	}
	return i;
}
int getDroppedItem(CHEST droppedItems[], POSICAO pos){
	int i=0, foundItem=0;
	while(i<MAX_DROPPED_ITEMS && !foundItem){
		if(droppedItems[i].item!=0 && droppedItems[i].pos.x == pos.x && droppedItems[i].pos.y == pos.y){
			foundItem=1;
		}else{
			i++;
		}
	}
	return i;
}
int pickUpItem(POSICAO jog, int inv[], CHEST droppedItems[], int action){
	int invI = getItemSpace(inv);
	if(invI==INVT_SIZE){
		return 3;
	}
	POSICAO pos = calcularNovaPosicao(jog,action-80);
	int drpItemI = getDroppedItem(droppedItems,pos);
	inv[invI] = droppedItems[drpItemI].item;
	droppedItems[drpItemI].item = 0;
	return 0;
}
POSICAO itAct2Pos(int action){
	POSICAO p;
	p.x = (action - 10000) / 100;
	p.y = (action - 10000) % 100;
	return p;
}
int getChest(CHEST chests[], int num_chests, POSICAO p){
	int i, found;
	i=found=0;
	while(!found && i<num_chests){
		if(chests[i].pos.x == p.x && chests[i].pos.y == p.y){
			found=1;
		}else{
			i++;
		}
	}
	return i;
}
void removeChest(int i, CHEST chests[], int num_chests){
	chests[i]=chests[num_chests];
}
void openChest(ESTADO *e){
	POSICAO chest = calcularNovaPosicao(e->jog,e->action-90);
	int chestIdx = getChest(e->chests, e->num_chests, chest);
	dropItem(e->droppedItems, &(e->chests[chestIdx].item), e->chests[chestIdx].pos);
	removeChest(chestIdx, e->chests, e->num_chests--);
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
int isRepeat(POSICAO targets[], int num_targets, POSICAO newTarget){
	int i;
	int repeat=0;
	for (i = 0; i < num_targets && !repeat; ++i){
		if(targets[i].x==newTarget.x && targets[i].y==newTarget.y){
			repeat=1;
		}
	}
	return repeat;
}
void castScroll_Lightning(ESTADO *e){
	POSICAO target = itAct2Pos(e->action);
	POSICAO targets[(SCROLL_LIGHTNING_DMG/10) + 1];
	int num_bolts=1;
	targets[0] = target;
	hitMonster(e,target,SCROLL_LIGHTNING_DMG);
	int found;
	do{
		found = 0;
		int x,y;
		for (x = -2; x < 3 && !found; ++x){
			for (y = -2; y < 3 && !found; ++y){
				POSICAO newTarget = {target.x+x,target.y+y};
				if(!isRepeat(targets,num_bolts,newTarget) && com_monstros(*e,newTarget)){
					hitMonster(e,newTarget,SCROLL_LIGHTNING_DMG - (10*num_bolts));
					found=1;
					target = newTarget;
					targets[num_bolts++]=newTarget;
				}
			}
		}
	}while(found && SCROLL_LIGHTNING_DMG-(num_bolts*10)>0);
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