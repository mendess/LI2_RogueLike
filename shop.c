#include "shop.h"

int getItemBuyPrice(char item){
	int price=INT_MAX;
	if(item<3){
		price = POTION_BUY_PRICE;
	}else if(item<10){
		price = SCROLL_BUY_PRICE;
	}else if(item<14){
		price = SWORD_BUY_PRICE*(item-9);
	}else if(item<18){
		price = ARMOUR_BUY_PRICE*(item-13);
	}
	return price;
}
int hasEnoughSpace(char inv[]){
	int hasEmptySpace=0;
	int i=0;
	while(!hasEmptySpace && i<INVT_SIZE){
		if(inv[i++]==0){
			hasEmptySpace=1;
		}
	}
	return hasEmptySpace;
}
void putItemInv(char inv[],char item){
	int emptySpace=-1;
	int i=0;
	while(emptySpace == -1){
		if(inv[i]==0){
			emptySpace=i;
		}
		i++;
	}
	inv[emptySpace]=item;
}
char buyItem(char action,char lootTable[],INVT *bag){
	char price = getItemBuyPrice(lootTable[(int) action-70]);
	int enoughMoney = bag->gold > price;
	int enoughSpace = hasEnoughSpace(bag->inv);

	if(!enoughMoney){									/* Se não tem dinheiro que chegue */
		return 2;										/* Retornar o codigo de erro 2 (Não tem dinheiro que chegue) */
	}else if(!enoughSpace){								/* Se não tem espaço que chegue */
		return 3;										/* Retornar o codigo de erro 3 (Não tem espaço que chegue) */
	}else{												/* Se tem dinheiro e espaço que chegue */
		putItemInv(bag->inv,lootTable[(int) action-70]);/* Colocar o item no inventario */
		lootTable[(int) action-70]=0;					/* Retirar o item da loja */
		bag->gold-=price;								/* Subtrair o preco ao dinheiro do jogador */
		return 1;										/* Retornar o codigo de erro 1 (Compra com sucesso) */
	}
}
int getItemSellPrice(char item){
	int price=INT_MAX;
	if(item<3){
		price = POTION_SELL_PRICE;
	}else if(item<10){
		price = SCROLL_SELL_PRICE;
	}else if(item<14){
		price = SWORD_SELL_PRICE*(item-9);
	}else if(item<18){
		price = ARMOUR_SELL_PRICE*(item-13);
	}
	return price;
}
void sellItem_Bag(char action, INVT *bag){
	char *item=&(bag->inv[(int) action-74]);
	bag->gold+=getItemSellPrice(*item);
	*item=0;
}
void sellEquipment(char action, INVT *bag){
	char *item;
	if(action==80){
		item=&(bag->weapon);
	}else{
		item=&(bag->armour);
	}
	bag->gold+=getItemSellPrice(*item);
	*item=0;
}
ESTADO shop(ESTADO e){
	if(e.action<74){
		e.shopFeedback=buyItem(e.action,e.lootTable,&(e.bag));
	}/*else if(e.action<80){
		sellItem_Bag(e.action,&(e.bag));
	}else if(e.action<82){
		sellEquipment(e.action,&(e.bag));
	}*/
	return e;
}