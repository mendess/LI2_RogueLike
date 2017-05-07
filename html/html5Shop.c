#include "html5Shop.h"

void imprime_shop_item(char item, int index){
	char *itemlist[] = ITEM_LIST;
	IMAGEM(86+(197*index),240,TAM,TAM,itemlist[(int) item]);
	char query[4];
	sprintf(query,"7%d",index);
	ABRIR_LINK(query);
	printf("<rect x=%d y=187 width=164 height=155 style=opacity:0;>\n",29+(197*index));
	FECHAR_LINK;
}
void imprime_inv_slot_shop(char item,int i){
	char *itemlist[] = ITEM_LIST;
	if(item!=0){
		if(i%2){
			IMAGEM(638+(TAM*(i/2)),489,TAM,TAM,itemlist[(int) item]);
		}else{
			IMAGEM(638+(TAM*(i/2)),539,TAM,TAM,itemlist[(int) item]);
		}
	}
}
void imprime_equipment_shop(INVT bag){
	char *itemlist[] = ITEM_LIST;
	IMAGEM(572,489,TAM,TAM,itemlist[(int) bag.weapon]);
	IMAGEM(572,539,TAM,TAM,itemlist[(int) bag.armour]);
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

	ABRIR_LINK("82");//done
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;>\n");
	FECHAR_LINK;
}