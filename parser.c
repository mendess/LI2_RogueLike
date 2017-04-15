#include "parser.h"

/**
\brief Imprime o inicio do html
*/
void print_header (){
	printf ("Content-Type: text/html; charset=utf-8\n\n");
	printf ("<header><title> Rogue Like </title></header>\n");
	printf ("<body>\n");
	printf ("<svg width=800 height = 600>\n");
}
/**
\brief Imprime o fim do html
*/
void print_footer () {
	printf ("</svg>\n");
	printf("</body>\n");
}
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
	if(isMonster(e,p)){
		type=10;
	}
	return 7-3*(p.y+1)+p.x+1+type;
}
/**
\brief Imprime um movimento (link)
@param p Posição a verficar
*/
void imprime_jogada(ESTADO e, POSICAO p){
	if(isMonster(e,p)){
		printf("<image x=%d y=%d width=%d height=%d xlink:href=\"%sMoldura_Movimento.png\"/>\n",
				TAM*(p.x+1),
				TAM*(p.y+1),
				TAM,
				TAM,
				IMAGE_PATH);
	}else{
		printf("<image x=%d y=%d width=%d height=%d xlink:href=\"%sMoldura_Movimento.png\"/>\n",
				TAM*(p.x+1),
				TAM*(p.y+1),
				TAM,
				TAM,
				IMAGE_PATH);
	}
}
/**
\brief Cria um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void criar_jogada(ESTADO e, POSICAO p){
	if(e.saida.x==(p.x+e.jog.x) && e.saida.y==(p.y+e.jog.y)){
		e.action=5;
	}else{
		e.action=(char) getDirection(e,p);
	}
	p.x += e.jog.x;
	p.y += e.jog.y;
	if (!outOfBounds(p) && !com_pedras(e,p)){
		char str[34];
		sprintf(str,"http://localhost/cgi-bin/roguel?%d",e.action);
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
	if(e.direction==0){
		printf("<image x=%d y=%d width= %d height= %d href=\"%sIcon_Viking_Right.png\"/>\n",
				TAM*(e.jog.x+1),
				TAM*(e.jog.y+1),
				TAM,
				TAM,
				IMAGE_PATH);
	}else{
		printf("<image x=%d y=%d width= %d height= %d href=\"%sIcon_Viking_Left.png\"/>\n",
				TAM*(e.jog.x+1),
				TAM*(e.jog.y+1),
				TAM,
				TAM,
				IMAGE_PATH);
	}
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
void imprime_casa (int r,POSICAO p){
	char *tiles[]={"Tile1.png","Tile2.png","Tile3.png","Tile4.png"};
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

void imprime(ESTADO e){
	print_header();
	imprime_background();

	int x,y;
	POSICAO p;
	srand(e.pedras[0].x);
	for(y = 0; y < SIZE; y++){
		for(x = 0; x < SIZE; x++){
			int r = rand() % 4;
			p.x= x;
			p.y= y;
			imprime_casa(r,p);
		}
	}

	imprime_saida(e.saida);
	imprime_pedras(e);
	imprime_monstros(e);
	imprime_jogador(e);

	print_footer();
}
