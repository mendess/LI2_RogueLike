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
	char *mold[]={"Movimento","Ataque"};
	int type=0;
	if(com_monstros(e,p)){
		type=1;
	}
	printf("<image x=%d y=%d width=%d height=%d xlink:href=\"%sMoldura_%s.png\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM,
			IMAGE_PATH,
			mold[type]);
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
		char str[34];
		sprintf(str,"http://localhost/cgi-bin/roguel?%d",new_action);
		ABRIR_LINK(str);
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
	char *dir[] = {"Right","Left"};
	printf("<image x=%d y=%d width= %d height= %d href=\"%sIcon_Viking_%s.png\"/>\n",
			TAM*(e.jog.x+1),
			TAM*(e.jog.y+1),
			TAM,
			TAM,
			IMAGE_PATH,
			dir[(int) e.direction]);
	imprime_jogadaS(e);
}
/**
\brief Imprime os monstros
@param e Estado do jogo
*/
void imprime_monstros (ESTADO e){
	int i;
	srand(time(NULL));
	char *wolfs[]={"Icon_Lobo_Lateral_3.png","Icon_Lobo_Lateral_4.png"};
	for(i=0;i<MAX_MONSTROS;i++){
		int r = rand() % 2;
		printf("<image x=%d y=%d width= %d height= %d href=\"%s%s\"/>\n",
				TAM*(e.monstros[i].x+1),
				TAM*(e.monstros[i].y+1),
				TAM,
				TAM,
				IMAGE_PATH,
				wolfs[r]);
	}
}
/**
\brief Imprime as pedras
@param e Estado do jogo
*/
void imprime_pedras (ESTADO e){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		printf("<image x=%d y=%d width= %d height= %d href=\"%sObstacle1.png\"/>\n",
				TAM*(e.pedras[i].x+1),
				TAM*(e.pedras[i].y+1),
				TAM,
				TAM,
				IMAGE_PATH);
	}
}
/**
\brief Imprime a saida
@param p Posição da saida
*/
void imprime_saida (POSICAO p){
	printf("<image x=%d y=%d width=%d height=%d href=\"%sExit_Tile.png\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM,
			IMAGE_PATH);
}
/**
\brief Imprime uma casa
@param p Posição a imprimir
*/
void imprime_casa (POSICAO p){
	char *tiles[]={"Tile1.png","Tile2.png","Tile3.png","Tile4.png"};
	int r = rand() % 4;
	printf("<image x=%d y=%d width=%d height=%d href=\"%s%s\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM,
			IMAGE_PATH,
			tiles[r]);
}
/**
\brief Imprime a imagem de fundo
*/
void imprime_background (){
	printf("<image x=0 y=0 width=800 height=600 href=\"%sIngame_Viking.png\"/>\n",IMAGE_PATH);
}
/**
\brief Imprime a barra que indica a vida do jogodor
@param hp Vida
*/
void imprime_hpBar(int hp){
	printf("<image x=600 y=100 width=%f height=10 preserveAspectRatio=none href=\"%sHealthBar.png\"/>\n",(hp)*1.5,IMAGE_PATH);
}
/**
\brief Imprime a barra que indica a mana do jogodor
@param mp Mana
*/
void imprime_mpBar(int mp){
	printf("<image x=600 y=115 width=%f height=10 preserveAspectRatio=none href=\"%sManaBar.png\"/>\n",(mp)*1.5,IMAGE_PATH);
}
void imprime_gameOverScreen(){
	printf("<image x=0 y=0 width=800 height=600 href=\"%sGameOverScreen.png\"/>\n",IMAGE_PATH);
	ABRIR_LINK("http://localhost/cgi-bin/roguel?0");
	printf("<rect x=300 y=350 width=200 height=70 style=opacity:0\n");
	FECHAR_LINK;
}
void imprimePlaying(ESTADO e){
	imprime_background();

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
	imprime_mpBar(e.mp);
	if(e.hp>1){
		imprime_jogador(e);
	}else{
		imprime_gameOverScreen();
	}
	#ifdef DEBUG
	printf("<p>hp:%d  mp:%d  world_lvl:%d  score:%d  turn:%d  LootTable[%d,%d,%d,%d]</p>",
			e.hp,
			e.mp-1,
			e.world_lvl,
			e.score,
			e.turn,
			e.lootTable[0],
			e.lootTable[1],
			e.lootTable[2],
			e.lootTable[3]);
	#endif
}