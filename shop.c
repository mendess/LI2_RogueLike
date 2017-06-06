#include "shop.h"

int getItemBuyPrice(int item){
	int price=INT_MAX;
	if(item==0){
		price = 0;
	}else if(item<3){
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
int hasEnoughSpace(int inv[]){
	int hasEmptySpace=0;
	int i=0;
	while(!hasEmptySpace && i<INVT_SIZE){
		if(inv[i++]==0){
			hasEmptySpace=1;
		}
	}
	return hasEmptySpace;
}
void putItemInv(int inv[],int item){
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
int buyItem(int action,int lootTable[],INVT *bag){
	int price = getItemBuyPrice(lootTable[(int) action-70]);
	int enoughMoney = bag->gold >= price;
	int enoughSpace = hasEnoughSpace(bag->inv);

	if(!enoughMoney){									/* Se não tem dinheiro que chegue */
		return 1;										/* Retornar o codigo de erro 1 (Não tem dinheiro que chegue) */
	}else if(!enoughSpace){								/* Se não tem espaço que chegue */
		return 2;										/* Retornar o codigo de erro 2 (Não tem espaço que chegue) */
	}else{												/* Se tem dinheiro e espaço que chegue */
		putItemInv(bag->inv,lootTable[(int) action-70]);/* Colocar o item no inventario */
		lootTable[(int) action-70]=0;					/* Retirar o item da loja */
		bag->gold-=price;								/* Subtrair o preco ao dinheiro do jogador */
		return 0;										/* Retornar o codigo de erro 0 (Compra com sucesso) */
	}
}