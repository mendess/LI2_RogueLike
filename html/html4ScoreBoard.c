#include "html4ScoreBoard.h"

void imprime_score(int score, int index){
	int digitPos=0;
	while(score){
		int digit = score % 10;
		char filepath[15];
		score = score / 10;
		sprintf(filepath,"Number%d.png",digit);
		IMAGEM(472-(TAM*digitPos),90+(TAM*index),TAM,TAM,filepath);
		digitPos++;
	}
}
void imprimeScoreBoard(char *name){
	ABRIR_SVG;
	
	int scoreBoard[SB_SIZE];
	int i;
	int num_scores = importScoreBoard(scoreBoard);
	IMAGEM(0,0,SVG_WIDTH,SVG_HEIGHT,"ScreenScoreBoard.png");
	for (i = 0; i < num_scores; ++i){
		imprime_score(scoreBoard[i],i);
	}
	ABRIR_LINK(name,"0");/* back */
	printf("<rect x=0 y=540 width=140 height=60 style=opacity:0;></rect>\n");
	FECHAR_LINK;

	FECHAR_SVG;
}