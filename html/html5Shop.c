#define DEBUG

#include "html5Shop.h"

void imprime_shop_item(char item, int index){
	char *itemlist[] = ITEM_LIST;
	char query[4];
	sprintf(query,"7%d",index);
	ABRIR_LINK(query);
	IMAGEM(86+(197*index),240,TAM,TAM,itemlist[(int) item]);
	FECHAR_LINK;
}
void imprime_inv_slot_shop(char item,int i){
	char *itemlist[] = ITEM_LIST;
	if(item!=0){
		char query[4];
		sprintf(query,"7%d",i+4);
		if(i%2){
			ABRIR_LINK(query);
			IMAGEM(638+(TAM*(i/2)),489,TAM,TAM,itemlist[(int) item]);
			FECHAR_LINK;
		}else{
			ABRIR_LINK(query);
			IMAGEM(638+(TAM*(i/2)),539,TAM,TAM,itemlist[(int) item]);
			FECHAR_LINK;
		}
	}
}
void imprime_equipment_shop(INVT bag){
	char *itemlist[] = ITEM_LIST;
	if(bag.weapon){
		ABRIR_LINK("80");
		IMAGEM(572,489,TAM,TAM,itemlist[(int) bag.weapon]);
		FECHAR_LINK;
	}
	if(bag.armour){
		ABRIR_LINK("81");
		IMAGEM(572,539,TAM,TAM,itemlist[(int) bag.armour]);
		FECHAR_LINK;
	}
}
void imprime_price(int x, int y, int amount){
	int digitPos=3;
	while(amount){
		int digit = amount % 10;
		amount /= 10;
		char filepath[15];
		sprintf(filepath,"Number%d.png",digit);
		IMAGEM(x+(25*digitPos),y,25,25,filepath);
		digitPos--;
	}
}
void imprime_shop_prices(char lootTable[],int gold){
	int i;
	for(i=0;i<LOOT_TABLE_SIZE;i++){
		int x=70+(197*i);
		int y=358;
		int price = getItemBuyPrice(lootTable[i]);
		imprime_price(x,y,price);
	}
	imprime_price(450,502,gold);
}
void imprime_shop_messages(char shopFeedback){
	char *messages[] = {"Empty","ShopMessage1Success.png","ShopMessage2notEnoughGold.png","ShopMessage3notEnoughSpace.png"};
	IMAGEM(20,400,150,150,messages[(int) shopFeedback]);
}
void imprimeShop(ESTADO e){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenShop.png");
	int i;
	for (i = 0; i < 4; ++i){
		imprime_shop_item(e.lootTable[i],i);
	}
	for (i = 0; i < INVT_SIZE; ++i){
		imprime_inv_slot_shop(e.bag.inv[i],i);
	}
	imprime_equipment_shop(e.bag);

	imprime_shop_prices(e.lootTable,e.bag.gold);

	imprime_shop_messages(e.shopFeedback);

	ABRIR_LINK("5");//done
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	#ifdef DEBUG
	printf("<p>world_lvl:%d  score:%d  LootTable[%d,%d,%d,%d] Gold:%d Inv[%d,%d,%d,%d] Weapon:%d Armour:%d </p>",
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
			e.bag.weapon,
			e.bag.armour);
	#endif

}