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
	printf("<image x=%d y=%d width=%d height=%d xlink:href=\"http://127.0.0.1/border.png\"/>\n",
		TAM*(p.x+1),
		TAM*(p.y+1),
		TAM,
		TAM);
}
/**
\brief Cria um movimento para as coordenadas dadas
@param e Estado do jogo
@param p Posição onde criar o movimento
*/
void criar_movimento(ESTADO e, POSICAO p){
	ESTADO novo;
	novo = e;
	p.x += e.jog.x;
	p.y += e.jog.y;
	if (!outOfBounds(p) && !pos_ocupada(e,p) ){	
		novo.jog.x = p.x;
		novo.jog.y = p.y;
		char str[MAX_BUFFER+33]="http://localhost/cgi-bin/roguel?";
		strcat(str,estado2str(novo));
		ABRIR_LINK(str);
		imprime_movimento(p);
		FECHAR_LINK;
		/*printf("http://localhost/cgi-bin/exemplo?%s",
				estado2str(novo));
		*/
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
			if (p.x != 0 && p.y != 0){
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
	printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/Viking.png\"/>\n",
			TAM*(e.jog.x+1),
			TAM*(e.jog.y+1),
			TAM,
			TAM);
	imprime_jogadas(e);
}
/**
\brief Imprime os monstros
@param e Estado do jogo
*/
void imprime_monstros (ESTADO e){
	int i;
	for(i=0;i<MAX_MONSTROS;i++){
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/dragao.png\"/>\n",
				TAM*(e.monstros[i].x+1),
				TAM*(e.monstros[i].y+1),
				TAM,
				TAM);
	}
}
/**
\brief Imprime as pedras
@param e Estado do jogo
*/
void imprime_pedras (ESTADO e){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/rock.png\"/>\n",
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
	printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/exit.png\"/>\n",
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
	printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/floor.png\"/>\n",
			TAM*(p.x+1),
			TAM*(p.y+1),
			TAM,
			TAM);
}
