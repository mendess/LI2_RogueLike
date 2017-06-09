#define DEBUG

#include "html6Shop.h"

void imprime_shop_item(char *name, int item, int index){
	if(item){
		char *itemlist[] = ITEM_LIST;
		char query[4];
		sprintf(query,"7%d",index);
		ABRIR_LINK(name,query);
		IMAGEM(73+(197*index),310,75,75,itemlist[(int) item]);
		FECHAR_LINK;
	}
}
void imprime_inv_slot_shop(char *name,int item,int i,int isDeletingItems){
	char *itemlist[] = ITEM_LIST;
	if(item!=0){
		if(isDeletingItems){
			char query[4];
			sprintf(query,"4%d",i);
			ABRIR_LINK(name,query);
		}
		if(i%2){
			IMAGEM(638+(TAM*(i/2)),489,TAM,TAM,itemlist[item]);
		}else{
			IMAGEM(638+(TAM*(i/2)),539,TAM,TAM,itemlist[item]);
		}
		if(isDeletingItems){
			FECHAR_LINK;
		}
	}
}
void imprime_equipment_shop(int weapon, int armour){		
	char *itemlist[] = ITEM_LIST;
	IMAGEM(572,489,TAM,TAM,itemlist[weapon]);
	IMAGEM(572,539,TAM,TAM,itemlist[armour]);
}
void imprime_price(int x, int y, int amount){
	int digitPos=3;
	while(amount){
		int digit = amount % 10;
		char filepath[15];
		amount /= 10;
		sprintf(filepath,"Numero_%d.png",digit);
		IMAGEM(x+(25*digitPos),y,25,25,filepath);
		digitPos--;
	}
}
void imprime_shop_prices(int lootTable[]){
	int i;
	for(i=0;i<LOOT_TABLE_SIZE;i++){
		int x=45+(197*i);
		int y=393;
		int price = getItemBuyPrice(lootTable[i]);
		imprime_price(x,y,price);
	}
	IMAGEM(400,492,50,50,"goldcoins.png");
}
void imprimeShop(ESTADO e){
	ABRIR_SVG;
	if(e.feedback==0){
		srand(time(NULL));
		e.feedback = rand() % 3 + 3;
	}
	char *shopScreens[] = SHOP_SCREENS;
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,shopScreens[e.feedback]);
	int i;
	for (i = 0; i < 4; ++i){
		imprime_shop_item(e.name,e.lootTable[i],i);
	}
	for (i = 0; i < INVT_SIZE; ++i){
		imprime_inv_slot_shop(e.name,e.bag.inv[i],i,e.isDeletingItems);
	}
	imprime_equipment_shop(e.bag.weapon,e.bag.armour);

	char *trashCan[] = {"button_trashCan_closed.png","button_trashCan_opened.png"};
	ABRIR_LINK(e.name,"80");
	IMAGEM(500,539,50,50,trashCan[e.isDeletingItems]);
	FECHAR_LINK;

	imprime_shop_prices(e.lootTable);
	imprime_price(450,502,e.bag.gold);

	ABRIR_LINK(e.name,"5");/* done */
	printf("<rect x=0 y=540 width=60 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;

	#ifdef DEBUG
	printf("<p>world_lvl:%d  score:%d  LootTable[%d,%d,%d,%d] Gold:%d Inv[%d,%d,%d,%d,%d,%d] Weapon:%d Armour:%d </p>",
			e.world_lvl,
			e.score,
			e.lootTable[0],
			e.lootTable[1],
			e.lootTable[2],
			e.lootTable[3],
			e.bag.gold,
			e.bag.inv[0],
			e.bag.inv[1],
			e.bag.inv[2],
			e.bag.inv[3],
			e.bag.inv[4],
			e.bag.inv[5],
			e.bag.weapon,
			e.bag.armour);
	#endif
}
