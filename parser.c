#include <stdio.h>
#include "parser.h"
#include "jogo.h"
#include "browser.h"

void print_header (){
	printf ("Content-Type: text/html; charset=utf-81\n\n");
	printf ("<header><title> Rogue Like </title></header>\n");
	printf ("<body>\n");
	printf ("<svg width=800 height = 600>\n");
}

void print_footer () {
	printf ("</svg>\n");
	printf("</body>\n");
}

/* Verifica se um par de coordenadas esta fora dos limites do mapa */
int outOfBounds(POSICAO p){
	if (p.x<0 || p.x> SIZE || p.y<0 || p.y>SIZE){
		return 1;
	}
	return 0;
}

/* Imprime um movimento */
void imprime_movimento (POSICAO p){
	printf("<image x=%d y=%d width= %d height= %d xlink:href=\"http://127.0.0.1/cgi-bin/border.png\">\n",
		TAM*p.x,
		TAM*p.y,
		TAM,
		TAM);
}

/* Imprime todos os movimentos possiveis */
void criar_movimento(ESTADO e, POSICAO p){
	ESTADO novo;
	novo = e;
	p.x += e.jog.x;
	p.y += e.jog.y;
	if (!outOfBounds(p) && !pos_ocupada(e,p) ){	
		novo.jog.x = x;
		novo.jog.y = y;
		char str[MAX_BUFFER+33]="http://localhost/cgi-bin/exemplo?";
		strcat(str,estado2str(novo));)
		ABRIR_LINK(str);
		FECHAR_LINK;
		/*printf("http://localhost/cgi-bin/exemplo?%s",
				estado2str(novo));
		*/
		imprime_mov(p);
	}
}
/* Imprime */
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

void imprime_jogador (ESTADO e){
	printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/cgi-bin/Viking.png\">\n",
			TAM*(e.jog.x),
			TAM*(e.jog.y),
			TAM,
			TAM);
	imprime_movimentos(e);
}

void imprime_monstros (ESTADO e){
	int i;
	for(i=0;i<MAX_MONSTROS;i++){
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/cgi-bin/dragao.png\">\n",
				TAM*(e.monstros[i].x),
				TAM*(e.monstros[i].y),
				TAM,
				TAM);
	}
}

void imprime_pedras (ESTADO e){
	int i;
	for (i=0;i<MAX_PEDRAS;i++){
		printf("<image x=%d y=%d width= %d height= %d href=\"http://127.0.0.1/cgi-bin/rock.png\">\n",
			TAM*(e.pedras[i].x),
			TAM*(e.pedras[i].y),
			TAM,
			TAM);
	}
}

void imprime_casa (POSICAO p){
	printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/cgi-bin/floor.png\">\n", TAM*x, TAM*y, TAM, TAM); 
/*	if (p.x == 0 || p.x == SIZE || p.y == 0 || p.y == SIZE){
		printf("<image x=%d y=%d width=%d height=%d href=\"http://127.0.0.1/cgi-bin/rock.png\">\n", TAM*x, TAM*y, TAM, TAM);
	}
*/
}
