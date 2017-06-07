#define DEBUG

#include "html5Playing.h"

int getDirection(ESTADO e,POSICAO p){
	int type=0;
	if(com_monstros(e,e.jog)){
		type=10;
	}
	return 7-3*(p.y+1)+p.x+1+type;
}
void imprime_move_frame(POSICAO p, int moldura){
	char *mold[]=PLAY_FRAMES;
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,mold[moldura]);
}
void imprime_link(char *name, POSICAO target, int new_action, int moldura){
	char query[5];
	sprintf(query,"%d",new_action);
	ABRIR_LINK(name,query);
	imprime_move_frame(target,moldura);
	FECHAR_LINK;
}
void imprime_move(ESTADO e, POSICAO p){
	int new_action;
	e.jog.x += p.x;
	e.jog.y += p.y;
	if(com_saida(e,e.jog)){
		new_action=5;
	}else{
		new_action=getDirection(e,p);
	}
	if (!outOfBounds(e.jog) && !com_pedras(e,e.jog)){
		int mold = com_monstros(e,e.jog) ? 1 : 0;
		imprime_link(e.name,e.jog,new_action,mold);
	}
}
void imprime_ranged_attack(ESTADO e,POSICAO dif){
	POSICAO pos;
	pos.x=dif.x+e.jog.x;
	pos.y=dif.y+e.jog.y;
	if(!outOfBounds(pos) && com_monstros(e,pos)){
		int actions[5][5] = ARCHER_ACTION_MATRIX;
		int new_action=actions[dif.y+2][dif.x+2];
		imprime_link(e.name,pos,new_action,1);
	}
}
void imprime_all_ranged_atacks(ESTADO e){
	POSICAO p;
	for(p.x=-2,p.y=0;p.x<1;p.x++,p.y++){
		imprime_ranged_attack(e,p);
		int tmp;
		tmp=p.x;p.x=p.y;p.y=tmp;
		imprime_ranged_attack(e,p);
		tmp=p.x;p.x=p.y;p.y=tmp;
	}
	p.x=p.y=-1;
	imprime_ranged_attack(e,p);
	p.x=p.y= 1;
	imprime_ranged_attack(e,p);
}
void imprime_lesser_teleport(ESTADO e){
	POSICAO dif;
	for (dif.x = -1; dif.x < 2; dif.x++){
		for (dif.y = -1; dif.y < 2; dif.y++){
			if(abs(dif.x)!=abs(dif.y)){
				POSICAO pos = {e.jog.x + dif.x*3,e.jog.y + dif.y*3};
				if(!outOfBounds(pos) && !com_pedras(e,pos) && !com_monstros(e,pos) && !com_saida(e,pos)){
					int new_action = 30 + getDirection(e,dif);
					imprime_link(e.name,pos,new_action,2);
				}
			}
		}
	}
}
void imprime_item_pickUp(ESTADO e){
	POSICAO dif;
	for (dif.x = -1; dif.x < 2; dif.x++){
		for (dif.y = -1; dif.y < 2; dif.y++){
			POSICAO pos = {e.jog.x + dif.x,e.jog.y + dif.y};
			if(!outOfBounds(pos) && com_droppedItem(e.droppedItems,pos) && !com_pedras(e,pos) && !com_monstros(e,pos) && !com_saida(e,pos)){
				int new_action = 80 + getDirection(e,dif);
				imprime_link(e.name,pos,new_action,3);
			}
		}
	}
}
void imprime_all_moves(ESTADO e){
	POSICAO p;
	for(p.x=-1;p.x<=1;p.x++){
		for(p.y=-1;p.y<=1;p.y++){
			if ((p.x == 0 || p.y == 0) && p.x!=p.y){
				imprime_move(e,p);
			}
		}
	}
	if(e.classe==2 || e.classe==3){
		imprime_all_ranged_atacks(e);
	}
	if(CAN_USE_LESSER_TELEPORT){
		imprime_lesser_teleport(e);
	}
	imprime_item_pickUp(e);
}
void imprime_jogador (ESTADO e){
	char *dir[] = {"Jogador_Viking_Right.png","Jogador_Viking_Left.png"};
	IMAGEM(TAM*(e.jog.x+1),TAM*(e.jog.y+1),TAM,TAM,dir[(int) e.direction]);
	if(!e.isDeletingItems){
		if(e.complexItem.isBeingUsed){
			imprime_castTargets(&e);
		}else{
			if(e.complexItem.isBeingCast && e.action>9999){
				imprime_castSpell(&e);
			}
			if(e.hp>0){
				imprime_all_moves(e);
			}
		}
	}
}
void imprime_droppedItems(CHEST droppedItems[]){
	int i;
	char *itemlist[] = ITEM_LIST;
	for(i=0;i<MAX_DROPPED_ITEMS;i++){
		if(droppedItems[i].item){
			IMAGEM(TAM*(droppedItems[i].pos.x+1),TAM*(droppedItems[i].pos.y+1),TAM,TAM,itemlist[droppedItems[i].item]);
		}
	}
}
void imprime_monstros (MSTR monstros[],int num_monstros){
	int i;
	char *wolfs[]={"Monstro_Lobo_Lateral_1.png","Monstro_Lobo_Lateral_2.png"};
	srand(time(NULL));
	for(i=0;i<num_monstros;i++){
		int r = rand() % 2;
		IMAGEM(TAM*(monstros[i].x+1),TAM*(monstros[i].y+1),TAM,TAM,wolfs[r]);
	}
}
void imprime_pedras (POSICAO pedras[]){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		IMAGEM(TAM*(pedras[i].x+1),TAM*(pedras[i].y+1),TAM,TAM,"Tile_Obstacle.png");
	}
}
void imprime_saida (POSICAO p){
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,"Tile_Exit.png");
}
void imprime_casa (POSICAO p){
	char *tiles[]={"Tile1.png","Tile2.png","Tile3.png","Tile4.png"};
	int r = rand() % 4;
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,tiles[r]);
}
void imprime_chao(){
	int x,y;
	POSICAO p;
	for(x = 0; x < SIZE; x++){
		for(y = 0; y < SIZE; y++){
			p.x= x;
			p.y= y;
			imprime_casa(p);
		}
	}
}
void imprime_background (int classe){
	char *background[] = {"Ingame_Viking.png","Ingame_Archer.png","Ingame_Mage.png"};
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,background[(int) classe-1]);
}
void imprime_hpBar(int hp){
	IMAGEM(600,10,200,50,"BarHealthIcon.png");
	IMAGEM(641,10,(int) ((hp)*1.5),50,"BarHealthBar.png");
}
void imprime_mpBar(int mp,int classe){
	char *icons[] = {"BarEnergyIcon.png","BarManaIcon.png"};
	char *bars[] = {"BarEnergyBar.png","BarManaBar.png"};
	IMAGEM(600,55,			   200,50,(classe <3) ? icons[0] : icons[1]);
	IMAGEM(641,55,(int) ((mp)*1.5),50,(classe <3) ? bars[0]  : bars[1]);
}
void imprime_gameOverScreen(char *name){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenGameOver.png");
	ABRIR_LINK(name,"0");/* back */
	printf("<rect x=300 y=350 width=200 height=70 style=opacity:0;></rect>\n");
	FECHAR_LINK;
}
void imprime_inv_slot(char *name, int item,int i){
	char *itemlist[] = ITEM_LIST;
	if(item!=0){
		int X = 620+(TAM*(i/2));
		int Y = 110+(50*!(i%2));
		char query[4];
		IMAGEM(X,Y,TAM,TAM,itemlist[item]);
		sprintf(query,"4%d",i);
		ABRIR_LINK(name,query);
		printf("<rect x=%d y=%d width=50 height=50 style=opacity:0;></rect>\n",X,Y);
		FECHAR_LINK;
	}
}
void imprime_equipment(INVT bag){
	char *itemlist[] = ITEM_LIST;
	IMAGEM(690,260,TAM,TAM,itemlist[bag.weapon]);
	IMAGEM(690,310,TAM,TAM,itemlist[bag.armour]);
}
void imprime_gold(int x, int y, int amount){
	int digitPos=3;
	while(amount){
		int digit = amount % 10;
		char filepath[15];
		amount /= 10;
		sprintf(filepath,"Number%d.png",digit);
		IMAGEM(x+(25*digitPos),y,25,25,filepath);
		digitPos--;
	}
}
void imprime_inventory(int mode,char *name,INVT bag){
	int i;
	IMAGEM(620,110,150,100,"Inv_bag.png");
	for (i = 0; i < INVT_SIZE; ++i){
		imprime_inv_slot(name,bag.inv[i],i);
	}
	IMAGEM(690,260,50,100,"Inv_equipment.png");
	imprime_equipment(bag);
	char *trashCan[] = {"TrashCan_closed.png","TrashCan_opened.png"};
	ABRIR_LINK(name,"80");
	IMAGEM(745,260,50,50,trashCan[mode]);
	FECHAR_LINK;
	IMAGEM(620,210,50,50,"goldcoins.png");
	imprime_gold(660,225,bag.gold);
}
void imprime_feedback(int feedback){
	char *feedbackMessages[] = FEEDBACK_MSGS;
	printf("<text x=600 y=480>%s</text>\n",feedbackMessages[feedback]);
}
void imprimePlaying(ESTADO e){
	ABRIR_SVG;

	srand(e.pedras[0].x);
	imprime_background(e.classe);
	imprime_chao();
	imprime_saida(e.saida);
	imprime_pedras(e.pedras);
	imprime_droppedItems(e.droppedItems);
	imprime_monstros(e.monstros,e.num_monstros);
	imprime_hpBar(e.hp);
	imprime_mpBar(e.mp,e.classe);
	imprime_inventory(e.isDeletingItems,e.name,e.bag);
	imprime_jogador(e);
	if(e.hp<1){
		imprime_gameOverScreen(e.name);
	}
	imprime_feedback(e.feedback);

	ABRIR_LINK(e.name,"0");/* back */
	printf("<rect x=660 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;
	
	FECHAR_SVG;

	#ifdef DEBUG
	printf("<p>hp:%d  mp:%d  world_lvl:%d  score:%d  turn:%d  LootTable[%d,%d,%d,%d] jog.x:%x jog.y:%d drops[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]</p>\n",
			e.hp,
			e.mp,
			e.world_lvl,
			e.score,
			e.turn,
			e.lootTable[0],
			e.lootTable[1],
			e.lootTable[2],
			e.lootTable[3],
			e.jog.x,
			e.jog.y,
			e.droppedItems[0].item,
			e.droppedItems[1].item,
			e.droppedItems[2].item,
			e.droppedItems[3].item,
			e.droppedItems[4].item,
			e.droppedItems[5].item,
			e.droppedItems[6].item,
			e.droppedItems[7].item,
			e.droppedItems[8].item,
			e.droppedItems[9].item,
			e.droppedItems[10].item,
			e.droppedItems[11].item);
	printf("<p>isBeingUsed:%d  type:%d  lastPickedTarget:%d  isBeingCast:%d </p>\n",
			e.complexItem.isBeingUsed,
			e.complexItem.type,
			e.complexItem.lastPickedTarget,
			e.complexItem.isBeingCast);
	int x;
	printf("<p>");
	for(x=0;x<e.num_monstros;x++){
		printf("x:%d y:%d hp:%d\t", e.monstros[x].x,e.monstros[x].y,e.monstros[x].hp);
	}
	printf("</p>");
	#endif
}
