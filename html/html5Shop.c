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

	ABRIR_LINK("5");//done
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;
}