#include "html5PlayingTips.h"

void imprime_helpButton(char *name){
	ABRIR_LINK(name,"10");
	IMAGEM(745,310,TAM,TAM,"button_toggle_help.png");
	FECHAR_LINK;
}
void imprime_helpEnemies(char *name, MSTR monstros[], int num_monstros){
	while(num_monstros--){
		char query[5];
		sprintf(query,"%d",10000+(monstros[num_monstros].x*100)+monstros[num_monstros].y);
		ABRIR_LINK(name,query);
		IMAGEM_FORMATED(monstros[num_monstros].x,monstros[num_monstros].y,TAM,TAM,"button_ask_help.png");
		FECHAR_LINK;
	}
}
void imprime_helpInvetory(char *name, INVT bag){
	int i;
	for(i=0;i<INVT_SIZE;i++){
		if(bag.inv[i]!=0){
		int X = 620+(TAM*(i/2));
		int Y = 110+(50*!(i%2));
		char query[4];
		sprintf(query,"4%d",i);
		ABRIR_LINK(name,query);
		IMAGEM(X,Y,TAM,TAM,"button_ask_help.png");
		FECHAR_LINK;
		}
	}
	if(bag.weapon){
		ABRIR_LINK(name,"46");
		IMAGEM(690,260,TAM,TAM,"button_ask_help.png");
		FECHAR_LINK;
	}
	if(bag.armour){
		ABRIR_LINK(name,"47");
		IMAGEM(690,310,TAM,TAM,"button_ask_help.png");
		FECHAR_LINK;
	}
}
void imprime_itemDescription(int item){
	char *ITEM_DESC[] = ITEM_DESCRIPTIONS;
	imprime_texto(600, 460, ITEM_DESC[item],17);
}
void imprime_monsterDescription(MSTR monstro){
	int BASE_HPS[]    = {MON_HP_WOLF,MON_HP_BAT,MON_HP_OGRE,MON_HP_ARCHER,MON_HP_DRAGON};
	char *MSTR_DESC[] = {WOLF_DESC  ,BAT_DESC  ,OGRE_DESC  ,ARCHER_DESC  ,DRAGON_DESC  };
	printf("<text x=600 y=420>MAX HP: %d</text>\n",BASE_HPS[monstro.monType]);
	imprime_texto(600, 440, MSTR_DESC[monstro.monType],15);
}
void imprime_monsterAttackArea(ESTADO e, MSTR monstro){
	switch(monstro.monType){
		case 0: i_wolfAttackArea(e,monstro);
				break;
		case 1: i_batAttackArea(e,monstro);
				break;
		case 2: i_ogreAttackArea(e,monstro);
				break;
		case 3: i_archerAttackArea(e,monstro);
				break;
		case 4: i_dragonAttackArea(e);
				break;
	}
}
void i_wolfAttackArea(ESTADO e,MSTR monstro){
	int i,j;
	for (i = -1; i < 2; ++i){
		for (j = -1; j < 2; ++j){
			POSICAO mon = {monstro.x+i,monstro.y+j};
			if(!outOfBounds(mon) && !com_monstros(e,mon) && !com_pedras(e,mon)){
				SQUARE_FORMATED(mon.x,mon.y,"red",0.3,"black",0.0,TAM);
			}
		}
	}
}
void i_batAttackArea(ESTADO e, MSTR monstro){
	int i,j;
	for (i = -1; i < 2; ++i){
		for (j = -1; j < 2; ++j){
			POSICAO mon = {monstro.x+i,monstro.y+j};
			if(!outOfBounds(mon) && !com_monstros(e,mon) && !com_pedras(e,mon)){
				SQUARE_FORMATED(mon.x,mon.y,"red",0.3,"black",0.0,TAM);
			}
		}
	}
}
void i_ogreAttackArea(ESTADO e, MSTR monstro){
	int i,j;
	for (i = -1; i < 2; ++i){
		for (j = -1; j < 2; ++j){
			POSICAO mon = {monstro.x+i,monstro.y+j};
			if((i==0 || j==0) && !outOfBounds(mon) && !com_monstros(e,mon) && !com_pedras(e,mon)){
				SQUARE_FORMATED(mon.x,mon.y,"red",0.3,"black",0.0,TAM);
			}
		}
	}
}
void i_archerAttackArea(ESTADO e, MSTR monstro){
	int x,y;
	for (x = -3; x < 4; ++x){
		for (y = -3; y < 4; ++y){
			POSICAO mon = {monstro.x+x,monstro.y+y};
			if(y<((-1*abs(x))+4) && y>(abs(x)-4)  && !outOfBounds(mon) && !com_monstros(e,mon) && !com_pedras(e,mon)){
				SQUARE_FORMATED(mon.x,mon.y,"red",0.3,"black",0.0,TAM);	
			}
		}
	}
}
void i_dragonAttackArea(ESTADO e){
	int i,j;
	for (i = 0; i < SIZE; ++i){
		for (j = 0; j < SIZE; ++j){
			POSICAO p = {i,j};
			if(!com_monstros(e,p)){
				SQUARE_FORMATED(i,j,"red",0.3,"black",0.0,TAM);
			}
		}
	}
}