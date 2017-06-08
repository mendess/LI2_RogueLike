#define DEBUG

#include "html5Playing.h"

int getDirection(ESTADO e,POSICAO p){
	int type=0;
	if(com_monstros(e,e.jog)){
		type=10;
	}else if(com_droppedItem(e.droppedItems,e.jog)){
		type=80;
	}else if(com_chest(e,e.jog)){
		type=90;
	}
	return 7-3*(p.y+1)+p.x+1+type;
}
void imprime_texto(int x, int y, char *text, int fontSize){
	int i=0;
	int lineNumber=0;
	printf("<text x=%d y=%d style=\"font-size:%dpx\";>\n",x,y,fontSize);
	while(text[i]){
		char line[50];
		int lineI=0;
		while(text[i] && text[i]!='\n'){
			line[lineI++]=text[i++];
		}
		line[lineI]='\0';
		printf("\t<tspan x=%d y=%d >%s</tspan>\n",x,y+((fontSize+1)*lineNumber),line);
		lineNumber++;
		if(text[i]=='\n'){i++;};
	}
	printf("</text>\n");
}
void imprime_move_frame(POSICAO p, int moldura){
	char *mold[]=PLAY_FRAMES;
	IMAGEM_FORMATED(p.x,p.y,TAM,TAM,mold[moldura]);
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
	if(com_saida(e,e.jog) && !com_monstros(e,p)){
		new_action=5;
	}else{
		new_action=getDirection(e,p);
	}
	if ((!outOfBounds(e.jog) && !com_pedras(e,e.jog)) && (p.x!=p.y || com_droppedItem(e.droppedItems,e.jog))){
		int mold;
		mold = new_action > 10 ? 1 : 0;
		mold = new_action > 80 ? 3 : mold;
		mold = new_action > 90 ? 4 : mold;
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
void imprime_all_ranged_attacks(ESTADO e){
	POSICAO p;
	for(p.x=-2;p.x<3;p.x++){
		for(p.y=-2;p.y<3;p.y++){
			if(p.y==(abs(p.x)-2) || p.y==((-1*abs(p.x))+2)){
				imprime_ranged_attack(e,p);
			}
		}
	}
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
void imprime_all_moves(ESTADO e){
	POSICAO p;
	for(p.x=-1;p.x<=1;p.x++){
		for(p.y=-1;p.y<=1;p.y++){
			if ((p.x == 0 || p.y == 0)){
				imprime_move(e,p);
			}
		}
	}
	if(e.classe==2 || e.classe==3){
		imprime_all_ranged_attacks(e);
	}
	if(CAN_USE_LESSER_TELEPORT){
		imprime_lesser_teleport(e);
	}
}
void imprime_jogador (ESTADO e){
	char *dir[] = {"Jogador_Viking_Right.png","Jogador_Viking_Left.png"};
	IMAGEM(TAM*(e.jog.x+1),TAM*(e.jog.y+1),TAM,TAM,dir[(int) e.direction]);
	if(!e.isDeletingItems && !e.isInIngameHelp){
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
			IMAGEM_FORMATED(droppedItems[i].pos.x,droppedItems[i].pos.y,TAM,TAM,itemlist[droppedItems[i].item]);
		}
	}
}
void imprime_chests(CHEST chests[],int num_chests){
	int i;
	for (i=0;i<num_chests;i++){
		IMAGEM_FORMATED(chests[i].pos.x,chests[i].pos.y,TAM,TAM,"Chest.png");
	}
}
void imprime_monstros (POSICAO jog, MSTR monstros[],int num_monstros){
	int i;
	srand(time(NULL));
	char *mstrImgs[]={  "Monstro_Lobo_Lateral_1.png"  ,"Monstro_Lobo_Lateral_2.png",
						"Monstro_Bat_Lateral_1.png"   ,"Monstro_Bat_Lateral_2.png",
						"Monstro_Ogre_Lateral_1.png"  ,"Monstro_Ogre_Lateral_2.png",
						"Monstro_Archer_Lateral_1.png","Monstro_Archer_Lateral_2.png"};

	for(i=0;i<num_monstros;i++){
		int side = jog.x > monstros[i].x ? 0 : 1;
		int type = monstros[i].monType;
		IMAGEM_FORMATED(monstros[i].x,monstros[i].y,TAM,TAM,mstrImgs[(type*2)+side]);
	}
}
void imprime_pedras (POSICAO pedras[]){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		IMAGEM_FORMATED(pedras[i].x,pedras[i].y,TAM,TAM,"Tile_Obstacle.png");
	}
}
void imprime_saida (POSICAO p){
	IMAGEM_FORMATED(p.x,p.y,TAM,TAM,"Tile_Exit.png");
}
void imprime_casa (POSICAO p){
	char *tiles[]={"Tile1.png","Tile2.png","Tile3.png","Tile4.png"};
	int r = rand() % 4;
	IMAGEM_FORMATED(p.x,p.y,TAM,TAM,tiles[r]);
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
		sprintf(query,"4%d",i);
		ABRIR_LINK(name,query);
		IMAGEM(X,Y,TAM,TAM,itemlist[item]);
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
	char *trashCan[] = {"button_trashCan_closed.png","button_trashCan_opened.png"};
	ABRIR_LINK(name,"80");
	IMAGEM(745,260,50,50,trashCan[mode]);
	FECHAR_LINK;
	IMAGEM(620,210,50,50,"goldcoins.png");
	imprime_gold(660,225,bag.gold);
}
void imprime_feedback(int feedback){
	IMAGEM(595,400,200,150,"ScreenFeedback.png");
	char *feedbackMessages[] = FEEDBACK_MSGS;
	imprime_texto(600, 480, feedbackMessages[feedback],17);
}
void imprime_ingameHelp(ESTADO e){
	imprime_helpButton(e.name);
	if(e.isInIngameHelp){
		imprime_helpEnemies(e.name, e.monstros, e.num_monstros);
		imprime_helpInvetory(e.name, e.bag);
		if(ACT_HELP_ITEM){
			imprime_itemDescription(e.bag.inv[e.action-40]);
		}
		if(ACT_HELP_SWORD){
			imprime_itemDescription(e.bag.weapon);
		}
		if(ACT_HELP_ARMOUR){
			imprime_itemDescription(e.bag.armour);
		}
		if(ACT_HELP_MSTR){
			POSICAO pos = {(e.action / 100)-100 , (e.action % 100)};
			imprime_monsterDescription(e.monstros[getMonstro(e,pos)]);
			imprime_monsterAttackArea(e,e.monstros[getMonstro(e,pos)]);
		}
	}
}
void imprimePlaying(ESTADO e){
	ABRIR_SVG;

	srand(e.pedras[0].x);
	imprime_background(e.classe);
	imprime_chao();
	imprime_saida(e.saida);
	imprime_pedras(e.pedras);
	imprime_droppedItems(e.droppedItems);
	imprime_chests(e.chests,e.num_chests);
	if(e.isInBossBattle){
		//imprime_boss(e);
	}else{
		imprime_monstros(e.jog,e.monstros,e.num_monstros);
	}
	imprime_hpBar(e.hp);
	imprime_mpBar(e.mp,e.classe);
	imprime_inventory(e.isDeletingItems,e.name,e.bag);
	imprime_jogador(e);
	imprime_feedback(e.feedback);
	imprime_ingameHelp(e);
	if(e.hp<1){
		imprime_gameOverScreen(e.name);
	}

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
	printf("<p>isBeingUsed:%d  type:%d  lastPickedTarget:%d  isBeingCast:%d | isInIngameHelp:%d</p>\n",
			e.complexItem.isBeingUsed,
			e.complexItem.type,
			e.complexItem.lastPickedTarget,
			e.complexItem.isBeingCast,
			e.isInIngameHelp);
	int x;
	printf("<p>");
	for(x=0;x<e.num_monstros;x++){
		printf("| x:%d y:%d hp:%d |", e.monstros[x].x,e.monstros[x].y,e.monstros[x].hp);
	}
	printf("</p>");
	#endif
}
