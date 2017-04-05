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
\brief Verifica se um par de coordenadas esta fora dos limites do mapa
@param p Posição a verficar
*/
int outOfBounds(POSICAO p){
	if (p.x<0 || p.x>= SIZE || p.y<0 || p.y>=SIZE){
		return 1;
	}
	return 0;
}
/**
\brief Imprime um movimento (link)
@param p Posição a verficar
*/
void imprime_movimento (POSICAO p){
	printf("<image x=%d y=%d width=%d height=%d xlink:href=\"http://127.0.0.1/Moldura_Movimento.png\"/>\n",
		TAM*(p.x+1),
		TAM*(p.y+1),
		TAM,
		TAM);
}
/**
\brief Retorna a direção em que o jogador vai andar
1- SW	x==-1 ; y==1
2- S	x==0  ; y==1
3- SE	x==1  ; y==1
4- W	x==-1 ; y==0
5- --	(saida, esta função nunca retorna este valor)
6- E	x==1  ; y==0
7- NW	x==-1 ; y==-1
8- N	x==0  ; y==-1
9- NE	x==1  ; y==-1
@param x Quanto no eixo dos x o jogador vai andar
@param y Quanto no eixo dos x o jogador vai andar
*/
int getDirection(int x, int y){
	if(x==-1 && y==1){
		return 1;
	}
	if(x==0  && y==1){
		return 2;
	}
	if(x==1  && y==1){
		return 3;
	}
	if(x==-1 && y==0){
		return 4;
	}
	if(x==1  && y==0){
		return 6;
	}
	if(x==-1 && y==-1){
		return 7;
	}
	if(x==0 && y==-1){
		return 8;
	}
	if(x==1 && y==-1){
		return 9;
	}
	return -1;
}
/**
\brief Cria um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void criar_movimento(ESTADO e, POSICAO p){
	if(e.saida.x==(p.x+e.jog.x) && e.saida.y==(p.y+e.jog.y)){
		e.action=5;
	}else{
		e.action=(char) getDirection(p.x,p.y);
	}
	p.x += e.jog.x;
	p.y += e.jog.y;
	if (!outOfBounds(p) && !pos_ocupada(e,p) ){	
		char str[MAX_BUFFER+33]="http://localhost/cgi-bin/roguel?";
		strcat(str,estado2str(e));
		ABRIR_LINK(str);
		imprime_movimento(p);
		FECHAR_LINK;
	}
}
/**
\brief Imprime as jogadas possiveis
@param e Estado do jogo
*/
void imprime_jogadas(ESTADO e){
	POSICAO p;
	for(p.x=-1;p.x<=1;p.x++){
		for(p.y=-1;p.y<=1;p.y++){
			if (p.x != 0 || p.y != 0){
				criar_movimento(e,p);
			}
		}
	}
}
/**
\brief Imprime o jogador
@param e Estado do jogo
*/
void imprime_jogador (ESTADO e){
	if(e.direction==0){
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/Icon_Viking_Right.png\"/>\n",
				TAM*(e.jog.x+1),
				TAM*(e.jog.y+1),
				TAM,
				TAM);
	}else{
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/Icon_Viking_Left.png\"/>\n",
				TAM*(e.jog.x+1),
				TAM*(e.jog.y+1),
				TAM,
				TAM);
	}
			
	imprime_jogadas(e);
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
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/%s\"/>\n",
				TAM*(e.monstros[i].x+1),
				TAM*(e.monstros[i].y+1),
				TAM,
				TAM,
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
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/Obstacle1.png\"/>\n",
			TAM*(e.pedras[i].x+1),
			TAM*(e.pedras[i].y+1),
			TAM,
			TAM);
	}
}
/**
\brief Imprime a saida
@param p Posição da saida
*/
void imprime_saida (POSICAO p){
	printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/Exit_Tile.png\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM);
}
/**
\brief Imprime uma casa
@param p Posição a imprimir
*/
void imprime_casa (POSICAO p){
	printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/Tile1.png\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM);
}
/**
\brief Imprime a imagem de fundo
*/
void imprime_background (){
	printf("<image x=0 y=0 width=800 height=600 href=\"http://127.0.0.1/Ingame_Viking.png\"/>\n");
}