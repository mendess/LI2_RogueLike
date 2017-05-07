#define DEBUG

#include "html4Playing.h"

/**
\brief Retorna a direção em que o jogador vai andar
1- SW	x==-1 ; y==1
2- S	x==0  ; y==1
3- SE	x==1  ; y==1
4- W	x==-1 ; y==0
5- --	(saida, esta função nunca deve retornar este valor)
6- E	x==1  ; y==0
7- NW	x==-1 ; y==-1
8- N	x==0  ; y==-1
9- NE	x==1  ; y==-1
@param x Quanto no eixo dos x o jogador vai andar
@param y Quanto no eixo dos x o jogador vai andar
*/
int getDirection(ESTADO e,POSICAO p){
	int type=0;
	POSICAO tmp;
	tmp.x = p.x + e.jog.x;
	tmp.y = p.y + e.jog.y;
	if(com_monstros(e,tmp)){
		type=10;
	}
	return 7-3*(p.y+1)+p.x+1+type;
}
/**
\brief Imprime um movimento (link)
@param p Posição a verficar
*/
void imprime_jogada(ESTADO e, POSICAO p){
	char *mold[]={"Moldura_Movimento.png","Moldura_Ataque.png"};
	int type=0;
	if(com_monstros(e,p)){
		type=1;
	}
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,mold[type]);

}
/**
\brief Cria um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void criar_jogada(ESTADO e, POSICAO p){
	int new_action;
	if(e.saida.x==(p.x+e.jog.x) && e.saida.y==(p.y+e.jog.y)){
		new_action=5;
	}else{
		new_action=(char) getDirection(e,p);
	}
	p.x += e.jog.x;
	p.y += e.jog.y;
	if (!outOfBounds(p) && !com_pedras(e,p)){
		char query[4];
		sprintf(query,"%d",new_action);
		ABRIR_LINK(query);
		imprime_jogada(e,p);
		FECHAR_LINK;
	}
}
/**
\brief Imprime as jogadas possiveis
@param e Estado do jogo
*/
void imprime_jogadaS(ESTADO e){
	POSICAO p;
	p.x=0;p.y=1;
	criar_jogada(e,p);
	p.x=1;p.y=0;
	criar_jogada(e,p);
	p.x=-1;p.y=0;
	criar_jogada(e,p);
	p.x=0;p.y=-1;
	criar_jogada(e,p);
	/*for(p.x=-1;p.x<=1;p.x++){
		for(p.y=-1;p.y<=1;p.y++){
			if (p.x != 0 || p.y != 0){
				criar_jogada(e,p);
			}
		}
	}*/
}
/**
\brief Imprime o jogador
@param e Estado do jogo
*/
void imprime_jogador (ESTADO e){
	char *dir[] = {"Jogador_Viking_Right.png","Jogador_Viking_Left.png"};
	IMAGEM(TAM*(e.jog.x+1),TAM*(e.jog.y+1),TAM,TAM,dir[(int) e.direction]);
	imprime_jogadaS(e);
}
/**
\brief Imprime os monstros
@param e Estado do jogo
*/
void imprime_monstros (ESTADO e){
	int i;
	srand(time(NULL));
	char *wolfs[]={"Monstro_Lobo_Lateral_1.png","Monstro_Lobo_Lateral_2.png"};
	for(i=0;i<MAX_MONSTROS;i++){
		int r = rand() % 2;
		IMAGEM(TAM*(e.monstros[i].x+1),TAM*(e.monstros[i].y+1),TAM,TAM,wolfs[r]);
	}
}
/**
\brief Imprime as pedras
@param e Estado do jogo
*/
void imprime_pedras (ESTADO e){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		IMAGEM(TAM*(e.pedras[i].x+1),TAM*(e.pedras[i].y+1),TAM,TAM,"Tile_Obstacle.png");
	}
}
/**
\brief Imprime a saida
@param p Posição da saida
*/
void imprime_saida (POSICAO p){
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,"Exit_Tile.png");
}
/**
\brief Imprime uma casa
@param p Posição a imprimir
*/
void imprime_casa (POSICAO p){
	char *tiles[]={"Tile1.png","Tile2.png","Tile3.png","Tile4.png"};
	int r = rand() % 4;
	IMAGEM(TAM*(p.x+1),TAM*(p.y+1),TAM,TAM,tiles[r]);
}
/**
\brief Imprime a imagem de fundo
*/
void imprime_background (char classe){
	char *background[] = {"Ingame_Viking.png","Ingame_Archer.png","Ingame_Mage.png"};
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,background[(int) classe]);
}
/**
\brief Imprime a barra que indica a vida do jogodor
@param hp Vida
*/
void imprime_hpBar(int hp){
	IMAGEM(600,10,200,50,"BarHealthIcon.png");
	IMAGEM(641,10,(int) ((hp)*1.5),50,"BarHealthBar.png");
}
/**
\brief Imprime a barra que indica a mana do jogodor
@param mp Mana
*/
void imprime_mpBar(int mp,char classe){
	char *icons[] = {"BarEnergyIcon.png","BarManaIcon.png"};
	char *bars[] = {"BarEnergyBar.png","BarManaBar.png"};
	IMAGEM(600,55,			   200,50,(classe <3) ? icons[0] : icons[1]);
	IMAGEM(641,55,(int) ((mp)*1.5),50,(classe <3) ? bars[0]  : bars[1]);
}
void imprime_gameOverScreen(){
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenGameOver.png");
	ABRIR_LINK("0");
	printf("<rect x=300 y=350 width=200 height=70 style=opacity:0;>\n");
	FECHAR_LINK;
}
void imprime_inv_slot(char item,int i){
	char *itemlist[] = ITEM_LIST;
	if(item!=0){
		int X = 600+(TAM*(i/2));
		int Y = 111+(50*!(i%2));
		IMAGEM(X,Y,TAM,TAM,itemlist[(int) item]);
		char query[4];
		sprintf(query,"2%d",i);
		ABRIR_LINK(query);
		printf("<rect x=%d y=%d width=50 height=50 style=opacity:0;>\n",X,Y);
		FECHAR_LINK;
	}
}
void imprime_equipment(INVT bag){
	char *itemlist[] = ITEM_LIST;
	IMAGEM(700,260,TAM,TAM,itemlist[(int) bag.weapon]);
	IMAGEM(700,310,TAM,TAM,itemlist[(int) bag.armour]);
}
void imprime_inventory(INVT bag){
	IMAGEM(620,110,150,100,"Inv_bag.png");
	int i;
	for (i = 0; i < INVT_SIZE; ++i){
		imprime_inv_slot(bag.inv[i],i);
	}
	IMAGEM(700,260,50,100,"Inv_equipment.png");
	imprime_equipment(bag);
}
void imprimePlaying(ESTADO e){
	imprime_background(e.classe);

	int x,y;
	POSICAO p;
	srand(e.pedras[0].x);
	for(y = 0; y < SIZE; y++){
		for(x = 0; x < SIZE; x++){
			p.x= x;
			p.y= y;
			imprime_casa(p);
		}
	}

	imprime_saida(e.saida);
	imprime_pedras(e);
	imprime_monstros(e);
	imprime_hpBar(e.hp);
	imprime_mpBar(e.mp,e.classe);
	imprime_inventory(e.bag);
	if(e.hp>1){
		imprime_jogador(e);
	}else{
		imprime_gameOverScreen();
	}
	#ifdef DEBUG
	printf("<p>hp:%d  mp:%d  world_lvl:%d  score:%d  turn:%d  LootTable[%d,%d,%d,%d]</p>",
			e.hp,
			e.mp,
			e.world_lvl,
			e.score,
			e.turn,
			e.lootTable[0],
			e.lootTable[1],
			e.lootTable[2],
			e.lootTable[3]);
	#endif
}